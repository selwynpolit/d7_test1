<?php
/**
 * @file
 * wfm_coupons.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function wfm_coupons_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create coupon content'.
  $permissions['create coupon content'] = array(
    'name' => 'create coupon content',
    'roles' => array(
      'Global Content Admin' => 'Global Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any coupon content'.
  $permissions['delete any coupon content'] = array(
    'name' => 'delete any coupon content',
    'roles' => array(
      'Global Content Admin' => 'Global Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own coupon content'.
  $permissions['delete own coupon content'] = array(
    'name' => 'delete own coupon content',
    'roles' => array(
      'Global Content Admin' => 'Global Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any coupon content'.
  $permissions['edit any coupon content'] = array(
    'name' => 'edit any coupon content',
    'roles' => array(
      'Global Content Admin' => 'Global Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own coupon content'.
  $permissions['edit own coupon content'] = array(
    'name' => 'edit own coupon content',
    'roles' => array(
      'Global Content Admin' => 'Global Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view any unpublished coupon content'.
  $permissions['view any unpublished coupon content'] = array(
    'name' => 'view any unpublished coupon content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
