<?php
/**
 * @file
 * growroom_light.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function growroom_light_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_growroom_light_names_pattern';
  $strongarm->value = 'growroom/light/name/[term:name]';
  $export['pathauto_taxonomy_term_growroom_light_names_pattern'] = $strongarm;

  return $export;
}
