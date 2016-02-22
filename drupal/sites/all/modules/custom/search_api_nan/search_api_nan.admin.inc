<?php

/**
 * @file
 *
 * Administrative functions for Search API NAN .
 */


//Todo: add config link on module page


function search_api_nan_form($form, &$form_state, $naan = NULL) {
  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => isset($naan->name) ? $naan->name : '',
    '#description' => t('Naan Name.'),
    '#required' => TRUE,
    '#weight' => -50,
  );
  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#default_value' => isset($naan->description) ? $naan->description : '',
    '#description' => t('Description for admin use only.'),
    '#required' => FALSE,
  );
  $form['urlpath'] = array(
    '#title' => t('URL Path'),
    '#type' => 'textfield',
    '#default_value' => isset($naan->urlpath) ? $naan->urlpath : '',
    '#description' => t('URL Path to the page without leading slash.'),
    '#required' => TRUE,
  );

  $form['frequency'] = array(
    '#title' => t('Frequency'),
    '#type' => 'textfield',
    '#default_value' => isset($naan->frequency) ? $naan->frequency : '0',
    '#description' => t('The time between indexing in seconds.'),
    '#required' => TRUE,
  );
  $form['auto_populate_body'] = array(
    '#title' => t('Auto Populate Body (Y/N)'),
    '#type' => 'radios',
    '#options' => array(1 => t('Yes'), 0 => t('No')),
    '#default_value' => isset($naan->auto_populate_body) ? $naan->auto_populate_body : 'N',
    '#description' => t('Automatically load the contents of the path into the body field for indexing.'),
    '#required' => TRUE,
  );
  $form['body'] = array(
    '#title' => t('Body'),
    '#type' => 'textarea',
    '#wysiwyg' => false,
//    '#type' => 'textfield',
    '#default_value' => isset($naan->body) ? $naan->body : '',
    '#description' => t('Content area of the page.  This is not usually required.'),
    '#required' => FALSE,
  );

  // Adds the fieldable fields to the form.
  field_attach_form('naan', $naan, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($naan->id) ? t('Update Naan') : t('Save Naan'),
    ),
  );

  return $form;
}

/**
 * Builds the administration form for Search API NAN search.
 */
function search_api_nan_nan_settings_form($form, &$form_state, $nan = NULL) {
  // We will have many fields with the same name, so we need to be able to
  // access the form hierarchically.
  $form['#tree'] = TRUE;

//    $environments = apachesolr_load_all_environments();
//    $env_options = array();
//    foreach ($environments as $machine_name => $env) {
//        $env_options[$machine_name] = $env['name'];
//    }

  $conditions = array('class' => 'search_api_solr_service', 'enabled' => TRUE);
  $first_server = "";
  $env_options = array();
  try {
    $servers = search_api_server_load_multiple(FALSE, $conditions);
    $first_server = key($servers);
    foreach ($servers as $server) {
      $env_options[$server->name] = $server->name;  //TODO: do I need to use $env_options?
//      if ($first_server == "") {
//        $first_server = $server->name;
//      }
    }
  }
  catch (SearchApiException $e) {
    watchdog_exception('search_api_nan', $e, '%type while accessing Solr server @server: !message in %function (line %line of %file).',
      array('@server' => $server->name));
  }


  $form['environment'] = array(
    '#type' => 'select',
    '#options' => $env_options,
    '#description' => t('Choose the solr server with which to index the content.'),
//    '#default_value' => apachesolr_default_environment(),
    '#default_value' => $first_server,
    '#required' => TRUE,
  );

  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Define the paths you would like indexed along with names and descriptions for them.'),
  );

  if (empty($form_state['items'])) {
    $results = db_select('search_api_nan', 'p')
      ->fields('p')
      ->execute();
    $items = array();
    while ($item = $results->fetchAssoc()) {
      $items[] = $item;
    }
    $form_state['items'] = $items;
  }
  if (!empty($form_state['all_removed']) || empty($form_state['items'])) {
    $form_state['items'] = NULL;//array(0 => array());
  }

  if (!empty($form_state['items'])) {
    // Build a fieldset for each item in the items array.
    $c = 1;
    foreach ($form_state['items'] as $i => $data) {

      $form['item'][$i] = array(
        '#type' => 'fieldset',
        '#title' => t('Item #@num', array('@num' => $c)),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
      );

      $form['item'][$i]['title'] = array(
        '#title' => t('Title'),
        '#type' => 'textfield',
        '#default_value' => isset($data['title']) ? $data['title'] : '',
        '#description' => t('Title for administrative use only.'),
        '#required' => TRUE,
        '#weight' => -50,
      );
      $form['item'][$i]['description'] = array(
        '#title' => t('Description'),
        '#type' => 'textfield',
        '#default_value' => isset($data['description']) ? $data['description'] : '',
        '#description' => t('Description for admin use only.'),
        '#required' => FALSE,
      );
      $form['item'][$i]['urlpath'] = array(
        '#type' => 'textfield',
        '#title' => t('Path to Index'),
        '#description' => t('URL Path to the page without leading slash.'),
        '#required' => TRUE,
        '#default_value' => isset($data['urlpath']) ? $data['urlpath'] : '',
      );

      $form['item'][$i]['frequency'] = array(
        '#title' => t('Frequency'),
        '#type' => 'textfield',
        '#default_value' => isset($data['frequency']) ? $data['frequency'] : '0',
        '#description' => t('The time between indexing in seconds.'),
        '#required' => TRUE,
      );
      $form['item'][$i]['auto_populate_body'] = array(
        '#title' => t('Auto Populate Body (Y/N)'),
        '#type' => 'radios',
        '#options' => array(1 => t('Yes'), 0 => t('No')),
        '#default_value' => isset($data['auto_populate_body']) ? $data['auto_populate_body'] : 'N',
        '#description' => t('Automatically load the contents of the path into the body field for indexing.'),
        '#required' => TRUE,
      );
      $form['item'][$i]['body'] = array(
        '#title' => t('Body'),
        '#type' => 'textarea',
        '#wysiwyg' => false,
        '#default_value' => isset($data['body']) ? $data['body'] : '',
        '#description' => t('Content area of the page.  This is not usually required.'),
        '#required' => FALSE,
      );


//      $form['item'][$i]['title'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Indexed Title'),
//        '#description' => t('A title to show on the search results page. This can be the name of the page or something else but users will see this in search results and the text will be used to boost result order.'),
//        '#default_value' => !empty($data['title']) ? $data['title'] : '',
//      );
//      $form['item'][$i]['description'] = array(
//        '#type' => 'textarea',
//        '#title' => t('Page description'),
//        '#description' => t('The description will show in search results only. It can be used to improve search results for certain pages.'),
//        '#default_value' => !empty($data['description']) ? $data['description'] : '',
//      );
//      $form['item'][$i]['frequency'] = array(
//        '#type' => 'select',
//        '#title' => t('Time between indexes'),
//        '#options' => array(
//          3600 => 'hourly',
//          86400 => 'daily',
//          604800 => 'weekly',
//          2419200 => 'monthly',
//        ),
//        '#description' => t('The page will be reindexed at the set interval.'),
//        '#default_value' => isset($data['frequency']) ? $data['frequency'] : 86400,
//        '#required' => TRUE,
//      );



      $form['item'][$i]['delete'] = array(
        '#type' => 'submit',
        '#name' => $i,
        '#value' => 'Delete',
        '#submit' => array('search_api_nan_remove_item'),
        '#limit_validation_errors' => array(),
      );
      $c++;
    }
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  // Adds "Add another item" button
  $form['add_item'] = array(
    '#type' => 'submit',
    '#value' => t('Add another item'),
    '#submit' => array('search_api_nan_add_form_item'),
  );

  return $form;
}

/**
 * function apachesolr_nan_add_form_item().
 *
 * Handles adding an additional item to the admin form.
 *
 * @see search_api_nan_nan_settings_form().
 */
function search_api_nan_add_form_item($form, &$form_state) {
  // Add an element to the end of the array with the next available number.
  if (empty($form_state['items'])) {
    $form_state['items'][] = array();
  }
  else {
    $keys = array_keys($form_state['items']);
    $end = end($keys);
    $end++;
    $form_state['items'][$end] = array();
  }
  // Rebuild the form.
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Your changes will not be saved until you press the submit button.'), 'warning');
}

/**
 * function search_api_nan_remove_form_item().
 *
 * Handles item removal from the admin page.
 *
 * @see search_api_nan_nan_settings_form().
 */
function search_api_nan_remove_form_item($form, &$form_state) {
  // Remove the item from the array that corresponds to the pressed delete
  // button.
  $keys = array_keys($form_state['values']['item']);
  $first = reset($keys);
  unset($form_state['items'][$first]);
  $form_state['rebuild'] = TRUE;
  if (empty($form_state['items'])) {
    $form_state['all_removed'] = TRUE;
  }
  drupal_set_message(t('If you are making changes to existing data, your changes will not be saved until you press the submit button.'), 'warning');
}

/**
 * function search_api_nan_nan_settings_form_validate().
 *
 * Validation for the admin page.
 *
 * @see search_api_nan_nan_settings_form().
 * @see search_api_nan_nan_settings_form_submit().
 */
function search_api_nan_nan_settings_form_validate($form, &$form_state) {
  // Validate the paths.
  if (!empty($form_state['items'])) {
    foreach ($form_state['items'] as $i => $data) {
      $path = $form_state['values']['item'][$i]['path'];
      if (!drupal_valid_path($path)) {
        if (empty($form_state['all_removed']) && $path != '') {
          form_set_error("item][$i][path", t('The path is not valid or you do not have access to it.'));
        }
      }
    }
  }
}


/**
 * function search_api_nan_nan_settings_form_submit().
 *
 * Submit form for admin page.
 *
 * @see search_api_nan_nan_settings_form().
 * @see search_api_nan_nan_settings_form_validate().
 */
function search_api_nan_nan_settings_form_submit($form, &$form_state) {
  $current_nans = entity_load('search_api_nan',FALSE);

  $servers = search_api_server_load_multiple(FALSE, $conditions);
  $first_server = key($servers);

  $old_env = variable_get('search_api_nan_server', $first_server);
  if ($form_state['values']['environment'] != $old_env) {
    // We switched environments so clean everything out of the other one.
    if (!empty($current_nans)) {
      foreach ($current_nans as $nan) {
        //Todo: implement?
//        apachesolr_index_delete_entity_from_index($old_env, 'apachesolr_nan', $nan);
      }
    }
  }

  // Set the new environment.
  $env = $form_state['values']['environment'];
  variable_set('search_api_nan_server', $env);
  if (!empty($form_state['items'])) {
    foreach ($form_state['values']['item'] as $key => $item) {
      unset($form_state['values']['item'][$key]['delete']);
    }
    $items = array_values($form_state['values']['item']);
  }
  else {
    $items = array();
  }

  // Keep list of previous paths in the DB.
  $old_paths = array();
  foreach ($current_nans as $nan) {
    $old_paths[] = $nan['urlpath'];
  }

  // Save adds/changes into the database.
  $new_paths = array();
  $saved = FALSE;
  foreach ($items as $item) {

    $new_paths[] = $item['path'];
    search_api_nan_write_entity($item);
    $saved = TRUE;
  }
  if ($saved) {
    drupal_set_message(t('Your paths have been updated or added.'));
  }

  // Find any removed elements and delete them.
  $delete_paths = array_diff($old_paths, $new_paths);
  if (!empty($delete_paths)) {
      // Todo: Implement?
//    module_load_include('inc', 'apachesolr', 'apachesolr.index');
//    $deleted = array();
//    foreach ($delete_paths as $path) {

      if (search_api_nan_delete_entity($env, $path)) {
        watchdog('Search API NAN search', 'The Search API NAN path %path was deleted', array('%path' => $path));
      }
      else {
        drupal_set_message(t('There was a problem removing the page from the index.'), 'error');
        watchdog('Search API NAN search', 'The Search API NAN path %path could not be deleted', array('%path' => $path), WATCHDOG_ERROR);
      }
      $deleted[] = $path;
    }


  if ($deleted > 0) {
    drupal_set_message(t('The following paths were deleted:'));
    foreach ($deleted as $removed_path) {
      drupal_set_message($removed_path);
    }
  }
}


/**
 * function apachesor_nan_get_nan_by_path().
 *
 * EntityFieldQuery wrapper to get a single nan by path.
 *
 * @param $path
 * @return bool|mixed
 */
function search_api_nan_get_nan_by_path($path) {

  $query = new EntityFieldQuery();
  $entities = $query->entityCondition('entity_type', 'search_api_nan')
    ->propertyCondition('urlpath', $path)
    ->execute();

  if ($entities['search_api_nan']) {
    return reset(entity_load('search_api_nan', array_keys($entities['search_api_nan'])));
  }

  return FALSE;
}

/**
 * function search_api_nan_write_entity().
 *
 * Helper function to update/save data for Search_api NAN entities.
 *
 * @param $item - Array containing submitted values for NANs
 */
function search_api_nan_write_entity($item) {

  // Fetch existing record.
  $nan = search_api_nan_get_nan_by_path($item['urlpath']);

  if (!$nan) {
    // Else write a new record.
    $nan = entity_create('search_api_nan', array());
  }

  $nan->urlpath = $item['urlpath'];
  $nan->title = $item['title'];
  $nan->description = $item['description'];
  $nan->frequency = $item['frequency'];
  $nan->save();
}


/**
 * function search_api_nan_delete_entity().
 *
 * Helper function to delete a nan entity.
 *
 * @param $env
 * @param $delete_path
 * @return bool
 */
function search_api_nan_delete_entity($env, $delete_path) {

  if ($nan = search_api_nan_get_nan_by_path($delete_path)) {
    $nan->delete();
    apachesolr_index_delete_entity_from_index($env, 'search_api_nan', $nan->id);
    return TRUE;
  }

  return FALSE;
}


