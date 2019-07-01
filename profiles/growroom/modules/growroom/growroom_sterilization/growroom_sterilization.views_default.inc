<?php
/**
 * @file
 * growroom_sterilization.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function growroom_sterilization_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'growroom_sterilization_plan';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'growroom_plan';
  $view->human_name = 'Growroom Sterilization Management Plans';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sterilization Management Plans';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any sterilization growroom plans';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
    'field_growroom_date_range' => 'field_growroom_date_range',
    'active' => 'active',
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
    'field_growroom_date_range' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'active' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No plans found.';
  /* Field: Growroom plan: Growroom plan ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'growroom_plan';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Plan ID';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Growroom plan: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'growroom_plan';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'growroom/plan/[id]';
  /* Field: Field: Date range */
  $handler->display->display_options['fields']['field_growroom_date_range']['id'] = 'field_growroom_date_range';
  $handler->display->display_options['fields']['field_growroom_date_range']['table'] = 'field_data_field_growroom_date_range';
  $handler->display->display_options['fields']['field_growroom_date_range']['field'] = 'field_growroom_date_range';
  $handler->display->display_options['fields']['field_growroom_date_range']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y-m-d',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Field: Season */
  $handler->display->display_options['fields']['field_growroom_season']['id'] = 'field_growroom_season';
  $handler->display->display_options['fields']['field_growroom_season']['table'] = 'field_data_field_growroom_season';
  $handler->display->display_options['fields']['field_growroom_season']['field'] = 'field_growroom_season';
  $handler->display->display_options['fields']['field_growroom_season']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Areas */
  $handler->display->display_options['fields']['field_growroom_area']['id'] = 'field_growroom_area';
  $handler->display->display_options['fields']['field_growroom_area']['table'] = 'field_data_field_growroom_area';
  $handler->display->display_options['fields']['field_growroom_area']['field'] = 'field_growroom_area';
  $handler->display->display_options['fields']['field_growroom_area']['delta_offset'] = '0';
  /* Field: Growroom plan: Active */
  $handler->display->display_options['fields']['active']['id'] = 'active';
  $handler->display->display_options['fields']['active']['table'] = 'growroom_plan';
  $handler->display->display_options['fields']['active']['field'] = 'active';
  $handler->display->display_options['fields']['active']['not'] = 0;
  /* Sort criterion: Growroom plan: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'growroom_plan';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Name';
  /* Sort criterion: Growroom plan: Active */
  $handler->display->display_options['sorts']['active']['id'] = 'active';
  $handler->display->display_options['sorts']['active']['table'] = 'growroom_plan';
  $handler->display->display_options['sorts']['active']['field'] = 'active';
  $handler->display->display_options['sorts']['active']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['active']['expose']['label'] = 'Active';
  /* Filter criterion: Growroom plan: Growroom plan type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'growroom_plan';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sterilization' => 'sterilization',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Plan type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Growroom plan: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'growroom_plan';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  /* Filter criterion: Field: Season (field_growroom_season) */
  $handler->display->display_options['filters']['field_growroom_season_tid']['id'] = 'field_growroom_season_tid';
  $handler->display->display_options['filters']['field_growroom_season_tid']['table'] = 'field_data_field_growroom_season';
  $handler->display->display_options['filters']['field_growroom_season_tid']['field'] = 'field_growroom_season_tid';
  $handler->display->display_options['filters']['field_growroom_season_tid']['value'] = '';
  $handler->display->display_options['filters']['field_growroom_season_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_season_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_season_tid']['expose']['operator_id'] = 'field_growroom_season_tid_op';
  $handler->display->display_options['filters']['field_growroom_season_tid']['expose']['label'] = 'Season';
  $handler->display->display_options['filters']['field_growroom_season_tid']['expose']['operator'] = 'field_growroom_season_tid_op';
  $handler->display->display_options['filters']['field_growroom_season_tid']['expose']['identifier'] = 'field_growroom_season_tid';
  $handler->display->display_options['filters']['field_growroom_season_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_growroom_season_tid']['vocabulary'] = 'growroom_season';
  $handler->display->display_options['filters']['field_growroom_season_tid']['hierarchy'] = 1;
  /* Filter criterion: Field: Areas (field_growroom_area) */
  $handler->display->display_options['filters']['field_growroom_area_tid']['id'] = 'field_growroom_area_tid';
  $handler->display->display_options['filters']['field_growroom_area_tid']['table'] = 'field_data_field_growroom_area';
  $handler->display->display_options['filters']['field_growroom_area_tid']['field'] = 'field_growroom_area_tid';
  $handler->display->display_options['filters']['field_growroom_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_area_tid']['expose']['operator_id'] = 'field_growroom_area_tid_op';
  $handler->display->display_options['filters']['field_growroom_area_tid']['expose']['label'] = 'Areas';
  $handler->display->display_options['filters']['field_growroom_area_tid']['expose']['operator'] = 'field_growroom_area_tid_op';
  $handler->display->display_options['filters']['field_growroom_area_tid']['expose']['identifier'] = 'field_growroom_area_tid';
  $handler->display->display_options['filters']['field_growroom_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_growroom_area_tid']['vocabulary'] = 'growroom_areas';
  $handler->display->display_options['filters']['field_growroom_area_tid']['hierarchy'] = 1;
  /* Filter criterion: Growroom plan: Active */
  $handler->display->display_options['filters']['active']['id'] = 'active';
  $handler->display->display_options['filters']['active']['table'] = 'growroom_plan';
  $handler->display->display_options['filters']['active']['field'] = 'active';
  $handler->display->display_options['filters']['active']['value'] = '1';
  $handler->display->display_options['filters']['active']['group'] = 1;
  $handler->display->display_options['filters']['active']['exposed'] = TRUE;
  $handler->display->display_options['filters']['active']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['active']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['active']['expose']['operator'] = 'active_op';
  $handler->display->display_options['filters']['active']['expose']['identifier'] = 'active';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'growroom/plans/sterilization';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Sterilization Management Plans';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'growroom';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['growroom_sterilization_plan'] = $view;

  return $export;
}
