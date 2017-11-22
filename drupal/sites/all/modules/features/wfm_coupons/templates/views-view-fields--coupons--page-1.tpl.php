<?php
/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

//	drupal_add_css(drupal_get_path('module', 'wfm_coupons') . '/styles/print.css');
/*
There is currently a bug when printing a single coupon, this drupal_add_css does not properly add the style.
This template is being executed, but for some reason the drupal_add_css fails.
We don't have time to troubleshoot this now, so I am simply placing the style here in the template file as a
temporary solution.
*/

	$plu = $row->field_field_coupon_plu[0]['rendered']['#markup'];
	$expires = date('F jS, Y', strtotime($row->field_field_coupon_expiration[0]['rendered']['#markup']));
?>

<style>
p {
  margin: 0;
  padding: 0;
}
.view-content {
  padding: 0 0 20px;
}
.views-row {
  width: 325px;
  float: left;
  margin-right: 20px;
  margin-top: 20px;
  text-align: center;
  position: relative;
  font-size: 12px;
}
.coupon-individual-print-view {
  position: relative;
  border: 2px dashed black;
  overflow: hidden;
  padding: 5px 10px 10px;
  height: 215px;
  max-height: 215px;
}
.cut {
  position: absolute;
  top: -13px;
  left: 6px;
}
.view-content {
  position: relative;
  padding: 20px 0;
}
.view-content:after, .clearfix:after {
  content: "";
  display: table;
  clear: both;
}
.wfmcouponlogo {
  float: left;
  padding-right: 10px;
}
.short-redemption-info {
  margin: 3px 0 5px 0;
}
.offer {
  font-size: 25px;
  clear: left;
  text-align: center;
}
.headline {
  font-size: 10px;
  margin-top: 1px;
  text-align: center;
  line-height: 100%;
}
/*
 * Always make sure that the legal text hugs the bottom of the coupon,
 * but never bleeds past it.
 */
.long-redemption-info {
  position: absolute;
  bottom: 2px;
  font-size: 8px;
  padding-top: 10px;
  text-align: left;
}
.barcode {
  text-align: left;
  font-size: 1.2em;
  margin-top: 20px;
  float: right;
  margin-right: 20px;
}
.plu, .plu-expires {
  float: left;
}
.product {
  margin-top: 10px;
}
</style>

<style media="print">
.views-row {
  float: none;
  display: inline-block;
}
.views-row:nth-child(12n) {
  page-break-after: always;
}
</style>

<!--[if lte IE 9]>
<style media="print">
  .views-row {
    max-width: 45%;
  }
  .plu-expires {
    width: 75%;
    float: right;
    font-size: 10px;
  }
</style>

<![endif]-->
<div class="cut" colspan="2"><img src="//assets.wholefoodsmarket.com/images/coupon-scissors.gif" alt="" height="15" width="35"></div>
<div class="coupon-individual-print-view">
	<img class="wfmcouponlogo" src="//assets.wholefoodsmarket.com/images/wfmcouponlogo.gif" alt="" height="35" width="50">
	<div class="plu-expires">
		<span class="plu"><strong>PLU: <?php print $plu; ?></strong></span>&nbsp;
		<span class="expires">Expires: <?php print $expires; ?></span><br>
        <div class="short-redemption-info"><?php print t("Redeemable only at Whole Foods Market®"); ?></div>
	</div>
	<div class="offer-headline-img clearfix">
		<p class="offer"><?php print $row->field_field_coupon_offer[0]['rendered']['#markup']; ?></p>
		<p class="headline"><?php print $row->field_field_coupon_headline[0]['raw']['value']; ?></p>
	</div>
  <?php
  if ($row->_field_data['nid']['entity']->field_coupon_country['und'][0]['nid'] == '94296') {
    $country_name = 'Canada';
  } else {
    $country_name = 'the U.S.A.';
  }
  ?>
  <div class="clearfix">
    <img class="product" src="//assets.wholefoodsmarket.com/coupons/images/coupons/large/<?php print $plu; ?>.png" height="75" width="60">
    <div class="barcode"><?php print $fields['field_coupon_plu']->content; ?></div>
  </div>
  <p class="long-redemption-info"><?php print _wfm_coupons_legal_bs($country_name) . '&nbsp;' . t('Expires') . '&nbsp;' . $expires; ?></p>
</div>
