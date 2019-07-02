<?php
/**
 * @file
 * growroom_plants.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function growroom_plants_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'growroom_individual_cultivars';
  $view->description = '';
  $view->tag = 'growroom_plants';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Growroom Individual Cultivars';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cultivars';
  $handler->display->display_options['css_class'] = 'views-tree';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any individual growroom assets';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'tree';
  $handler->display->display_options['style_options']['main_field'] = 'tid';
  $handler->display->display_options['style_options']['parent_field'] = 'tid_1';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'id' => 'id',
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h4>Hierarchy <small><a href="/admin/structure/taxonomy/growroom_individual_cultivars?destination=growroom/assets/individuals/cultivars">(change)</a></small></h4>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No cultivars found.';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Relationship: Taxonomy term: Growroom asset using Cultivars */
  $handler->display->display_options['relationships']['reverse_field_growroom_individual_cultivar_growroom_asset']['id'] = 'reverse_field_growroom_individual_cultivar_growroom_asset';
  $handler->display->display_options['relationships']['reverse_field_growroom_individual_cultivar_growroom_asset']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_growroom_individual_cultivar_growroom_asset']['field'] = 'reverse_field_growroom_individual_cultivar_growroom_asset';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['tid_1']['label'] = 'Parent Term ID';
  $handler->display->display_options['fields']['tid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid_1']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: COUNT(Growroom asset: Growroom asset ID) */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['relationship'] = 'reverse_field_growroom_individual_cultivar_growroom_asset';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  $handler->display->display_options['fields']['id']['prefix'] = '(';
  $handler->display->display_options['fields']['id']['suffix'] = ')';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'growroom_individual_cultivars' => 'growroom_individual_cultivars',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'growroom/assets/individuals/cultivars';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Cultivars';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'growroom';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['growroom_individual_cultivars'] = array(
    t('Master'),
    t('Individual Cultivars'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h4>Hierarchy <small><a href="/admin/structure/taxonomy/growroom_individual_cultivars?destination=growroom/assets/individuals/cultivars">(change)</a></small></h4>'),
    t('No cultivars found.'),
    t('Parent'),
    t('field_growroom_individual_cultivar'),
    t('Term ID'),
    t('.'),
    t('Parent Term ID'),
    t(','),
    t('('),
    t(')'),
    t('Page'),
  );
  $export['growroom_individual_cultivars'] = $view;
  
  $view = new view();
  $view->name = 'growroom_individual_alias';
  $view->description = '';
  $view->tag = 'growroom_plants';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Growroom Individual Alias';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Alias';
  $handler->display->display_options['css_class'] = 'views-tree';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any individual growroom assets';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'tree';
  $handler->display->display_options['style_options']['main_field'] = 'tid';
  $handler->display->display_options['style_options']['parent_field'] = 'tid_1';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'id' => 'id',
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h4>Hierarchy <small><a href="/admin/structure/taxonomy/growroom_individual_alias?destination=growroom/assets/individuals/alias">(change)</a></small></h4>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No alias found.';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Relationship: Taxonomy term: Growroom asset using Alias */
  $handler->display->display_options['relationships']['reverse_field_growroom_individual_alias_growroom_asset']['id'] = 'reverse_field_growroom_individual_alias_growroom_asset';
  $handler->display->display_options['relationships']['reverse_field_growroom_individual_alias_growroom_asset']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_growroom_individual_alias_growroom_asset']['field'] = 'reverse_field_growroom_individual_alias_growroom_asset';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['tid_1']['label'] = 'Parent Term ID';
  $handler->display->display_options['fields']['tid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid_1']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: COUNT(Growroom asset: Growroom asset ID) */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['relationship'] = 'reverse_field_growroom_individual_alias_growroom_asset';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  $handler->display->display_options['fields']['id']['prefix'] = '(';
  $handler->display->display_options['fields']['id']['suffix'] = ')';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'growroom_individual_alias' => 'growroom_individual_alias',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'growroom/assets/individuals/alias';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Alias';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'growroom';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['growroom_individual_alias'] = array(
    t('Master'),
    t('Individual Alias'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h4>Hierarchy <small><a href="/admin/structure/taxonomy/growroom_individual_alias?destination=growroom/assets/individuals/alias">(change)</a></small></h4>'),
    t('No alias found.'),
    t('Parent'),
    t('field_growroom_individual_alias'),
    t('Term ID'),
    t('.'),
    t('Parent Term ID'),
    t(','),
    t('('),
    t(')'),
    t('Page'),
  );
  $export['growroom_individual_alias'] = $view;
  
  $view = new view();
  $view->name = 'growroom_individuals';
  $view->description = '';
  $view->tag = 'growroom_plants';
  $view->base_table = 'growroom_asset';
  $view->human_name = 'Growroom Individuals';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Individuals';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any individual growroom assets';
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
    'field_growroom_individual_cultivars' => 'field_growroom_individual_cultivar',
    'field_growroom_individual_alias' => 'field_growroom_individual_alias',
    'field_growroom_date' => 'field_growroom_date',
    'field_growroom_move_to' => 'field_growroom_move_to',
    'field_growroom_individual_origin' => 'field_growroom_individual_origin',
    'field_growroom_individual_source' => 'field_growroom_source',
    'field_growroom_individual_fertility' => 'field_growroom_individual_fertility',
    'field_growroom_description' => 'field_growroom_description',
    'inventory' => 'inventory',
    'field_growroom_images' => 'field_growroom_images',
    'field_growroom_flags' => 'field_growroom_flags',
    'field_growroom_group' => 'field_growroom_group',
    'id' => 'id',
    'archived' => 'archived',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
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
    'field_growroom_individual_cultivar' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_individual_alias' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_move_to' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
     'field_growroom_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_individual_origin' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_source' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_individual_fertility' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
     ),
       'inventory' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_images' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_flags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_group' => array(
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
    'id' => array(
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
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No individuals found.';
  /* Relationship: Growroom asset: Latest movement */
  $handler->display->display_options['relationships']['latest_movement']['id'] = 'latest_movement';
  $handler->display->display_options['relationships']['latest_movement']['table'] = 'growroom_asset';
  $handler->display->display_options['relationships']['latest_movement']['field'] = 'latest_movement';
  /* Relationship: Growroom asset: Group membership */
  $handler->display->display_options['relationships']['membership']['id'] = 'membership';
  $handler->display->display_options['relationships']['membership']['table'] = 'growroom_asset';
  $handler->display->display_options['relationships']['membership']['field'] = 'membership';
  /* Field: Bulk operations: Growroom asset */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_growroom_asset';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::growroom_log_asset_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::growroom_asset_archive_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::growroom_asset_clone_action' => array(
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
    'action::growroom_group_asset_membership_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::growroom_movement_asset_move_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::growroom_asset_unarchive_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::growroom_plants_weight_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Growroom asset: Growroom asset ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Asset ID';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Field: Photos */
  $handler->display->display_options['fields']['field_growroom_images']['id'] = 'field_growroom_images';
  $handler->display->display_options['fields']['field_growroom_images']['table'] = 'field_data_field_growroom_images';
  $handler->display->display_options['fields']['field_growroom_images']['field'] = 'field_growroom_images';
  $handler->display->display_options['fields']['field_growroom_images']['label'] = '';
  $handler->display->display_options['fields']['field_growroom_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_growroom_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_growroom_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_growroom_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_growroom_images']['delta_offset'] = '0';
  /* Field: Growroom asset: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'growroom/asset/[id]';
  /* Field: Growroom asset: Cultivar */
  $handler->display->display_options['fields']['field_growroom_individual_cultivar']['id'] = 'field_growroom_individual_cultivar';
  $handler->display->display_options['fields']['field_growroom_individual_cultivar']['table'] = 'field_data_field_growroom_individual_cultivar';
  $handler->display->display_options['fields']['field_growroom_individual_cultivar']['field'] = 'field_growroom_individual_cultivar';
  /* Field: Growroom asset: Alias */
  $handler->display->display_options['fields']['field_growroom_individual_alias']['id'] = 'field_growroom_individual_alias';
  $handler->display->display_options['fields']['field_growroom_individual_alias']['table'] = 'field_data_field_growroom_individual_alias';
  $handler->display->display_options['fields']['field_growroom_individual_alias']['field'] = 'field_growroom_individual_alias';
  /* Field: Growroom asset: Repop date */
  $handler->display->display_options['fields']['field_growroom_date']['id'] = 'field_growroom_date';
  $handler->display->display_options['fields']['field_growroom_date']['table'] = 'field_data_field_growroom_date';
  $handler->display->display_options['fields']['field_growroom_date']['field'] = 'field_growroom_date';
  $handler->display->display_options['fields']['field_growroom_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Growroom asset: Origin */
  $handler->display->display_options['fields']['field_growroom_individual_origin']['id'] = 'field_growroom_individual_origin';
  $handler->display->display_options['fields']['field_growroom_individual_origin']['table'] = 'field_data_field_growroom_individual_origin';
  $handler->display->display_options['fields']['field_growroom_individual_origin']['field'] = 'field_growroom_individual_origin';
  /* Field: Growroom asset: Fertility */
  $handler->display->display_options['fields']['field_growroom_individual_fertility']['id'] = 'field_growroom_individual_fertility';
  $handler->display->display_options['fields']['field_growroom_individual_fertility']['table'] = 'field_data_field_growroom_individual_fertility';
  $handler->display->display_options['fields']['field_growroom_individual_fertility']['field'] = 'field_growroom_individual_fertility';
  /* Field: Growroom asset: Source */
  $handler->display->display_options['fields']['field_growroom_source']['id'] = 'field_growroom_source';
  $handler->display->display_options['fields']['field_growroom_source']['table'] = 'field_data_field_growroom_source';
  $handler->display->display_options['fields']['field_growroom_source']['field'] = 'field_growroom_source'; 
  /* Field: Growroom asset: Description */
  $handler->display->display_options['fields']['field_growroom_description']['id'] = 'field_growroom_description';
  $handler->display->display_options['fields']['field_growroom_description']['table'] = 'field_data_field_growroom_description';
  $handler->display->display_options['fields']['field_growroom_description']['field'] = 'field_growroom_description';
  $handler->display->display_options['fields']['field_growroom_description']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_growroom_description']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['field_growroom_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_growroom_description']['alter']['trim'] = TRUE;
  /* Field: Growroom asset: Asset inventory value */
  $handler->display->display_options['fields']['inventory']['id'] = 'inventory';
  $handler->display->display_options['fields']['inventory']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['inventory']['field'] = 'inventory';
  $handler->display->display_options['fields']['inventory']['label'] = 'Inventory';
  /* Field: Field: Flags */
  $handler->display->display_options['fields']['field_growroom_flags']['id'] = 'field_growroom_flags';
  $handler->display->display_options['fields']['field_growroom_flags']['table'] = 'field_data_field_growroom_flags';
  $handler->display->display_options['fields']['field_growroom_flags']['field'] = 'field_growroom_flags';
  $handler->display->display_options['fields']['field_growroom_flags']['delta_offset'] = '0';
  /* Field: Field collection item: Group */
  $handler->display->display_options['fields']['field_growroom_group']['id'] = 'field_growroom_group';
  $handler->display->display_options['fields']['field_growroom_group']['table'] = 'field_data_field_growroom_group';
  $handler->display->display_options['fields']['field_growroom_group']['field'] = 'field_growroom_group';
  $handler->display->display_options['fields']['field_growroom_group']['relationship'] = 'membership';
  $handler->display->display_options['fields']['field_growroom_group']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_growroom_group']['delta_offset'] = '0';
  /* Field: Field collection item: Movement to */
  $handler->display->display_options['fields']['field_growroom_move_to']['id'] = 'field_growroom_move_to';
  $handler->display->display_options['fields']['field_growroom_move_to']['table'] = 'field_data_field_growroom_move_to';
  $handler->display->display_options['fields']['field_growroom_move_to']['field'] = 'field_growroom_move_to';
  $handler->display->display_options['fields']['field_growroom_move_to']['relationship'] = 'latest_movement';
  $handler->display->display_options['fields']['field_growroom_move_to']['label'] = 'Location';
  /* Field: Growroom asset: Archived */
  $handler->display->display_options['fields']['archived']['id'] = 'archived';
  $handler->display->display_options['fields']['archived']['table'] = 'growroom_asset';
  $handler->display->display_options['fields']['archived']['field'] = 'archived';
  $handler->display->display_options['fields']['archived']['date_format'] = 'custom';
  $handler->display->display_options['fields']['archived']['custom_date_format'] = 'm j y';
  $handler->display->display_options['fields']['archived']['second_date_format'] = 'long';
  /* Sort criterion: Growroom asset: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'growroom_asset';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Name';
  /* Sort criterion: Growroom asset: Repop date (field_growroom_date) */
  $handler->display->display_options['sorts']['field_growroom_date_value']['id'] = 'field_growroom_date_value';
  $handler->display->display_options['sorts']['field_growroom_date_value']['table'] = 'field_data_field_growroom_date';
  $handler->display->display_options['sorts']['field_growroom_date_value']['field'] = 'field_growroom_date_value';
  $handler->display->display_options['sorts']['field_growroom_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_growroom_date_value']['expose']['label'] = 'Repop Date';
  /* Sort criterion: Growroom asset: Cultivars (field_growroom_individual_cultivar) */
  $handler->display->display_options['sorts']['field_growroom_individual_cultivar_tid']['id'] = 'field_growroom_individual_cultivar_tid';
  $handler->display->display_options['sorts']['field_growroom_individual_cultivar_tid']['table'] = 'field_data_field_growroom_individual_cultivar';
  $handler->display->display_options['sorts']['field_growroom_individual_cultivar_tid']['field'] = 'field_growroom_individual_cultivar_tid';
  $handler->display->display_options['sorts']['field_growroom_individual_cultivar_tid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_growroom_individual_cultivar_tid']['expose']['label'] = 'Cultivar';
  /* Sort criterion: Growroom asset: Alias (field_growroom_individual_alias) */
  $handler->display->display_options['sorts']['field_growroom_individual_alias_tid']['id'] = 'field_growroom_individual_alias_tid';
  $handler->display->display_options['sorts']['field_growroom_individual_alias_tid']['table'] = 'field_data_field_growroom_individual_alias';
  $handler->display->display_options['sorts']['field_growroom_individual_alias_tid']['field'] = 'field_growroom_individual_alias_tid';
  $handler->display->display_options['sorts']['field_growroom_individual_alias_tid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_growroom_individual_alias_tid']['expose']['label'] = 'Alias';
  /* Sort criterion: Growroom asset: origin (field_growroom_individual_origin) */
  $handler->display->display_options['sorts']['field_growroom_individual_origin_value']['id'] = 'field_growroom_individual_origin_value';
  $handler->display->display_options['sorts']['field_growroom_individual_origin_value']['table'] = 'field_data_field_growroom_individual_origin';
  $handler->display->display_options['sorts']['field_growroom_individual_origin_value']['field'] = 'field_growroom_individual_origin_value';
  $handler->display->display_options['sorts']['field_growroom_individual_origin_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_growroom_individual_origin_value']['expose']['label'] = 'Origin';
    /* Sort criterion: Growroom asset: fertility (field_growroom_individual_fertility) */
  $handler->display->display_options['sorts']['field_growroom_individual_fertility_value']['id'] = 'field_growroom_individual_fertility_value';
  $handler->display->display_options['sorts']['field_growroom_individual_fertility_value']['table'] = 'field_data_field_growroom_individual_fertility';
  $handler->display->display_options['sorts']['field_growroom_individual_fertility_value']['field'] = 'field_growroom_individual_fertility_value';
  $handler->display->display_options['sorts']['field_growroom_individual_fertility_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_growroom_individual_fertility_value']['expose']['label'] = 'Fertility';
  /* Contextual filter: Field collection item: Movement to (field_growroom_move_to) */
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['id'] = 'field_growroom_move_to_tid';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['table'] = 'field_data_field_growroom_move_to';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['field'] = 'field_growroom_move_to_tid';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['relationship'] = 'latest_movement';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['title'] = 'Individuals in %1';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_growroom_move_to_tid']['validate_options']['vocabularies'] = array(
    'growroom_areas' => 'growroom_areas',
  );
  /* Contextual filter: Growroom asset: Cultivar (field_growroom_individual_cultivar) */
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['id'] = 'field_growroom_individual_cultivar_tid';
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['table'] = 'field_data_field_growroom_individual_cultivar';
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['field'] = 'field_growroom_individual_cultivar_tid';
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['title'] = 'Individuals of cultivar %2';
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_growroom_individual_cultivar_tid']['validate_options']['vocabularies'] = array(
    'growroom_individual_cultivars' => 'growroom_individual_cultivars',
  );
  /* Contextual filter: Growroom asset: Cultivar (field_growroom_individual_alias) */
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['id'] = 'field_growroom_individual_alias_tid';
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['table'] = 'field_data_field_growroom_individual_alias';
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['field'] = 'field_growroom_individual_alias_tid';
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['title'] = 'Individuals of alias %2';
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_growroom_individual_alias_tid']['validate_options']['vocabularies'] = array(
    'growroom_individual_alias' => 'growroom_individual_alias',
  );
  /* Filter criterion: Growroom asset: Growroom asset type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'growroom_asset';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'individual' => 'individual',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  /* Filter criterion: Growroom asset: Cultivar (field_growroom_individual_cultivar) */
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['id'] = 'field_growroom_individual_cultivar_tid';
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['table'] = 'field_data_field_growroom_individual_cultivar';
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['field'] = 'field_growroom_individual_cultivar_tid';
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['expose']['operator_id'] = 'field_growroom_individual_cultivar_tid_op';
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['expose']['label'] = 'Cultivars';
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['expose']['operator'] = 'field_growroom_individual_cultivar_tid_op';
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['expose']['identifier'] = 'field_growroom_individual_cultivar_tid';
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['vocabulary'] = 'growroom_individual_cultivars';
  $handler->display->display_options['filters']['field_growroom_individual_cultivar_tid']['hierarchy'] = 1;
  /* Filter criterion: Growroom asset: Alias (field_growroom_individual_alias) */
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['id'] = 'field_growroom_individual_alias_tid';
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['table'] = 'field_data_field_growroom_individual_alias';
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['field'] = 'field_growroom_individual_alias_tid';
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['expose']['operator_id'] = 'field_growroom_individual_alias_tid_op';
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['expose']['label'] = 'Alias';
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['expose']['operator'] = 'field_growroom_individual_alias_tid_op';
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['expose']['identifier'] = 'field_growroom_individual_alias_tid';
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['vocabulary'] = 'growroom_individual_alias';
  $handler->display->display_options['filters']['field_growroom_individual_alias_tid']['hierarchy'] = 1;
  /* Filter criterion: Growroom asset: origin (field_growroom_individual_origin) */
  $handler->display->display_options['filters']['field_growroom_individual_origin_value']['id'] = 'field_growroom_individual_origin_value';
  $handler->display->display_options['filters']['field_growroom_individual_origin_value']['table'] = 'field_data_field_growroom_individual_origin';
  $handler->display->display_options['filters']['field_growroom_individual_origin_value']['field'] = 'field_growroom_individual_origin_value';
  $handler->display->display_options['filters']['field_growroom_individual_origin_value']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_individual_origin_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_individual_origin_value']['expose']['operator_id'] = 'field_growroom_individual_origin_value_op';
  $handler->display->display_options['filters']['field_growroom_individual_origin_value']['expose']['label'] = 'Origin';
  $handler->display->display_options['filters']['field_growroom_individual_origin_value']['expose']['operator'] = 'field_growroom_individual_origin_value_op';
  $handler->display->display_options['filters']['field_growroom_individual_origin_value']['expose']['identifier'] = 'field_growroom_individual_origin_value';
  /* Filter criterion: Growroom asset: Source (field_growroom_individual_source) */
  $handler->display->display_options['filters']['field_growroom_individual_source_value']['id'] = 'field_growroom_individual_source_value';
  $handler->display->display_options['filters']['field_growroom_individual_source_value']['table'] = 'field_data_field_growroom_source';
  $handler->display->display_options['filters']['field_growroom_individual_source_value']['field'] = 'field_growroom_source_value';
  $handler->display->display_options['filters']['field_growroom_individual_source_value']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_individual_source_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_individual_source_value']['expose']['operator_id'] = 'field_growroom_source_value_op';
  $handler->display->display_options['filters']['field_growroom_individual_source_value']['expose']['label'] = 'Fertility';
  $handler->display->display_options['filters']['field_growroom_individual_source_value']['expose']['operator'] = 'field_growroom_source_value_op';
  $handler->display->display_options['filters']['field_growroom_individual_source_value']['expose']['identifier'] = 'field_growroom_source_value';
  /* Filter criterion: Growroom asset: Fertility (field_growroom_individual_fertility) */
  $handler->display->display_options['filters']['field_growroom_individual_fertility_value']['id'] = 'field_growroom_individual_fertility_value';
  $handler->display->display_options['filters']['field_growroom_individual_fertility_value']['table'] = 'field_data_field_growroom_individual_fertility';
  $handler->display->display_options['filters']['field_growroom_individual_fertility_value']['field'] = 'field_growroom_individual_fertility_value';
  $handler->display->display_options['filters']['field_growroom_individual_fertility_value']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_individual_fertility_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_individual_fertility_value']['expose']['operator_id'] = 'field_growroom_individual_fertility_value_op';
  $handler->display->display_options['filters']['field_growroom_individual_fertility_value']['expose']['label'] = 'Fertility';
  $handler->display->display_options['filters']['field_growroom_individual_fertility_value']['expose']['operator'] = 'field_growroom_individual_fertility_value_op';
  $handler->display->display_options['filters']['field_growroom_individual_fertility_value']['expose']['identifier'] = 'field_growroom_individual_fertility_value';
  /* Filter criterion: Growroom asset: Repop date (field_growroom_date) */
  $handler->display->display_options['filters']['field_growroom_date_value']['id'] = 'field_growroom_date_value';
  $handler->display->display_options['filters']['field_growroom_date_value']['table'] = 'field_data_field_growroom_date';
  $handler->display->display_options['filters']['field_growroom_date_value']['field'] = 'field_growroom_date_value';
  $handler->display->display_options['filters']['field_growroom_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_growroom_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_date_value']['expose']['operator_id'] = 'field_growroom_date_value_op';
  $handler->display->display_options['filters']['field_growroom_date_value']['expose']['label'] = 'Repop Date (range)';
  $handler->display->display_options['filters']['field_growroom_date_value']['expose']['operator'] = 'field_growroom_date_value_op';
  $handler->display->display_options['filters']['field_growroom_date_value']['expose']['identifier'] = 'field_growroom_date_value';
  $handler->display->display_options['filters']['field_growroom_date_value']['year_range'] = '-10:+3';
  /* Filter criterion: Field collection item: Movement to (field_growroom_move_to) */
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['id'] = 'field_growroom_move_to_tid';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['table'] = 'field_data_field_growroom_move_to';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['field'] = 'field_growroom_move_to_tid';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['relationship'] = 'latest_movement';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['expose']['operator_id'] = 'field_growroom_move_to_tid_op';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['expose']['operator'] = 'field_growroom_move_to_tid_op';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['expose']['identifier'] = 'field_growroom_move_to_tid';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['vocabulary'] = 'growroom_areas';
  $handler->display->display_options['filters']['field_growroom_move_to_tid']['hierarchy'] = 1;
  /* Filter criterion: Field collection item: Group (field_growroom_group) */
  $handler->display->display_options['filters']['field_growroom_group_target_id']['id'] = 'field_growroom_group_target_id';
  $handler->display->display_options['filters']['field_growroom_group_target_id']['table'] = 'field_data_field_growroom_group';
  $handler->display->display_options['filters']['field_growroom_group_target_id']['field'] = 'field_growroom_group_target_id';
  $handler->display->display_options['filters']['field_growroom_group_target_id']['relationship'] = 'membership';
  $handler->display->display_options['filters']['field_growroom_group_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_group_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_group_target_id']['expose']['operator_id'] = 'field_growroom_group_target_id_op';
  $handler->display->display_options['filters']['field_growroom_group_target_id']['expose']['label'] = 'Group';
  $handler->display->display_options['filters']['field_growroom_group_target_id']['expose']['operator'] = 'field_growroom_group_target_id_op';
  $handler->display->display_options['filters']['field_growroom_group_target_id']['expose']['identifier'] = 'field_growroom_group_target_id';
  $handler->display->display_options['filters']['field_growroom_group_target_id']['expose']['multiple'] = TRUE;
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
  /* Filter criterion: Growroom asset: Archived (boolean) */
  $handler->display->display_options['filters']['archived_boolean']['id'] = 'archived_boolean';
  $handler->display->display_options['filters']['archived_boolean']['table'] = 'growroom_asset';
  $handler->display->display_options['filters']['archived_boolean']['field'] = 'archived_boolean';
  $handler->display->display_options['filters']['archived_boolean']['value'] = '0';
  $handler->display->display_options['filters']['archived_boolean']['group'] = 1;
  $handler->display->display_options['filters']['archived_boolean']['exposed'] = TRUE;
  $handler->display->display_options['filters']['archived_boolean']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['archived_boolean']['expose']['label'] = 'Archived';
  $handler->display->display_options['filters']['archived_boolean']['expose']['operator'] = 'archived_boolean_op';
  $handler->display->display_options['filters']['archived_boolean']['expose']['identifier'] = 'archived_boolean';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'growroom/assets/individuals/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Individuals';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'growroom';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Individuals';
  $handler->display->display_options['tab_options']['weight'] = '10';
  $handler->display->display_options['tab_options']['name'] = 'growroom';

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
  $handler->display->display_options['path'] = 'growroom/assets/individuals/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['growroom_individuals'] = array(
    t('Master'),
    t('Individuals'),
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
    t('No individuals found.'),
    t('Latest movement'),
    t('Group membership'),
    t('Growroom asset'),
    t('- Choose an operation -'),
    t('Delete'),
    t('Asset ID'),
    t('.'),
    t('Name'),
    t('Cultivars'),
    t('Alias'),
    t('Repop date'),
    t('Origin'),
    t('Source'),
    t('Fertility'),
    t('Inventory'),
    t('Description'),
    t('Flags'),
    t('Group'),
    t('Location'),
    t('Archived'),
    t('All'),
    t('Individual in %1'),
    t('Individual of Cultivars %2'),
    t('Individual of Alias %2'),
    t('Repop date (range)'),
    t('Page'),
    t('Data export'),
  );
  $export['growroom_individuals'] = $view;

  $view = new view();
  $view->name = 'growroom_log_repop';
  $view->description = '';
  $view->tag = 'growroom_log';
  $view->base_table = 'log';
  $view->human_name = 'Growroom Log: Repop';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Repops';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any growroom_repop log entities';
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

    'name' => 'name',
    'timestamp' => 'timestamp',
    'field_growroom_individual_mother' => 'field_growroom_individual_mother',
    'field_growroom_asset' => 'field_growroom_asset',
    'field_growroom_area' => 'field_growroom_area',
    'field_growroom_notes' => 'field_growroom_notes',
    'field_growroom_flags' => 'field_growroom_flags',
    'field_growroom_log_category' => 'field_growroom_log_category',
    'field_growroom_log_owner' => 'field_growroom_log_owner',
    'id' => 'id',
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
    'timestamp' => array(
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
    'field_growroom_individual_mother' => array(
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
    'field_growroom_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_notes' => array(
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
    'id' => array(
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
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No repop logs found.';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_growroom_individual_mother_target_id']['id'] = 'field_growroom_individual_mother_target_id';
  $handler->display->display_options['relationships']['field_growroom_individual_mother_target_id']['table'] = 'field_data_field_growroom_individual_mother';
  $handler->display->display_options['relationships']['field_growroom_individual_mother_target_id']['field'] = 'field_growroom_individual_mother_target_id';
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
  /* Field: Log: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'log';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Log name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'log/[id]';
  /* Field: Log: Mother */
  $handler->display->display_options['fields']['field_growroom_individual_mother']['id'] = 'field_growroom_individual_mother';
  $handler->display->display_options['fields']['field_growroom_individual_mother']['table'] = 'field_data_field_growroom_individual_mother';
  $handler->display->display_options['fields']['field_growroom_individual_mother']['field'] = 'field_growroom_individual_mother';
  $handler->display->display_options['fields']['field_growroom_individual_mother']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  /* Field: Log: Assets */
  $handler->display->display_options['fields']['field_growroom_asset']['id'] = 'field_growroom_asset';
  $handler->display->display_options['fields']['field_growroom_asset']['table'] = 'field_data_field_growroom_asset';
  $handler->display->display_options['fields']['field_growroom_asset']['field'] = 'field_growroom_asset';
  $handler->display->display_options['fields']['field_growroom_asset']['label'] = 'Offspring';
  $handler->display->display_options['fields']['field_growroom_asset']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_growroom_asset']['delta_offset'] = '0';
  /* Field: Log: Areas */
  $handler->display->display_options['fields']['field_growroom_area']['id'] = 'field_growroom_area';
  $handler->display->display_options['fields']['field_growroom_area']['table'] = 'field_data_field_growroom_area';
  $handler->display->display_options['fields']['field_growroom_area']['field'] = 'field_growroom_area';
  /* Field: Log: Notes */
  $handler->display->display_options['fields']['field_growroom_notes']['id'] = 'field_growroom_notes';
  $handler->display->display_options['fields']['field_growroom_notes']['table'] = 'field_data_field_growroom_notes';
  $handler->display->display_options['fields']['field_growroom_notes']['field'] = 'field_growroom_notes';
  $handler->display->display_options['fields']['field_growroom_notes']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_growroom_notes']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['field_growroom_notes']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_growroom_notes']['alter']['trim'] = TRUE;
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
  $handler->display->display_options['sorts']['name_1']['id'] = 'name_1';
  $handler->display->display_options['sorts']['name_1']['table'] = 'log';
  $handler->display->display_options['sorts']['name_1']['field'] = 'name';
  $handler->display->display_options['sorts']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name_1']['expose']['label'] = 'Log name';
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
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['title'] = '%1\'s Repop';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['validate']['type'] = 'growroom_asset';
  /* Contextual filter: Log: Areas (field_growroom_area) */
  $handler->display->display_options['arguments']['field_growroom_area_tid']['id'] = 'field_growroom_area_tid';
  $handler->display->display_options['arguments']['field_growroom_area_tid']['table'] = 'field_data_field_growroom_area';
  $handler->display->display_options['arguments']['field_growroom_area_tid']['field'] = 'field_growroom_area_tid';
  $handler->display->display_options['arguments']['field_growroom_area_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_area_tid']['title'] = 'Repops in %2';
  $handler->display->display_options['arguments']['field_growroom_area_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_growroom_area_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_growroom_area_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_growroom_area_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_growroom_area_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_area_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_growroom_area_tid']['validate_options']['vocabularies'] = array(
    'growroom_areas' => 'growroom_areas',
  );
  /* Contextual filter: Log: Mother (field_growroom_individual_mother) */
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['id'] = 'field_growroom_individual_mother_target_id';
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['table'] = 'field_data_field_growroom_individual_mother';
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['field'] = 'field_growroom_individual_mother_target_id';
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['title'] = 'Repops by %3';
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['validate']['type'] = 'growroom_asset';
  $handler->display->display_options['arguments']['field_growroom_individual_mother_target_id']['validate_options']['types'] = array(
    'individual' => 'individual',
  );
  /* Filter criterion: Log: Log type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'log';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'growroom_repop' => 'growroom_repop',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Growroom asset: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'growroom_asset';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'field_growroom_individual_mother_target_id';
  $handler->display->display_options['filters']['name_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['name_1']['group'] = 1;
  $handler->display->display_options['filters']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_1']['expose']['operator_id'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['label'] = 'Mother';
  $handler->display->display_options['filters']['name_1']['expose']['operator'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['identifier'] = 'name_1';
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
  /* Filter criterion: Log: Areas (field_growroom_area) */
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
  /* Filter criterion: Log: Assigned to (field_growroom_log_owner) */
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['id'] = 'field_growroom_log_owner_target_id';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['table'] = 'field_data_field_growroom_log_owner';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['field'] = 'field_growroom_log_owner_target_id';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['expose']['operator_id'] = 'field_growroom_log_owner_target_id_op';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['expose']['label'] = 'Assigned to';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['expose']['operator'] = 'field_growroom_log_owner_target_id_op';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['expose']['identifier'] = 'field_growroom_log_owner_target_id';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['expose']['multiple'] = TRUE;
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
  $handler->display->display_options['path'] = 'growroom/logs/repops';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Repops';
  $handler->display->display_options['menu']['weight'] = '';
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
  $handler->display->display_options['path'] = 'growroom/logs/repops/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['growroom_log_repop'] = array(
    t('Master'),
    t('Repops'),
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
    t('No repop logs found.'),
    t('Growroom asset entity referenced from field_growroom_individual_mother'),
    t('Log'),
    t('- Choose an operation -'),
    t('Delete'),
    t('Done'),
    t('Not Done'),
    t('✔'),
    t('Log ID'),
    t('.'),
    t('Date'),
    t('Log name'),
    t('Mother'),
    t('Offspring'),
    t('Areas'),
    t('Notes'),
    t('Flags'),
    t('Categories'),
    t('Assigned to'),
    t('All'),
    t('%1\'s Repop'),
    t('Repops in %2'),
    t('Repops by %3'),
    t('Start date'),
    t('End date'),
    t('Page'),
    t('Data export'),
  );
  $export['growroom_log_repop'] = $view;

  $view = new view();
  $view->name = 'growroom_log_treatment';
  $view->description = '';
  $view->tag = 'growroom_log';
  $view->base_table = 'log';
  $view->human_name = 'Growroom Log: Treatment';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Treatment Records';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any growroom_treatment log entities';
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
    'name' => 'name',
    'timestamp' => 'timestamp',
    'field_growroom_asset' => 'field_growroom_asset',
    'field_growroom_notes' => 'field_growroom_notes',
    'field_growroom_flags' => 'field_growroom_flags',
    'field_growroom_log_category' => 'field_growroom_log_category',
    'field_growroom_log_owner' => 'field_growroom_log_owner',
    'id' => 'id',
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
    'name' => array(
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
    'field_growroom_notes' => array(
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
    'id' => array(
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
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No treatment logs found.';
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
  /* Field: Log: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'log';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Log name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'log/[id]';
  /* Field: Log: Assets */
  $handler->display->display_options['fields']['field_growroom_asset']['id'] = 'field_growroom_asset';
  $handler->display->display_options['fields']['field_growroom_asset']['table'] = 'field_data_field_growroom_asset';
  $handler->display->display_options['fields']['field_growroom_asset']['field'] = 'field_growroom_asset';
  $handler->display->display_options['fields']['field_growroom_asset']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_growroom_asset']['delta_offset'] = '0';
  /* Field: Log: Notes */
  $handler->display->display_options['fields']['field_growroom_notes']['id'] = 'field_growroom_notes';
  $handler->display->display_options['fields']['field_growroom_notes']['table'] = 'field_data_field_growroom_notes';
  $handler->display->display_options['fields']['field_growroom_notes']['field'] = 'field_growroom_notes';
  $handler->display->display_options['fields']['field_growroom_notes']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_growroom_notes']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['field_growroom_notes']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_growroom_notes']['alter']['trim'] = TRUE;
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
  $handler->display->display_options['sorts']['name_1']['id'] = 'name_1';
  $handler->display->display_options['sorts']['name_1']['table'] = 'log';
  $handler->display->display_options['sorts']['name_1']['field'] = 'name';
  $handler->display->display_options['sorts']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name_1']['expose']['label'] = 'Log name';
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
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['title'] = 'Treatment records for %1';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['validate']['type'] = 'growroom_asset';
  /* Filter criterion: Log: Log type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'log';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'growroom_treatment' => 'growroom_treatment',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  /* Filter criterion: Log: Assigned to (field_growroom_log_owner) */
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['id'] = 'field_growroom_log_owner_target_id';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['table'] = 'field_data_field_growroom_log_owner';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['field'] = 'field_growroom_log_owner_target_id';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['expose']['operator_id'] = 'field_growroom_log_owner_target_id_op';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['expose']['label'] = 'Assigned to';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['expose']['operator'] = 'field_growroom_log_owner_target_id_op';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['expose']['identifier'] = 'field_growroom_log_owner_target_id';
  $handler->display->display_options['filters']['field_growroom_log_owner_target_id']['expose']['multiple'] = TRUE;
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
  $handler->display->display_options['path'] = 'growroom/logs/treatment';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Treatment';
  $handler->display->display_options['menu']['weight'] = '';
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
  $handler->display->display_options['path'] = 'growroom/logs/treatment/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['growroom_log_treatment'] = array(
    t('Master'),
    t('Treatment Records'),
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
    t('No treatment logs found.'),
    t('Log'),
    t('- Choose an operation -'),
    t('Delete'),
    t('Done'),
    t('Not Done'),
    t('✔'),
    t('Log ID'),
    t('.'),
    t('Date'),
    t('Log name'),
    t('Assets'),
    t('Notes'),
    t('Flags'),
    t('Categories'),
    t('Assigned to'),
    t('All'),
    t('Treatment records for %1'),
    t('Start date'),
    t('End date'),
    t('Page'),
    t('Data export'),
  );
  $export['growroom_log_treatment'] = $view;

  return $export;
}
