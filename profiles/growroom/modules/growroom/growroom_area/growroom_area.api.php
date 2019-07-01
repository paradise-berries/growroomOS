<?php

/**
 * @file
 * Hooks provided by growroom_area.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_area Growroom area module integrations.
 *
 * Module integrations with the growroom_area module.
 */

/**
 * @defgroup growroom_area_hooks Growroom area's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_area.
 */

/**
 * Defines growroom area types.
 *
 * @return array
 *   Returns an array of growroom area type information.
 */
function hook_growroom_area_type_info() {
  return array(
    'building' => array(
      'label' => t('Building'),
      'weight' => 10,
    ),
  );
}

/**
 * Provide details about growroom areas.
 *
 * @param int $id
 *   The area id.
 *
 * @return array
 *   Returns a render array to add to the area's popup.
 */
function hook_growroom_area_details($id) {

  // Start a render array.
  $output = array();

  // Add "Hi" to area details.
  $output[] = array(
    '#type' => 'markup',
    '#markup' => 'Hi ',
  );

  // Return the render array.
  return $output;
}

/**
 * @}
 */
