<?php
/**
 * @file
 * growroom_asset_offspring.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function growroom_asset_offspring_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'growroom_asset_offspring';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'growroom_asset';
  $view->human_name = 'Growroom Asset Offspring';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Offspring';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view growroom assets';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100, 250, 500';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'name' => 'name',
    'archived' => 'archived',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'archived' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No offspring found.';
  /* Field: Growroom asset: Growroom asset ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Growroom asset: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'growroom/asset/[id]';
  /* Field: Growroom asset: Archived */
  $handler->display->display_options['fields']['archived']['id'] = 'archived';
  $handler->display->display_options['fields']['archived']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['archived']['field'] = 'archived';
  $handler->display->display_options['fields']['archived']['date_format'] = 'custom';
  $handler->display->display_options['fields']['archived']['custom_date_format'] = 'M j Y';
  $handler->display->display_options['fields']['archived']['second_date_format'] = 'long';
  /* Sort criterion: Growroom asset: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'growroom_asset';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Name';
  /* Sort criterion: Growroom asset: Growroom asset ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'growroom_asset';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  $handler->display->display_options['sorts']['id']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['id']['expose']['label'] = 'Asset ID';
  /* Contextual filter: Growroom asset: Parent(s) (field_growroom_parent) */
  $handler->display->display_options['arguments']['field_growroom_parent_target_id']['id'] = 'field_growroom_parent_target_id';
  $handler->display->display_options['arguments']['field_growroom_parent_target_id']['table'] = 'field_data_field_growroom_parent';
  $handler->display->display_options['arguments']['field_growroom_parent_target_id']['field'] = 'field_growroom_parent_target_id';
  $handler->display->display_options['arguments']['field_growroom_parent_target_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_parent_target_id']['title'] = 'Offspring of %1';
  $handler->display->display_options['arguments']['field_growroom_parent_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_growroom_parent_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_growroom_parent_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_growroom_parent_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_growroom_parent_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_parent_target_id']['validate']['type'] = 'growroom_asset';
  /* Filter criterion: Growroom asset: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'growroom_asset';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  /* Filter criterion: Growroom asset: Archived (boolean) */
  $handler->display->display_options['filters']['archived_boolean']['id'] = 'archived_boolean';
  $handler->display->display_options['filters']['archived_boolean']['table'] = 'growroom_asset';
  $handler->display->display_options['filters']['archived_boolean']['field'] = 'archived_boolean';
  $handler->display->display_options['filters']['archived_boolean']['value'] = 'All';
  $handler->display->display_options['filters']['archived_boolean']['exposed'] = TRUE;
  $handler->display->display_options['filters']['archived_boolean']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['archived_boolean']['expose']['label'] = 'Archived';
  $handler->display->display_options['filters']['archived_boolean']['expose']['operator'] = 'archived_boolean_op';
  $handler->display->display_options['filters']['archived_boolean']['expose']['identifier'] = 'archived_boolean';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'growroom/asset/%/offspring';
  $translatables['growroom_asset_offspring'] = array(
    t('Master'),
    t('Offspring'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('No offspring found.'),
    t('Growroom asset ID'),
    t('.'),
    t('Name'),
    t('Archived'),
    t('Asset ID'),
    t('All'),
    t('Offspring of %1'),
    t('Page'),
  );
  $export['growroom_asset_offspring'] = $view;

  return $export;
}
