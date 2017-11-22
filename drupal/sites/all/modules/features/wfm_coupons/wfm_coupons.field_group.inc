<?php
/**
 * @file
 * wfm_coupons.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function wfm_coupons_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_offer_info|node|coupon|form';
  $field_group->group_name = 'group_offer_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'coupon';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Offer Info',
    'weight' => '2',
    'children' => array(
      0 => 'field_coupon_headline',
      1 => 'field_coupon_image',
      2 => 'field_coupon_offer',
      3 => 'field_coupon_plu',
      4 => 'field_coupon_expiration',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_offer_info|node|coupon|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_offer_valid_info|node|coupon|form';
  $field_group->group_name = 'group_offer_valid_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'coupon';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Offer Valid Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_coupon_country',
      1 => 'field_coupon_region',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_offer_valid_info|node|coupon|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Offer Info');
  t('Offer Valid Info');

  return $field_groups;
}
