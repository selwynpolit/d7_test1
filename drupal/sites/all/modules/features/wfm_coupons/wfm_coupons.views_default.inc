<?php
/**
 * @file
 * wfm_coupons.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function wfm_coupons_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'coupons';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Coupons';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Coupons';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'coupon-[field_coupon_plu]';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_coupon_offer' => 'field_coupon_offer',
    'field_coupon_headline' => 'field_coupon_headline',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* No results behavior: No Store Selected */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['ui_name'] = 'No Store Selected';
  $handler->display->display_options['empty']['area']['label'] = 'No Store Selected';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '[api:get_template_text["wfm_template_text_coupons_no_results"]/]';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Coupon PLU */
  $handler->display->display_options['fields']['field_coupon_plu_1']['id'] = 'field_coupon_plu_1';
  $handler->display->display_options['fields']['field_coupon_plu_1']['table'] = 'field_data_field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu_1']['field'] = 'field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu_1']['label'] = 'PLU';
  $handler->display->display_options['fields']['field_coupon_plu_1']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Coupon Expiration */
  $handler->display->display_options['fields']['field_coupon_expiration']['id'] = 'field_coupon_expiration';
  $handler->display->display_options['fields']['field_coupon_expiration']['table'] = 'field_data_field_coupon_expiration';
  $handler->display->display_options['fields']['field_coupon_expiration']['field'] = 'field_coupon_expiration';
  $handler->display->display_options['fields']['field_coupon_expiration']['label'] = 'Expires';
  $handler->display->display_options['fields']['field_coupon_expiration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coupon_expiration']['settings'] = array(
    'format_type' => 'blog_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Coupon Offer */
  $handler->display->display_options['fields']['field_coupon_offer']['id'] = 'field_coupon_offer';
  $handler->display->display_options['fields']['field_coupon_offer']['table'] = 'field_data_field_coupon_offer';
  $handler->display->display_options['fields']['field_coupon_offer']['field'] = 'field_coupon_offer';
  $handler->display->display_options['fields']['field_coupon_offer']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_offer']['element_label_colon'] = FALSE;
  /* Field: Content: Coupon Headline */
  $handler->display->display_options['fields']['field_coupon_headline']['id'] = 'field_coupon_headline';
  $handler->display->display_options['fields']['field_coupon_headline']['table'] = 'field_data_field_coupon_headline';
  $handler->display->display_options['fields']['field_coupon_headline']['field'] = 'field_coupon_headline';
  $handler->display->display_options['fields']['field_coupon_headline']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_headline']['element_label_colon'] = FALSE;
  /* Field: Content: Coupon Image */
  $handler->display->display_options['fields']['field_coupon_image']['id'] = 'field_coupon_image';
  $handler->display->display_options['fields']['field_coupon_image']['table'] = 'field_data_field_coupon_image';
  $handler->display->display_options['fields']['field_coupon_image']['field'] = 'field_coupon_image';
  $handler->display->display_options['fields']['field_coupon_image']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coupon_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_coupon_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Barcode */
  $handler->display->display_options['fields']['field_coupon_plu']['id'] = 'field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu']['table'] = 'field_data_field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu']['field'] = 'field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu']['ui_name'] = 'Barcode';
  $handler->display->display_options['fields']['field_coupon_plu']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_plu']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coupon_plu']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_coupon_plu']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Limit one coupon per purchase of specified product(s) per individual. Void if altered, transferred, reproduced, exchanged, sold, purchased, or where prohibited or restricted by law. No monetary value. Valid only in the U.S.A. Expires [field_coupon_expiration].';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Coupon Region (field_coupon_region) */
  $handler->display->display_options['arguments']['field_coupon_region_nid']['id'] = 'field_coupon_region_nid';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['table'] = 'field_data_field_coupon_region';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['field'] = 'field_coupon_region_nid';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_coupon_region_nid']['title'] = 'You are viewing coupons for %1 and %2';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Coupon Country (field_coupon_country) */
  $handler->display->display_options['arguments']['field_coupon_country_nid']['id'] = 'field_coupon_country_nid';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['table'] = 'field_data_field_coupon_country';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['field'] = 'field_coupon_country_nid';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'coupon' => 'coupon',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Coupons Block */
  $handler = $view->new_display('block', 'Coupons Block', 'block');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Print Select */
  $handler->display->display_options['fields']['print_select']['id'] = 'print_select';
  $handler->display->display_options['fields']['print_select']['table'] = 'node';
  $handler->display->display_options['fields']['print_select']['field'] = 'print_select';
  $handler->display->display_options['fields']['print_select']['label'] = '';
  $handler->display->display_options['fields']['print_select']['element_label_colon'] = FALSE;
  /* Field: Content: Coupon PLU */
  $handler->display->display_options['fields']['field_coupon_plu']['id'] = 'field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu']['table'] = 'field_data_field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu']['field'] = 'field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_plu']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_coupon_plu']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coupon_plu']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_coupon_plu']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Coupon Image */
  $handler->display->display_options['fields']['field_coupon_image']['id'] = 'field_coupon_image';
  $handler->display->display_options['fields']['field_coupon_image']['table'] = 'field_data_field_coupon_image';
  $handler->display->display_options['fields']['field_coupon_image']['field'] = 'field_coupon_image';
  $handler->display->display_options['fields']['field_coupon_image']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coupon_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_coupon_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Coupon Offer */
  $handler->display->display_options['fields']['field_coupon_offer']['id'] = 'field_coupon_offer';
  $handler->display->display_options['fields']['field_coupon_offer']['table'] = 'field_data_field_coupon_offer';
  $handler->display->display_options['fields']['field_coupon_offer']['field'] = 'field_coupon_offer';
  $handler->display->display_options['fields']['field_coupon_offer']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_offer']['element_label_colon'] = FALSE;
  /* Field: Content: Coupon Headline */
  $handler->display->display_options['fields']['field_coupon_headline']['id'] = 'field_coupon_headline';
  $handler->display->display_options['fields']['field_coupon_headline']['table'] = 'field_data_field_coupon_headline';
  $handler->display->display_options['fields']['field_coupon_headline']['field'] = 'field_coupon_headline';
  $handler->display->display_options['fields']['field_coupon_headline']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Coupon Region (field_coupon_region) */
  $handler->display->display_options['arguments']['field_coupon_region_nid']['id'] = 'field_coupon_region_nid';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['table'] = 'field_data_field_coupon_region';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['field'] = 'field_coupon_region_nid';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_coupon_region_nid']['title'] = 'Coupons for %1';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_coupon_region_nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Coupon Country (field_coupon_country) */
  $handler->display->display_options['arguments']['field_coupon_country_nid']['id'] = 'field_coupon_country_nid';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['table'] = 'field_data_field_coupon_country';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['field'] = 'field_coupon_country_nid';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_coupon_country_nid']['summary_options']['items_per_page'] = '25';

  /* Display: Print Page */
  $handler = $view->new_display('page', 'Print Page', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Coupon PLU */
  $handler->display->display_options['fields']['field_coupon_plu_1']['id'] = 'field_coupon_plu_1';
  $handler->display->display_options['fields']['field_coupon_plu_1']['table'] = 'field_data_field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu_1']['field'] = 'field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu_1']['label'] = 'PLU';
  $handler->display->display_options['fields']['field_coupon_plu_1']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Coupon Expiration */
  $handler->display->display_options['fields']['field_coupon_expiration']['id'] = 'field_coupon_expiration';
  $handler->display->display_options['fields']['field_coupon_expiration']['table'] = 'field_data_field_coupon_expiration';
  $handler->display->display_options['fields']['field_coupon_expiration']['field'] = 'field_coupon_expiration';
  $handler->display->display_options['fields']['field_coupon_expiration']['label'] = 'Expires';
  $handler->display->display_options['fields']['field_coupon_expiration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coupon_expiration']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_coupon_expiration']['settings'] = array(
    'format_type' => 'blog_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Coupon Offer */
  $handler->display->display_options['fields']['field_coupon_offer']['id'] = 'field_coupon_offer';
  $handler->display->display_options['fields']['field_coupon_offer']['table'] = 'field_data_field_coupon_offer';
  $handler->display->display_options['fields']['field_coupon_offer']['field'] = 'field_coupon_offer';
  $handler->display->display_options['fields']['field_coupon_offer']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_offer']['element_label_colon'] = FALSE;
  /* Field: Content: Coupon Headline */
  $handler->display->display_options['fields']['field_coupon_headline']['id'] = 'field_coupon_headline';
  $handler->display->display_options['fields']['field_coupon_headline']['table'] = 'field_data_field_coupon_headline';
  $handler->display->display_options['fields']['field_coupon_headline']['field'] = 'field_coupon_headline';
  $handler->display->display_options['fields']['field_coupon_headline']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_headline']['element_label_colon'] = FALSE;
  /* Field: Content: Coupon Image */
  $handler->display->display_options['fields']['field_coupon_image']['id'] = 'field_coupon_image';
  $handler->display->display_options['fields']['field_coupon_image']['table'] = 'field_data_field_coupon_image';
  $handler->display->display_options['fields']['field_coupon_image']['field'] = 'field_coupon_image';
  $handler->display->display_options['fields']['field_coupon_image']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coupon_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_coupon_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Barcode */
  $handler->display->display_options['fields']['field_coupon_plu']['id'] = 'field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu']['table'] = 'field_data_field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu']['field'] = 'field_coupon_plu';
  $handler->display->display_options['fields']['field_coupon_plu']['ui_name'] = 'Barcode';
  $handler->display->display_options['fields']['field_coupon_plu']['label'] = '';
  $handler->display->display_options['fields']['field_coupon_plu']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coupon_plu']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_coupon_plu']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['base_path'] = 'coupons';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['path'] = 'mycoupons/%';
  $export['coupons'] = $view;

  return $export;
}
