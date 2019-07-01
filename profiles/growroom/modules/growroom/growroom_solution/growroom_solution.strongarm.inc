<?php
/**
 * @file
 * growroom_solution.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function growroom_solution_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_growroom_solution_names_pattern';
  $strongarm->value = 'growroom/solution/name/[term:name]';
  $export['pathauto_taxonomy_term_growroom_solution_names_pattern'] = $strongarm;

  return $export;
}
