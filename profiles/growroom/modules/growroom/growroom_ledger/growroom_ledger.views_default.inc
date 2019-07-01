<?php
/**
 * @file
 * growroom_ledger.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function growroom_ledger_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'growroom_log_purchase';
  $view->description = '';
  $view->tag = 'growroom_ledger';
  $view->base_table = 'log';
  $view->human_name = 'Growroom Log: Purchases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Purchases';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any growroom_purchase log entities';
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
    'name' => 'name',
    'field_growroom_asset' => 'field_growroom_asset',
    'field_growroom_seller' => 'field_growroom_seller',
    'field_growroom_invoice_number' => 'field_growroom_invoice_number',
    'field_growroom_lot_number' => 'field_growroom_lot_number',
    'field_growroom_quantity_value' => 'field_growroom_quantity_value',
    'field_growroom_quantity_units' => 'field_growroom_quantity_units',
    'field_growroom_unit_price' => 'field_growroom_unit_price',
    'field_growroom_total_price' => 'field_growroom_total_price',
    'field_growroom_notes' => 'field_growroom_notes',
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
    'name' => array(
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
    'field_growroom_seller' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_invoice_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_lot_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_quantity_value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_quantity_units' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_unit_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_total_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No purchases found.';
  /* Field: Bulk operations: Log */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_log';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
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
    'bypass_access' => 0,
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_growroom_asset']['delta_offset'] = '0';
  /* Field: Log: Seller */
  $handler->display->display_options['fields']['field_growroom_seller']['id'] = 'field_growroom_seller';
  $handler->display->display_options['fields']['field_growroom_seller']['table'] = 'field_data_field_growroom_seller';
  $handler->display->display_options['fields']['field_growroom_seller']['field'] = 'field_growroom_seller';
  /* Field: Log: Invoice number */
  $handler->display->display_options['fields']['field_growroom_invoice_number']['id'] = 'field_growroom_invoice_number';
  $handler->display->display_options['fields']['field_growroom_invoice_number']['table'] = 'field_data_field_growroom_invoice_number';
  $handler->display->display_options['fields']['field_growroom_invoice_number']['field'] = 'field_growroom_invoice_number';
  /* Field: Log: Purchase lot number */
  $handler->display->display_options['fields']['field_growroom_lot_number']['id'] = 'field_growroom_lot_number';
  $handler->display->display_options['fields']['field_growroom_lot_number']['table'] = 'field_data_field_growroom_lot_number';
  $handler->display->display_options['fields']['field_growroom_lot_number']['field'] = 'field_growroom_lot_number';
  /* Field: Field: Value */
  $handler->display->display_options['fields']['field_growroom_quantity_value']['id'] = 'field_growroom_quantity_value';
  $handler->display->display_options['fields']['field_growroom_quantity_value']['table'] = 'field_data_field_growroom_quantity_value';
  $handler->display->display_options['fields']['field_growroom_quantity_value']['field'] = 'field_growroom_quantity_value';
  $handler->display->display_options['fields']['field_growroom_quantity_value']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['field_growroom_quantity_value']['settings'] = array(
    'precision' => '0',
    'auto_precision' => 1,
  );
  /* Field: Field: Units */
  $handler->display->display_options['fields']['field_growroom_quantity_units']['id'] = 'field_growroom_quantity_units';
  $handler->display->display_options['fields']['field_growroom_quantity_units']['table'] = 'field_data_field_growroom_quantity_units';
  $handler->display->display_options['fields']['field_growroom_quantity_units']['field'] = 'field_growroom_quantity_units';
  /* Field: Log: Unit price */
  $handler->display->display_options['fields']['field_growroom_unit_price']['id'] = 'field_growroom_unit_price';
  $handler->display->display_options['fields']['field_growroom_unit_price']['table'] = 'field_data_field_growroom_unit_price';
  $handler->display->display_options['fields']['field_growroom_unit_price']['field'] = 'field_growroom_unit_price';
  $handler->display->display_options['fields']['field_growroom_unit_price']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['field_growroom_unit_price']['settings'] = array(
    'precision' => '0',
    'auto_precision' => 1,
  );
  /* Field: Log: Total price */
  $handler->display->display_options['fields']['field_growroom_total_price']['id'] = 'field_growroom_total_price';
  $handler->display->display_options['fields']['field_growroom_total_price']['table'] = 'field_data_field_growroom_total_price';
  $handler->display->display_options['fields']['field_growroom_total_price']['field'] = 'field_growroom_total_price';
  $handler->display->display_options['fields']['field_growroom_total_price']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['field_growroom_total_price']['settings'] = array(
    'precision' => '0',
    'auto_precision' => 1,
  );
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
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'log';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Log name';
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
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['title'] = '%1\'s purchases';
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
    'growroom_purchase' => 'growroom_purchase',
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
  $handler->display->display_options['path'] = 'growroom/logs/purchases';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Purchases';
  $handler->display->display_options['menu']['weight'] = '';
  $handler->display->display_options['menu']['name'] = 'growroom';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
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
  $handler->display->display_options['path'] = 'growroom/logs/purchases/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['growroom_log_purchase'] = array(
    t('Master'),
    t('Purchases'),
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
    t('No purchases found.'),
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
    t('Seller'),
    t('Invoice number'),
    t('Purchase lot number'),
    t('Units'),
    t('Unit price'),
    t('Total price'),
    t('Notes'),
    t('Flags'),
    t('Categories'),
    t('Assigned to'),
    t('All'),
    t('%1\'s purchases'),
    t('Start date'),
    t('End date'),
    t('Page'),
    t('Data export'),
  );
  $export['growroom_log_purchase'] = $view;

  $view = new view();
  $view->name = 'growroom_log_sale';
  $view->description = '';
  $view->tag = 'growroom_ledger';
  $view->base_table = 'log';
  $view->human_name = 'Growroom Log: Sales';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sales';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any growroom_sale log entities';
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
    'name' => 'name',
    'field_growroom_asset' => 'field_growroom_asset',
    'field_growroom_customer' => 'field_growroom_customer',
    'field_growroom_invoice_number' => 'field_growroom_invoice_number',
    'field_growroom_lot_number' => 'field_growroom_lot_number',
    'field_growroom_quantity_value' => 'field_growroom_quantity_value',
    'field_growroom_quantity_units' => 'field_growroom_quantity_units',
    'field_growroom_unit_price' => 'field_growroom_unit_price',
    'field_growroom_total_price' => 'field_growroom_total_price',
    'field_growroom_notes' => 'field_growroom_notes',
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
    'name' => array(
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
    'field_growroom_customer' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_invoice_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_lot_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_quantity_value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_quantity_units' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_unit_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_growroom_total_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No sales found.';
  /* Field: Bulk operations: Log */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_log';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
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
    'bypass_access' => 0,
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_growroom_asset']['delta_offset'] = '0';
  /* Field: Log: Customer */
  $handler->display->display_options['fields']['field_growroom_customer']['id'] = 'field_growroom_customer';
  $handler->display->display_options['fields']['field_growroom_customer']['table'] = 'field_data_field_growroom_customer';
  $handler->display->display_options['fields']['field_growroom_customer']['field'] = 'field_growroom_customer';
  /* Field: Log: Invoice number */
  $handler->display->display_options['fields']['field_growroom_invoice_number']['id'] = 'field_growroom_invoice_number';
  $handler->display->display_options['fields']['field_growroom_invoice_number']['table'] = 'field_data_field_growroom_invoice_number';
  $handler->display->display_options['fields']['field_growroom_invoice_number']['field'] = 'field_growroom_invoice_number';
  /* Field: Log: Sale lot number */
  $handler->display->display_options['fields']['field_growroom_lot_number']['id'] = 'field_growroom_lot_number';
  $handler->display->display_options['fields']['field_growroom_lot_number']['table'] = 'field_data_field_growroom_lot_number';
  $handler->display->display_options['fields']['field_growroom_lot_number']['field'] = 'field_growroom_lot_number';
  /* Field: Field: Value */
  $handler->display->display_options['fields']['field_growroom_quantity_value']['id'] = 'field_growroom_quantity_value';
  $handler->display->display_options['fields']['field_growroom_quantity_value']['table'] = 'field_data_field_growroom_quantity_value';
  $handler->display->display_options['fields']['field_growroom_quantity_value']['field'] = 'field_growroom_quantity_value';
  $handler->display->display_options['fields']['field_growroom_quantity_value']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['field_growroom_quantity_value']['settings'] = array(
    'precision' => '0',
    'auto_precision' => 1,
  );
  /* Field: Field: Units */
  $handler->display->display_options['fields']['field_growroom_quantity_units']['id'] = 'field_growroom_quantity_units';
  $handler->display->display_options['fields']['field_growroom_quantity_units']['table'] = 'field_data_field_growroom_quantity_units';
  $handler->display->display_options['fields']['field_growroom_quantity_units']['field'] = 'field_growroom_quantity_units';
  /* Field: Log: Unit price */
  $handler->display->display_options['fields']['field_growroom_unit_price']['id'] = 'field_growroom_unit_price';
  $handler->display->display_options['fields']['field_growroom_unit_price']['table'] = 'field_data_field_growroom_unit_price';
  $handler->display->display_options['fields']['field_growroom_unit_price']['field'] = 'field_growroom_unit_price';
  $handler->display->display_options['fields']['field_growroom_unit_price']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['field_growroom_unit_price']['settings'] = array(
    'precision' => '0',
    'auto_precision' => 1,
  );
  /* Field: Log: Total price */
  $handler->display->display_options['fields']['field_growroom_total_price']['id'] = 'field_growroom_total_price';
  $handler->display->display_options['fields']['field_growroom_total_price']['table'] = 'field_data_field_growroom_total_price';
  $handler->display->display_options['fields']['field_growroom_total_price']['field'] = 'field_growroom_total_price';
  $handler->display->display_options['fields']['field_growroom_total_price']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['field_growroom_total_price']['settings'] = array(
    'precision' => '0',
    'auto_precision' => 1,
  );
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
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'log';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Log name';
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
  $handler->display->display_options['arguments']['field_growroom_asset_target_id']['title'] = '%1\'s sales';
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
    'growroom_sale' => 'growroom_sale',
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
  $handler->display->display_options['path'] = 'growroom/logs/sales';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Sales';
  $handler->display->display_options['menu']['weight'] = '';
  $handler->display->display_options['menu']['name'] = 'growroom';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
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
  $handler->display->display_options['path'] = 'growroom/logs/sales/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['growroom_log_sale'] = array(
    t('Master'),
    t('Sales'),
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
    t('No sales found.'),
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
    t('Customer'),
    t('Invoice number'),
    t('Sale lot number'),
    t('Units'),
    t('Unit price'),
    t('Total price'),
    t('Notes'),
    t('Flags'),
    t('Categories'),
    t('Assigned to'),
    t('All'),
    t('%1\'s sales'),
    t('Start date'),
    t('End date'),
    t('Page'),
    t('Data export'),
  );
  $export['growroom_log_sale'] = $view;

  return $export;
}
