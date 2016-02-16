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
    '#type' => 'textfield',
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

  field_attach_form('naan', $naan, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($naan->id) ? t('Update Nan') : t('Save Nan'),
    ),
  );

  return $form;
}

/**
 * Validation for naan entity form.
 */
function naan_form_validate($form, &$form_state) {
  if (isset($form_state['values']['duration']) && !is_numeric($form_state['values']['duration'])) {
    form_set_error('duration', t('Duration field must be an integer value.'));
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