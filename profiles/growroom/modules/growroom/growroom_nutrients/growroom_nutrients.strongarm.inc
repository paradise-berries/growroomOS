<?php
/**
 * @file
 * growroom_nutrients.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function growroom_nutrients_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_growroom_asset_nutrients_pattern';
  $strongarm->value = 'growroom/nutrients/[growroom_asset:name]';
  $export['pathauto_growroom_asset_nutrients_pattern'] = $strongarm;

  return $export;
}
