<?php
/**
 * @file
 * growroom_movement.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function growroom_movement_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'growroom_area_assets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'log';
  $view->human_name = 'Growroom Area Assets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'History of Assets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all logs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
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
    'type' => 'type',
    'active' => 'active',
    'timestamp' => 'timestamp',
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
    'type' => array(
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
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<small>This lists all assets that have ever been moved to this area. If an asset has been moved to this area more than once, it will show up more than once in this list.</small>';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Relationship: Log: Movement (field_growroom_movement) */
  $handler->display->display_options['relationships']['field_growroom_movement_value']['id'] = 'field_growroom_movement_value';
  $handler->display->display_options['relationships']['field_growroom_movement_value']['table'] = 'field_data_field_growroom_movement';
  $handler->display->display_options['relationships']['field_growroom_movement_value']['field'] = 'field_growroom_movement_value';
  $handler->display->display_options['relationships']['field_growroom_movement_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_growroom_movement_value']['delta'] = '0';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_growroom_asset_target_id']['id'] = 'field_growroom_asset_target_id';
  $handler->display->display_options['relationships']['field_growroom_asset_target_id']['table'] = 'field_data_field_growroom_asset';
  $handler->display->display_options['relationships']['field_growroom_asset_target_id']['field'] = 'field_growroom_asset_target_id';
  $handler->display->display_options['relationships']['field_growroom_asset_target_id']['label'] = 'Asset';
  /* Field: Growroom asset: Growroom asset ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['relationship'] = 'field_growroom_asset_target_id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Growroom asset: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_growroom_asset_target_id';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'growroom/asset/[id]';
  /* Field: Growroom asset: Growroom asset type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_growroom_asset_target_id';
  $handler->display->display_options['fields']['type']['label'] = 'Type';
  /* Field: Growroom asset: Archived */
  $handler->display->display_options['fields']['archived']['id'] = 'archived';
  $handler->display->display_options['fields']['archived']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['archived']['field'] = 'archived';
  $handler->display->display_options['fields']['archived']['relationship'] = 'field_growroom_asset_target_id';
  $handler->display->display_options['fields']['archived']['date_format'] = 'custom';
  $handler->display->display_options['fields']['archived']['custom_date_format'] = 'M j Y';
  $handler->display->display_options['fields']['archived']['second_date_format'] = 'long';
  /* Field: Log: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'log';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Arrived';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'M j Y';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Sort criterion: Log: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'log';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Field collection item: Movement to (field_growroom_move_to) */
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['id'] = 'field_growroom_move_to_tid';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['table'] = 'field_data_field_growroom_move_to';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['field'] = 'field_growroom_move_to_tid';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['relationship'] = 'field_growroom_movement_value';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['title'] = 'Assets in %1';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['validate_options']['vocabularies'] = array(
    'growroom_areas' => 'growroom_areas',
  );
  /* Filter criterion: Log: Done */
  $handler->display->display_options['filters']['done']['id'] = 'done';
  $handler->display->display_options['filters']['done']['table'] = 'log';
  $handler->display->display_options['filters']['done']['field'] = 'done';
  $handler->display->display_options['filters']['done']['value'] = '1';
  $handler->display->display_options['filters']['done']['group'] = 1;
  /* Filter criterion: Growroom asset: Growroom asset type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'growroom_asset';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_growroom_asset_target_id';
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Asset type';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  /* Filter criterion: Date: Date (log) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'log';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Arrived after';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+3';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'log.timestamp' => 'log.timestamp',
  );
  /* Filter criterion: Date: Date (log) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'log';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Arrived before';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+3';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'log.timestamp' => 'log.timestamp',
  );
  $translatables['growroom_area_assets'] = array(
    t('Master'),
    t('History of Assets'),
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
    t('<small>This lists all assets that have ever been moved to this area. If an asset has been moved to this area more than once, it will show up more than once in this list.</small>'),
    t('Displaying @start - @end of @total'),
    t('field collection item from field_growroom_movement'),
    t('Asset'),
    t('Growroom asset ID'),
    t('.'),
    t('Name'),
    t('Type'),
    t('Archived'),
    t('Arrived'),
    t('All'),
    t('Assets in %1'),
    t('Asset type'),
    t('Arrived after'),
    t('Arrived before'),
  );
  $export['growroom_area_assets'] = $view;

  $view = new view();
  $view->name = 'growroom_asset_geojson';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'growroom_asset';
  $view->human_name = 'Growroom Asset GeoJSON';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Growroom Asset GeoJSON';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all logs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Growroom asset: Latest movement */
  $handler->display->display_options['relationships']['latest_movement']['id'] = 'latest_movement';
  $handler->display->display_options['relationships']['latest_movement']['table'] = 'growroom_asset';
  $handler->display->display_options['relationships']['latest_movement']['field'] = 'latest_movement';
  /* Field: Field: Geometry */
  $handler->display->display_options['fields']['field_growroom_geofield']['id'] = 'field_growroom_geofield';
  $handler->display->display_options['fields']['field_growroom_geofield']['table'] = 'field_data_field_growroom_geofield';
  $handler->display->display_options['fields']['field_growroom_geofield']['field'] = 'field_growroom_geofield';
  $handler->display->display_options['fields']['field_growroom_geofield']['relationship'] = 'latest_movement';
  $handler->display->display_options['fields']['field_growroom_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_growroom_geofield']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_growroom_geofield']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_growroom_geofield']['delta_offset'] = '0';
  /* Field: Growroom asset: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Contextual filter: Growroom asset: Growroom asset type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'growroom_asset';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  /* Filter criterion: Growroom asset: Archived (boolean) */
  $handler->display->display_options['filters']['archived_boolean']['id'] = 'archived_boolean';
  $handler->display->display_options['filters']['archived_boolean']['table'] = 'growroom_asset';
  $handler->display->display_options['filters']['archived_boolean']['field'] = 'archived_boolean';
  $handler->display->display_options['filters']['archived_boolean']['value'] = '0';
  $handler->display->display_options['filters']['archived_boolean']['group'] = 1;
  /* Filter criterion: Field: Geometry (field_growroom_geofield:geom) */
  $handler->display->display_options['filters']['field_growroom_geofield_geom']['id'] = 'field_growroom_geofield_geom';
  $handler->display->display_options['filters']['field_growroom_geofield_geom']['table'] = 'field_data_field_growroom_geofield';
  $handler->display->display_options['filters']['field_growroom_geofield_geom']['field'] = 'field_growroom_geofield_geom';
  $handler->display->display_options['filters']['field_growroom_geofield_geom']['relationship'] = 'latest_movement';
  $handler->display->display_options['filters']['field_growroom_geofield_geom']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_growroom_geofield_geom']['group'] = 1;

  /* Display: Full Geometry */
  $handler = $view->new_display('feed', 'Full Geometry', 'feed_full');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_geojson_feed';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'field_growroom_geofield';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'field_growroom_geofield';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_growroom_geofield';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_growroom_geofield';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'name';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['path'] = 'growroom/assets/geojson/full';

  /* Display: Centroid */
  $handler = $view->new_display('feed', 'Centroid', 'feed_centroid');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_geojson_feed';
  $handler->display->display_options['style_options']['data_source']['value'] = 'wkt';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'field_growroom_geofield';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'field_growroom_geofield';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_growroom_geofield';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_growroom_geofield';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'name';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'name';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Growroom asset: Growroom asset ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Field: Geometry */
  $handler->display->display_options['fields']['field_growroom_geofield']['id'] = 'field_growroom_geofield';
  $handler->display->display_options['fields']['field_growroom_geofield']['table'] = 'field_data_field_growroom_geofield';
  $handler->display->display_options['fields']['field_growroom_geofield']['field'] = 'field_growroom_geofield';
  $handler->display->display_options['fields']['field_growroom_geofield']['relationship'] = 'latest_movement';
  $handler->display->display_options['fields']['field_growroom_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_growroom_geofield']['settings'] = array(
    'data' => 'centroid',
  );
  $handler->display->display_options['fields']['field_growroom_geofield']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_growroom_geofield']['delta_offset'] = '0';
  /* Field: Growroom asset: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'growroom/asset/[id]';
  $handler->display->display_options['path'] = 'growroom/assets/geojson/centroid';
  $translatables['growroom_asset_geojson'] = array(
    t('Master'),
    t('Growroom Asset GeoJSON'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Latest movement'),
    t('Geometry'),
    t('Name'),
    t('All'),
    t('Full Geometry'),
    t('Centroid'),
    t('Growroom asset ID'),
    t('.'),
    t(','),
  );
  $export['growroom_asset_geojson'] = $view;

  $view = new view();
  $view->name = 'growroom_movement_log';
  $view->description = '';
  $view->tag = 'growroom_movement';
  $view->base_table = 'log';
  $view->human_name = 'Growroom movement logs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Logs of movements';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all logs';
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
    'views_bulk_operations' => 'views_bulk_operations',
    'done' => 'done',
    'id' => 'id',
    'timestamp' => 'timestamp',
    'field_growroom_asset' => 'field_growroom_asset',
    'field_growroom_move_to' => 'field_growroom_move_to',
    'name' => 'name',
    'type' => 'type',
    'field_growroom_flags' => 'field_growroom_flags',
    'field_growroom_log_category' => 'field_growroom_log_category',
    'field_growroom_log_owner' => 'field_growroom_log_owner',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'done' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_asset' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_move_to' => array(
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
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_flags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_log_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_log_owner' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = 'This lists all logs that define movements of assets. Multiple log types are included in this list, and are specified in the "Log type" column.';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No logs of movements found.';
  /* Relationship: Log: Movement (field_growroom_movement) */
  $handler->display->display_options['relationships']['field_growroom_movement_value']['id'] = 'field_growroom_movement_value';
  $handler->display->display_options['relationships']['field_growroom_movement_value']['table'] = 'field_data_field_growroom_movement';
  $handler->display->display_options['relationships']['field_growroom_movement_value']['field'] = 'field_growroom_movement_value';
  $handler->display->display_options['relationships']['field_growroom_movement_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_growroom_movement_value']['delta'] = '0';
  /* Field: Bulk operations: Log */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_log';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::growroom_log_assign_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::log_clone_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Delete',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::growroom_flags_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::growroom_map_kml_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::log_done_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Done',
    ),
    'action::log_undone_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Not Done',
    ),
    'action::log_reschedule_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Log: Done */
  $handler->display->display_options['fields']['done']['id'] = 'done';
  $handler->display->display_options['fields']['done']['table'] = 'log';
  $handler->display->display_options['fields']['done']['field'] = 'done';
  $handler->display->display_options['fields']['done']['type'] = 'custom';
  $handler->display->display_options['fields']['done']['type_custom_true'] = '✔';
  $handler->display->display_options['fields']['done']['not'] = 0;
  /* Field: Log: Log ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Log: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'log';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Date';
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['path'] = 'log/[id]';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'M j Y';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: Log: Assets */
  $handler->display->display_options['fields']['field_growroom_asset']['id'] = 'field_growroom_asset';
  $handler->display->display_options['fields']['field_growroom_asset']['table'] = 'field_data_field_growroom_asset';
  $handler->display->display_options['fields']['field_growroom_asset']['field'] = 'field_growroom_asset';
  $handler->display->display_options['fields']['field_growroom_asset']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field collection item: Movement to */
  $handler->display->display_options['fields']['field_growroom_move_to']['id'] = 'field_growroom_move_to';
  $handler->display->display_options['fields']['field_growroom_move_to']['table'] = 'field_data_field_growroom_move_to';
  $handler->display->display_options['fields']['field_growroom_move_to']['field'] = 'field_growroom_move_to';
  $handler->display->display_options['fields']['field_growroom_move_to']['relationship'] = 'field_growroom_movement_value';
  $handler->display->display_options['fields']['field_growroom_move_to']['delta_offset'] = '0';
  /* Field: Log: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'log';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Log name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'log/[id]';
  /* Field: Log: Log type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'log';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Field: Flags */
  $handler->display->display_options['fields']['field_growroom_flags']['id'] = 'field_growroom_flags';
  $handler->display->display_options['fields']['field_growroom_flags']['table'] = 'field_data_field_growroom_flags';
  $handler->display->display_options['fields']['field_growroom_flags']['field'] = 'field_growroom_flags';
  $handler->display->display_options['fields']['field_growroom_flags']['delta_offset'] = '0';
  /* Field: Log: Log category */
  $handler->display->display_options['fields']['field_growroom_log_category']['id'] = 'field_growroom_log_category';
  $handler->display->display_options['fields']['field_growroom_log_category']['table'] = 'field_data_field_growroom_log_category';
  $handler->display->display_options['fields']['field_growroom_log_category']['field'] = 'field_growroom_log_category';
  $handler->display->display_options['fields']['field_growroom_log_category']['label'] = 'Categories';
  $handler->display->display_options['fields']['field_growroom_log_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_growroom_log_category']['delta_offset'] = '0';
  /* Field: Log: Assigned to */
  $handler->display->display_options['fields']['field_growroom_log_owner']['id'] = 'field_growroom_log_owner';
  $handler->display->display_options['fields']['field_growroom_log_owner']['table'] = 'field_data_field_growroom_log_owner';
  $handler->display->display_options['fields']['field_growroom_log_owner']['field'] = 'field_growroom_log_owner';
  $handler->display->display_options['fields']['field_growroom_log_owner']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_growroom_log_owner']['delta_offset'] = '0';
  /* Sort criterion: Log: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'log';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['sorts']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['timestamp']['expose']['label'] = 'Date';
  /* Sort criterion: Log: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'log';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Log name';
  /* Sort criterion: Log: Log type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'log';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
  $handler->display->display_options['sorts']['type']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['type']['expose']['label'] = 'Log type';
  /* Sort criterion: Log: Log ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'log';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  $handler->display->display_options['sorts']['id']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['id']['expose']['label'] = 'Log ID';
  /* Contextual filter: Log: Assets (field_growroom_asset) */
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['id'] = 'field_growroom_asset_target_id';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['table'] = 'field_data_field_growroom_asset';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['field'] = 'field_growroom_asset_target_id';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['title'] = '%1\'s movements';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['validate']['type'] = 'growroom_asset';
  /* Filter criterion: Log: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'log';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Log name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  /* Filter criterion: Field collection item: Movement to (field_growroom_move_to) */
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['id'] = 'field_growroom_move_to_tid';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['table'] = 'field_data_field_growroom_move_to';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['field'] = 'field_growroom_move_to_tid';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['relationship'] = 'field_growroom_movement_value';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['expose']['operator_id'] = 'field_growroom_move_to_tid_op';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['expose']['label'] = 'Movement to';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['expose']['operator'] = 'field_growroom_move_to_tid_op';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['expose']['identifier'] = 'field_growroom_move_to_tid';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['vocabulary'] = 'growroom_areas';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['hierarchy'] = 1;
  /* Filter criterion: Log: Log type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'log';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Log type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Field: Flags (field_growroom_flags) */
  $handler->display->display_options['filters']['field_growroom_flags_value']['id'] = 'field_growroom_flags_value';
  $handler->display->display_options['filters']['field_growroom_flags_value']['table'] = 'field_data_field_growroom_flags';
  $handler->display->display_options['filters']['field_growroom_flags_value']['field'] = 'field_growroom_flags_value';
  $handler->display->display_options['filters']['field_growroom_flags_value']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_flags_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_flags_value']['expose']['operator_id'] = 'field_growroom_flags_value_op';
  $handler->display->display_options['filters']['field_growroom_flags_value']['expose']['label'] = 'Flags';
  $handler->display->display_options['filters']['field_growroom_flags_value']['expose']['operator'] = 'field_growroom_flags_value_op';
  $handler->display->display_options['filters']['field_growroom_flags_value']['expose']['identifier'] = 'field_growroom_flags_value';
  $handler->display->display_options['filters']['field_growroom_flags_value']['expose']['multiple'] = TRUE;
  /* Filter criterion: Log: Log category (field_growroom_log_category) */
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['id'] = 'field_growroom_log_category_tid';
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['table'] = 'field_data_field_growroom_log_category';
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['field'] = 'field_growroom_log_category_tid';
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['expose']['operator_id'] = 'field_growroom_log_category_tid_op';
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['expose']['operator'] = 'field_growroom_log_category_tid_op';
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['expose']['identifier'] = 'field_growroom_log_category_tid';
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['vocabulary'] = 'growroom_log_categories';
  $handler->display->display_options['filters']['field_growroom_log_category_tid']['hierarchy'] = 1;
  /* Filter criterion: Date: Date (log) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'log';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Start date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+3';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'log.timestamp' => 'log.timestamp',
  );
  /* Filter criterion: Date: Date (log) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'log';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'End date';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+3';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'log.timestamp' => 'log.timestamp',
  );
  /* Filter criterion: Log: Done */
  $handler->display->display_options['filters']['done']['id'] = 'done';
  $handler->display->display_options['filters']['done']['table'] = 'log';
  $handler->display->display_options['filters']['done']['field'] = 'done';
  $handler->display->display_options['filters']['done']['value'] = 'All';
  $handler->display->display_options['filters']['done']['group'] = 1;
  $handler->display->display_options['filters']['done']['exposed'] = TRUE;
  $handler->display->display_options['filters']['done']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['done']['expose']['label'] = 'Done';
  $handler->display->display_options['filters']['done']['expose']['operator'] = 'done_op';
  $handler->display->display_options['filters']['done']['expose']['identifier'] = 'done';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'growroom/logs/movements';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Logs of movements';
  $handler->display->display_options['menu']['weight'] = '100';
  $handler->display->display_options['menu']['name'] = 'growroom';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%exposed-%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'growroom/logs/movements/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['growroom_movement_log'] = array(
    t('Master'),
    t('Logs of movements'),
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
    t('This lists all logs that define movements of assets. Multiple log types are included in this list, and are specified in the "Log type" column.'),
    t('Displaying @start - @end of @total'),
    t('No logs of movements found.'),
    t('field collection item from field_growroom_movement'),
    t('Log'),
    t('- Choose an operation -'),
    t('Delete'),
    t('Done'),
    t('Not Done'),
    t('✔'),
    t('Log ID'),
    t('.'),
    t('Date'),
    t('Assets'),
    t('Movement to'),
    t('Log name'),
    t('Log type'),
    t('Flags'),
    t('Categories'),
    t('Assigned to'),
    t('All'),
    t('%1\'s movements'),
    t('Start date'),
    t('End date'),
    t('Page'),
    t('Data export'),
  );
  $export['growroom_movement_log'] = $view;

  return $export;
}
