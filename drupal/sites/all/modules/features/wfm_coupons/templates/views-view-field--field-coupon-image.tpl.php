<?php
/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
// Check to see if there is an image in the Drupal database.
// This will allow content team to override S3 images on the fly.
if (isset($row->field_coupon_image_fid)) {
  print $output;
} 
else {
  $as3_root = "//assets.wholefoodsmarket.com/coupons/images/coupons/large/";
  
  $plu = '0';
  if (isset($row->field_coupon_plu_value)) {
    $plu = $row->field_coupon_plu_value;
  } 
  elseif (isset($row->field_field_coupon_plu['0']['rendered']['#markup'])) {
    $plu = $row->field_field_coupon_plu['0']['rendered']['#markup'];
  }
  
  $as3_image = $as3_root . $plu . '.png';
  $output = '<img typeof="foaf:Image" src="' . $as3_image . '" width="120" height="150" alt="" />';
  print $output;
}
// @TODO -- Need handler for malformed PLUs to display a default image
?>
