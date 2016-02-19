<?php

function naan_form($form, &$form_state, $naan = NULL) {
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
 * Validation for naan entity form.
 */
function naan_form_validate($form, &$form_state) {
  if (isset($form_state['values']['frequency']) && !is_numeric($form_state['values']['frequency'])) {
    form_set_error('frequency', t('Frequency field must be an integer value.'));
  }

  if (isset($form_state['values']['urlpath'])) {
    $val = trim($form_state['values']['urlpath']);
    if (substr($val, 0, 1) === '/') {
      form_set_error('urlpath', t('URL may not begin with a forward slash /.'));
    }
    if (substr($val, 0, 1) === "\\") {
      form_set_error('urlpath', t('URL may not begin with a backslash \.'));
    }
  }


}

/**
 * Submit handler for naan entity form.
 */
function naan_form_submit($form, &$form_state) {
  $naan = entity_ui_form_submit_build_entity($form, $form_state);
  $naan->save();
  drupal_set_message(t('@name naan has been saved.', array('@name' => $naan->name)));
//  $form_state['redirect'] = 'admin/content/naans';
  $form_state['redirect'] = 'admin/naans';
}