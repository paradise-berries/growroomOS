<?php

/**
 * @file
 * Hooks provided by growroom_sensor.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_sensor Growroom sensor module integrations.
 *
 * Module integrations with the growroom_sensor module.
 */

/**
 * @defgroup growroom_sensor_hooks Growroom sensor's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_sensor.
 */

/**
 * Provide information about growroom sensor types.
 *
 * @return array
 *   Returns an array of sensor type information.
 */
function hook_growroom_sensor_type_info() {
  return array(
    'mysensor' => array(
      'label' => t('My Sensor'),
      'description' => t('Description of my sensor.'),
      'form' => 'my_sensor_settings_form_callback',
    ),
  );
}

/**
 * Add content to the sensor view page.
 *
 * @param GrowroomAsset $asset
 *   The sensor asset.
 *
 * @return array
 *   Returns a build array to be merged into the sensor asset view page.
 */
function hook_growroom_sensor_view($asset) {
  $build['mysensor'] = array(
    '#markup' => 'Add this to the sensor asset page!',
  );
  return $build;
}

/**
 * @}
 */
