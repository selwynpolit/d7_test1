<?php
/**
 * @file
 * wfm_coupons.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function wfm_coupons_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_coupon_country'.
  $field_bases['field_coupon_country'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_coupon_country',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'profile2_private' => FALSE,
      'referenceable_types' => array(
        'bc_article' => 0,
        'bc_connect' => 0,
        'bc_coupon' => 0,
        'bc_image' => 0,
        'bc_video' => 0,
        'blog' => 0,
        'blog_post' => 0,
        'core_value' => 0,
        'coupon' => 0,
        'department' => 0,
        'department_article' => 0,
        'event' => 0,
        'faq' => 0,
        'instagram_feed' => 0,
        'instagram_media_item' => 0,
        'instagram_url' => 0,
        'job' => 0,
        'local_vendor' => 0,
        'marquee' => 0,
        'metro' => 0,
        'national_offices' => 'national_offices',
        'newsletter' => 0,
        'page' => 0,
        'person' => 0,
        'product' => 0,
        'product_certification' => 0,
        'product_line' => 0,
        'product_recall' => 0,
        'promo' => 0,
        'recipe' => 0,
        'region' => 0,
        'service' => 0,
        'special_diet' => 0,
        'store' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_coupon_expiration'.
  $field_bases['field_coupon_expiration'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_coupon_expiration',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 1,
      'cache_enabled' => 1,
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 'second',
        'year' => 'year',
      ),
      'profile2_private' => FALSE,
      'repeat' => 0,
      'timezone_db' => 'UTC',
      'todate' => '',
      'tz_handling' => 'site',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_coupon_headline'.
  $field_bases['field_coupon_headline'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_coupon_headline',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_coupon_image'.
  $field_bases['field_coupon_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_coupon_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_coupon_offer'.
  $field_bases['field_coupon_offer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_coupon_offer',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_coupon_plu'.
  $field_bases['field_coupon_plu'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_coupon_plu',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_coupon_region'.
  $field_bases['field_coupon_region'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_coupon_region',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'profile2_private' => FALSE,
      'referenceable_types' => array(
        'bc_article' => 0,
        'bc_connect' => 0,
        'bc_coupon' => 0,
        'bc_image' => 0,
        'bc_video' => 0,
        'blog' => 0,
        'blog_post' => 0,
        'core_value' => 0,
        'coupon' => 0,
        'department' => 0,
        'department_article' => 0,
        'event' => 0,
        'faq' => 0,
        'instagram_feed' => 0,
        'instagram_media_item' => 0,
        'instagram_url' => 0,
        'job' => 0,
        'local_vendor' => 0,
        'marquee' => 0,
        'metro' => 0,
        'national_offices' => 0,
        'newsletter' => 0,
        'page' => 0,
        'person' => 0,
        'product' => 0,
        'product_certification' => 0,
        'product_line' => 0,
        'product_recall' => 0,
        'promo' => 0,
        'recipe' => 0,
        'region' => 'region',
        'service' => 0,
        'special_diet' => 0,
        'store' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  return $field_bases;
}
