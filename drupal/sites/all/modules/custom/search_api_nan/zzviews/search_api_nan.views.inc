<?php

/**
 * @file
 * Providing extra functionality for the Model UI via views.
 */


/**
 * Implements hook_views_data()
 */
function search_api_nan_views_data_alter(&$data) {
  $data['search_api_nan']['link_search_api_nan'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the search_api_nan.'),
      'handler' => 'search_api_nan_handler_link_field',
    ),
  );
  $data['search_api_nan']['edit_search_api_nan'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the search_api_nan.'),
      'handler' => 'search_api_nan_handler_edit_link_field',
    ),
  );
  $data['search_api_nan']['delete_search_api_nan'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the search_api_nan.'),
      'handler' => 'search_api_nan_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows search_api_nans/search_api_nan/%search_api_nan_id/op
  $data['search_api_nan']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this search_api_nan.'),
      'handler' => 'search_api_nan_handler_search_api_nan_operations_field',
    ),
  );
}


/**
 * Implements hook_views_default_views().
 */
function search_api_nan_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'search_api_nans';
  $view->description = 'A list of all search_api_nans';
  $view->tag = 'search_api_nans';
  $view->base_table = 'search_api_nan';
  $view->human_name = 'Models';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Models';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any search_api_nan type';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'nan_id' => 'nan_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'nan_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No nans have been created yet';
  /* Field: Model: Model ID */
  $handler->display->display_options['fields']['nan_id']['id'] = 'nan_id';
  $handler->display->display_options['fields']['nan_id']['table'] = 'search_api_nan';
  $handler->display->display_options['fields']['nan_id']['field'] = 'nan_id';
  $handler->display->display_options['fields']['nan_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nan_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nan_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nan_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nan_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nan_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nan_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nan_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nan_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nan_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nan_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nan_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nan_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nan_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nan_id']['empty_zero'] = 0;
  /* Field: Model: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_nan';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  /* Field: Model: Link */
  $handler->display->display_options['fields']['link_model']['id'] = 'link_model';
  $handler->display->display_options['fields']['link_model']['table'] = 'search_api_nan';
  $handler->display->display_options['fields']['link_model']['field'] = 'link_model';
  $handler->display->display_options['fields']['link_model']['label'] = 'View';
  $handler->display->display_options['fields']['link_model']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_model']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_model']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_model']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_model']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_model']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_model']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_model']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_model']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_model']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_model']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_model']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_model']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_model']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_model']['empty_zero'] = 0;
  /* Field: Model: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'search_api_nan';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['operations']['empty_zero'] = 0;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'nans_admin_page');
  $handler->display->display_options['path'] = 'admin/content/nans/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Nans';
  $handler->display->display_options['tab_options']['description'] = 'Manage nans';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['nans'] = array(
    t('Master'),
    t('Models'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Empty '),
    t('No models have been created yet'),
    t('Model ID'),
    t('.'),
    t(','),
    t('Name'),
    t('View'),
    t('Operations links'),
    t('Page'),
  );
  $views[] = $view;
  return $views;

}
