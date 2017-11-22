<?php
/**
 * @file
 * wfm_coupons.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function wfm_coupons_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__redirect_context_feed7bbe-8fbf-4ac3-9688-ee6fc8cdbe32';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'redirect_context';
  $handler->weight = 103;
  $handler->conf = array(
    'title' => 'Redirect Coupon Nodes',
    'contexts' => array(),
    'relationships' => array(),
    'path' => 'coupons',
    'query' => '',
    'fragment' => '',
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'coupon' => 'coupon',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 6,
              1 => 3,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['node_view__redirect_context_feed7bbe-8fbf-4ac3-9688-ee6fc8cdbe32'] = $handler;

  return $export;
}
