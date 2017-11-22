<?php
/**
 * @file
 * Forms and functions only needed on administration pages.
 */

/**
 * Generates the form message entity add/edit form.
 *
 * This form is automatically picked up by the administrative UI provided by
 * Entity API module.
 */
function formmsgs_form($form, &$form_state, $formmsg, $op = 'edit') {

  if ($op == 'clone') {
    $formmsg->label .= ' (cloned)';
    $formmsg->name .= '_clone';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $formmsg->label,
  );
  // Machine-readable form message name.
  $form['name'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($formmsg->name) ? $formmsg->name : '',
    '#disabled' => ($op === 'edit') ? TRUE : FALSE,
    '#machine_name' => array(
      'exists' => 'formmsgs_load_by_name',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this form message. It can only contain lowercase letters, numbers, and underscores.'),
  );
  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Active'),
    '#default_value' => $formmsg->status,
  );

  // $formmsg = formmsgs_create(array('type' => 'formmsgs'));
  field_attach_form('formmsgs', $formmsg, $form, $form_state);
  
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save form message'),
    '#weight' => 50,
  );
  return $form;
}

/**
 * Form API submit callback for the formmsgs entity add/edit form.
 */
function formmsgs_form_submit(&$form, &$form_state) {
  $formmsg = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $formmsg->save();
  $form_state['redirect'] = 'admin/structure/formmsgs';
}

