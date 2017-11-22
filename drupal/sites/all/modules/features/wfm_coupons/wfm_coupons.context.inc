<?php
/**
 * @file
 * wfm_coupons.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function wfm_coupons_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'wfm_coupons';
  $context->description = 'Handles National and Regional Coupons';
  $context->tag = 'Sales';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'newcoupons*' => 'coupons/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'wfm_blocks-wfm_blocks_coupon_filters' => array(
          'module' => 'wfm_blocks',
          'delta' => 'wfm_blocks_coupon_filters',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Handles National and Regional Coupons');
  t('Sales');
  $export['wfm_coupons'] = $context;

  return $export;
}
