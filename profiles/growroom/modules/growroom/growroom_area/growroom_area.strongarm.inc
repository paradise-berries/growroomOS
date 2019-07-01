<?php
/**
 * @file
 * growroom_area.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function growroom_area_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_growroom_areas_pattern';
  $strongarm->value = 'growroom/area/[term:name]';
  $export['pathauto_taxonomy_term_growroom_areas_pattern'] = $strongarm;

  return $export;
}
