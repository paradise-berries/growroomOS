<?php
/**
 * @file
 * growroom_fields.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function growroom_fields_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_growroom_log_categories_pattern';
  $strongarm->value = 'growroom/log/category/[term:name]';
  $export['pathauto_taxonomy_term_growroom_log_categories_pattern'] = $strongarm;

  return $export;
}
