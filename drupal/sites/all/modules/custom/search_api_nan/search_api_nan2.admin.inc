<?php

/**
 * @file
 *
 * Administrative functions for Search API NAN .
 */


/**
 * Builds the administration form for Search API NAN search.
 */
function search_api_nan_nan_settings_form($form, &$form_state) {
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
    $results = db_select('search_api_nan_index_paths', 'p')
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

      $form['item'][$i]['path'] = array(
        '#type' => 'textfield',
        '#title' => t('Path to Index'),
        '#description' => t('Enter a path to index.'),
        '#required' => TRUE,
        '#default_value' => !empty($data['path']) ? $data['path'] : '',
      );
      $form['item'][$i]['title'] = array(
        '#type' => 'textfield',
        '#title' => t('Indexed Title'),
        '#description' => t('A title to show on the search results page. This can be the name of the page or something else but users will see this in search results and the text will be used to boost result order.'),
        '#default_value' => !empty($data['title']) ? $data['title'] : '',
      );
      $form['item'][$i]['description'] = array(
        '#type' => 'textarea',
        '#title' => t('Page description'),
        '#description' => t('The description will show in search results only. It can be used to improve search results for certain pages.'),
        '#default_value' => !empty($data['description']) ? $data['description'] : '',
      );
      $form['item'][$i]['frequency'] = array(
        '#type' => 'select',
        '#title' => t('Time between indexes'),
        '#options' => array(
          3600 => 'hourly',
          86400 => 'daily',
          604800 => 'weekly',
          2419200 => 'monthly',
        ),
        '#description' => t('The page will be reindexed at the set interval.'),
        '#default_value' => isset($data['frequency']) ? $data['frequency'] : 86400,
        '#required' => TRUE,
      );
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
    '#submit' => array('search_api_nan_add_item'),
  );

  return $form;
}

/**
 * Handles adding an additional item to the admin form.
 *
 * @see search_api_nan_nan_settings_form().
 */
function search_api_nan_add_item($form, &$form_state) {
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
 * Handles item removal from the admin page.
 *
 * @see search_api_nan_nan_settings_form().
 */
function search_api_nan_remove_item($form, &$form_state) {
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
 * Submit form for admin page.
 *
 * @see search_api_nan_nan_settings_form().
 * @see search_api_nan_nan_settings_form_validate().
 */
function search_api_nan_nan_settings_form_submit($form, &$form_state) {

  $conditions = array('class' => 'search_api_solr_service', 'enabled' => TRUE);
  $servers = search_api_server_load_multiple(FALSE, $conditions);
  reset($servers);
  $server_name = key($servers);

  $old_env = variable_get('search_api_nan_nan_env', $server_name);
  if ($form_state['values']['environment'] != $old_env) {
    // We switched environments so clean everything out of the other one.
    $ids = db_select('search_api_nan_index_paths', 'p')
      ->fields('p', array('id'))
      ->execute()
      ->fetchCol();
    if (!empty($ids)) {
      foreach ($ids as $id) {
        //TODO: implement
//        apachesolr_index_delete_entity_from_index($old_env, 'node', $id);
      }
    }
  }
  // Set the new environment.
  $env = $form_state['values']['environment'];
  variable_set('search_api_nan_nan_env', $env);
  if (!empty($form_state['items'])) {
    foreach ($form_state['values']['item'] as $key => $item) {
      unset($form_state['values']['item'][$key]['delete']);
    }
    $items = array_values($form_state['values']['item']);
  }
  else {
    $items = array();
  }
  // Set the items into the database;
  $paths = db_select('search_api_nan_index_paths', 'p')->fields('p', array(
    'id',
    'path'
  ))->execute()->fetchAllKeyed();
  $new_paths = array();
  $saved = FALSE;
  foreach ($items as $item) {
    $new_paths[] = $item['path'];
    if ($key = array_search($item['path'], $paths)) {
      $record = $item + array('id' => $key);
      drupal_write_record('search_api_nan_index_paths', $record, array('id'));
      $saved = TRUE;
//      _write_to_index();
    }
    else {
      drupal_write_record('search_api_nan_index_paths', $item);
      $saved = TRUE;
    }
  }
  if ($saved) {
    drupal_set_message(t('Your paths have been updated or added.'));
  }
  // Find the removed elements and delete them.
  //TODO: implement

//  $delete = array_diff($paths, $new_paths);
//  $delete_keys = array_keys($delete);
//  if (!empty($delete_keys)) {
//    module_load_include('inc', 'apachesolr', 'apachesolr.index');
//    foreach ($delete_keys as $key) {
//      $id = (int) $key * -1;
//      if (apachesolr_index_delete_entity_from_index($env, 'node', $id)) {
//        watchdog('ApacheSolr NAN search', 'The apache solr non-node item %id was deleted', array('%id' => $id));
//      }
//      else {
//        drupal_set_message(t('There was a problem removing the page from the index.'), 'error');
//        watchdog('ApacheSolr NAN search', 'The apache solr non-node item %id could not be deleted', array('%id' => $id), WATCHDOG_ERROR);
//      }
//    }
//  }
//  if (!empty($delete_keys)) {
//    $deleted = db_delete('search_api_nan_index_paths')->condition('id', $delete_keys, 'IN')->execute();
//    if ($deleted > 0) {
//      drupal_set_message(t('The following paths were deleted:'));
//      foreach ($delete as $removed_path) {
//        drupal_set_message($removed_path);
//      }
//    }
//  }
//  }
}

/**
 * Form callback wrapper: create or edit a nan.
 *
 * @param $nan
 *   The nan object being edited by this form.
 *
 * @see nan_edit_form()
 */
function nan_form_wrapper($nan) {
  // Add the breadcrumb for the form's location.
  nan_set_breadcrumb();
  return drupal_get_form('nan_edit_form', $nan);
}


/**
 * Form callback wrapper: delete a nan.
 *
 * @param $nan
 *   The nan object being edited by this form.
 *
 * @see nan_edit_form()
 */
function nan_delete_form_wrapper($nan) {
  // Add the breadcrumb for the form's location.
  //nan_set_breadcrumb();
  return drupal_get_form('nan_delete_form', $nan);
}


/**
 * Form callback: create or edit a nan.
 *
 * @param $nan
 *   The nan object to edit or for a create form an empty nan object
 *     with only a nan type defined.
 */
function nan_edit_form($form, &$form_state, $nan) {
  // Add the default field elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('nan Name'),
    '#default_value' => isset($nan->name) ? $nan->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['data']['#tree'] = TRUE;
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting nan switch'),
    '#default_value' => isset($nan->data['sample_data']) ? $nan->data['sample_data'] : 1,
  );

  // Add the field related form elements.
  $form_state['nan'] = $nan;
  field_attach_form('nan', $nan, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save nan'),
    '#submit' => $submit + array('nan_edit_form_submit'),
  );

  if (!empty($nan->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete nan'),
      '#suffix' => l(t('Cancel'), 'admin/content/nans'),
      '#submit' => $submit + array('nan_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'nan_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the nan form
 */
function nan_edit_form_validate(&$form, &$form_state) {
  $nan = $form_state['nan'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('nan', $nan, $form, $form_state);
}


/**
 * Form API submit callback for the nan form.
 *
 * @todo remove hard-coded link
 */
function nan_edit_form_submit(&$form, &$form_state) {

  $nan = entity_ui_controller('nan')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the nan and go back to the list of nans

  // Add in created and changed times.
  if ($nan->is_new = isset($nan->is_new) ? $nan->is_new : 0){
    $nan->created = time();
  }

  $nan->changed = time();

  $nan->save();
  $form_state['redirect'] = 'admin/content/nans';
}

/**
 * Form API submit callback for the delete button.
 *
 * @todo Remove hard-coded path
 */
function nan_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/nans/nan/' . $form_state['nan']->nan_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a nan.
 *
 * @param $nan
 *   The nan to delete
 *
 * @see confirm_form()
 */
function nan_delete_form($form, &$form_state, $nan) {
  $form_state['nan'] = $nan;

  $form['#submit'][] = 'nan_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete nan %name?', array('%name' => $nan->name)),
    'admin/content/nans/nan',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for nan_delete_form
 */
function nan_delete_form_submit($form, &$form_state) {
  $nan = $form_state['nan'];

  nan_delete($nan);

  drupal_set_message(t('The nan %name has been deleted.', array('%name' => $nan->name)));
  watchdog('nan', 'Deleted nan %name.', array('%name' => $nan->name));

  $form_state['redirect'] = 'admin/content/nans';
}



/**
 * Page to add nan Entities.
 *
 * @todo Pass this through a proper theme function
 */
function nan_add_page() {
  $controller = entity_ui_controller('search_api_nan');
  return $controller->addPage();
}


/**
 * Displays the list of available nan types for nan creation.
 *
 * @ingroup themeable
 */
function theme_nan_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="nan-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer nan types')) {
      $output = '<p>' . t('nan Entities cannot be added because you have not created any nan types yet. Go to the <a href="@create-nan-type">nan type creation page</a> to add a new nan type.', array('@create-nan-type' => url('admin/structure/nan_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No nan types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}





/**
 * Sets the breadcrumb for administrative nan pages.
 */
function nan_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('nans'), 'admin/content/nans'),
  );

  drupal_set_breadcrumb($breadcrumb);
}





//function nan_form($form, &$form_state, $nan = NULL) {
//  $form['title'] = array(
//    '#title' => t('Title'),
//    '#type' => 'textfield',
//    '#default_value' => isset($nan->title) ? $nan->title : '',
//    '#description' => t('Nan title.'),
//    '#required' => TRUE,
//    '#weight' => -50,
//  );
//  $form['description'] = array(
//    '#title' => t('Description'),
//    '#type' => 'textfield',
//    '#default_value' => isset($nan->description) ? $nan->description : '',
//    '#description' => t('Description for admin use only.'),
//    '#required' => FALSE,
//  );
//
//  $form['path'] = array(
//    '#title' => t('Path'),
//    '#type' => 'textfield',
//    '#default_value' => isset($nan->path) ? $nan->path : '',
//    '#description' => t('Path to the page without leading slash.'),
//    '#required' => TRUE,
//  );
//
//  $form['frequency'] = array(
//    '#title' => t('Frequency'),
//    '#type' => 'textfield',
//    '#default_value' => isset($nan->frequency) ? $nan->frequency : '0',
//    '#description' => t('The time between indexing in seconds.'),
//    '#required' => TRUE,
//  );
//  $form['auto_populate_body'] = array(
//    '#title' => t('Auto Populate Body (Y/N)'),
//    '#type' => 'textfield',
//    '#default_value' => isset($nan->auto_populate_body) ? $nan->auto_populate_body : 'N',
//    '#description' => t('Automatically load the contents of the path into the body field for indexing.'),
//    '#required' => TRUE,
//  );
//  $form['body'] = array(
//    '#title' => t('Body'),
//    '#type' => 'textarea',
//    '#default_value' => isset($nan->body) ? $nan->body : '',
//    '#description' => t('Content area of the page.  This is not usually required.'),
//    '#required' => FALSE,
//  );
//
//  field_attach_form('nan', $nan, $form, $form_state);
//
//  $form['actions'] = array(
//    '#type' => 'actions',
//    'submit' => array(
//      '#type' => 'submit',
//      '#value' => isset($nan->id) ? t('Update Nan') : t('Save Nan'),
//    ),
//  );
//
//  return $form;
//}
