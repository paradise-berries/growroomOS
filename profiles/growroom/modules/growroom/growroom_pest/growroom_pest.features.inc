<?php
/**
 * @file
 * growroom_pest.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_pest_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function growroom_pest_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_growroom_plan_type().
 */
function growroom_pest_default_growroom_plan_type() {
  $items = array();
  $items['pest'] = entity_import('growroom_plan_type', '{
    "type" : "pest",
    "label" : "Pest Management Plan",
    "weight" : 0,
    "rdf_mapping" : []
  }');
  return $items;
}
