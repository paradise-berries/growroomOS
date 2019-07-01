<?php
/**
 * @file
 * growroom_photosynthesis.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_photosynthesis_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function growroom_photosynthesis_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_growroom_plan_type().
 */
function growroom_photosynthesis_default_growroom_plan_type() {
  $items = array();
  $items['photosynthesis'] = entity_import('growroom_plan_type', '{
    "type" : "photosynthesis",
    "label" : "Photosynthesis Management Plan",
    "weight" : 0,
    "rdf_mapping" : []
  }');
  return $items;
}
