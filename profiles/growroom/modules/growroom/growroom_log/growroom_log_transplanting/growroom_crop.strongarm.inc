<?php
/**
 * @file
 * growroom_crop.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function growroom_crop_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_growroom_asset_planting_pattern';
  $strongarm->value = 'growroom/planting/[growroom_asset:name]';
  $export['pathauto_growroom_asset_planting_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_growroom_crops_pattern';
  $strongarm->value = 'growroom/crop/[term:name]';
  $export['pathauto_taxonomy_term_growroom_crops_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_growroom_crop_families_pattern';
  $strongarm->value = 'growroom/crop-family/[term:name]';
  $export['pathauto_taxonomy_term_growroom_crop_families_pattern'] = $strongarm;

  return $export;
}
