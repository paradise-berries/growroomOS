<?php
/**
 * @file
 * growroom_sensor.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function growroom_sensor_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_growroom_asset_sensor_pattern';
  $strongarm->value = 'growroom/sensor/[growroom_asset:name]';
  $export['pathauto_growroom_asset_sensor_pattern'] = $strongarm;

  return $export;
}
