<?php
/**
 * @file
 * Defines print select field for Views module.
 */


/**
 * Implements hook_views_data_alter().
 *
 * @param $data
 *   Information about Views' tables and fields.
 */
function wfm_coupons_views_data_alter(&$data) {
  $data['node']['print_select'] = array(
    'field' => array(
      'title' => t('Print Select'),
      'help' => t('Print Select Checkbox'),
      'handler' => 'wfm_coupons_field_handler_print_select',
    ),
  );
}