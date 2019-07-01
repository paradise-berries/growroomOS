<?php
/**
 * @file
 * growroom_plants.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function growroom_plants_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_growroom_asset_individual_pattern';
  $strongarm->value = 'growroom/individual/[growroom_asset:name]';
  $export['pathauto_growroom_asset_individual_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_growroom_individual_cultivars_pattern';
  $strongarm->value = 'growroom/individual/cultivar/[term:name]';
  $export['pathauto_taxonomy_term_growroom_individual_cultivars_pattern'] = $strongarm;
  return $export;
}
