<?php
/**
 * @file
 * growroom_seeds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_seeds_ctools_plugin_api($module = NULL, $api = NULL) {
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
function growroom_seeds_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_growroom_asset_type().
 */
function growroom_seeds_default_growroom_asset_type() {
  $items = array();
  $items['seeds'] = entity_import('growroom_asset_type', '{
    "type" : "seeds",
    "label" : "Seeds",
    "weight" : 0,
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_log_type().
 */
function growroom_seeds_default_log_type() {
  $items = array();
  $items['growroom_seed'] = entity_import('log_type', '{
    "type" : "growroom_seed",
    "label" : "Seed",
    "weight" : 0,
    "name_pattern" : "Seed: [log:field-growroom-asset]",
    "name_edit" : "1",
    "done" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
