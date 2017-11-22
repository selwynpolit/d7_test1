<?php
/**
 * @file
 * wfm_coupons.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function wfm_coupons_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'coupons';
  $feeds_importer->config = array(
    'name' => 'Coupons',
    'description' => 'Grabs coupons CSV from Mambo Sprouts',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
        'direct' => 0,
        'directory' => 'public://feeds/coupons/imports/',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '15552000',
        'author' => '44576',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Coupon Country',
            'target' => 'field_coupon_country:title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Coupon Region',
            'target' => 'field_coupon_region:title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Coupon Offer',
            'target' => 'field_coupon_offer',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Coupon Headline',
            'target' => 'field_coupon_headline',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Coupon PLU',
            'target' => 'field_coupon_plu',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Coupon Expiration',
            'target' => 'field_coupon_expiration:start',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Publish Date',
            'target' => 'publish_on',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Unpublish Date',
            'target' => 'unpublish_on',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'coupon',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['coupons'] = $feeds_importer;

  return $export;
}
