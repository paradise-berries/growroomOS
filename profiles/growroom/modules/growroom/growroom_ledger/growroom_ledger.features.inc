<?php
/**
 * @file
 * growroom_ledger.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_ledger_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function growroom_ledger_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_log_type().
 */
function growroom_ledger_default_log_type() {
  $items = array();
  $items['growroom_purchase'] = entity_import('log_type', '{
    "type" : "growroom_purchase",
    "label" : "Purchase",
    "weight" : 0,
    "name_pattern" : "[log:field-growroom-asset] [log:field-growroom-invoice-number]",
    "name_edit" : "1",
    "done" : "1",
    "rdf_mapping" : []
  }');
  $items['growroom_sale'] = entity_import('log_type', '{
    "type" : "growroom_sale",
    "label" : "Sale",
    "weight" : 0,
    "name_pattern" : "[log:field-growroom-customer] [log:field-growroom-invoice-number] [log:field-growroom-asset]",
    "name_edit" : "1",
    "done" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
