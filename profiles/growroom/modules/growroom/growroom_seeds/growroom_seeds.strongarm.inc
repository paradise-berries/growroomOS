<?php
/**
 * @file
 * growroom_seeds.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function growroom_seeds_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_growroom_asset_seeds_pattern';
  $strongarm->value = 'growroom/seeds/[growroom_asset:name]';
  $export['pathauto_growroom_asset_seeds_pattern'] = $strongarm;

  return $export;
}
