<?php
/**
 * @file
 * growroom_plants.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_plants_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function growroom_plants_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_growroom_asset_type().
 */
function growroom_plants_default_growroom_asset_type() {
  $items = array();
  $items['individual'] = entity_import('growroom_asset_type', '{
    "type" : "individual",
    "label" : "Individual",
    "weight" : 0,
    "inventory" : { "enabled" : "1", "individual" : "1" },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_log_type().
 */
function growroom_plants_default_log_type() {
  $items = array();
  $items['growroom_repop'] = entity_import('log_type', '{
    "type" : "growroom_repop",
    "label" : "Repop",
    "weight" : 0,
    "name_pattern" : "Repop: [log:field-growroom-asset]",
    "name_edit" : "0",
    "done" : "1",
    "rdf_mapping" : []
  }');
  $items['growroom_treatment'] = entity_import('log_type', '{
    "type" : "growroom_treatment",
    "label" : "Treatment",
    "weight" : 0,
    "name_pattern" : "Treatment: [log:field-growroom-asset] [log:timestamp:short]",
    "name_edit" : "1",
    "done" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
