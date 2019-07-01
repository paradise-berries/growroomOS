<?php
/**
 * @file
 * growroom_equipment.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function growroom_equipment_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_growroom_asset_equipment_pattern';
  $strongarm->value = 'growroom/equipment/[growroom_asset:name]';
  $export['pathauto_growroom_asset_equipment_pattern'] = $strongarm;

  return $export;
}
