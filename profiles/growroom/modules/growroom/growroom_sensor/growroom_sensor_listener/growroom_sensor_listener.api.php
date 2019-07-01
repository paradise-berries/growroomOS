<?php

/**
 * @file
 * Hooks provided by growroom_sensor_listener.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_sensor_listener Growroom sensor module integrations.
 *
 * Module integrations with the growroom_sensor_listener module.
 */

/**
 * @defgroup growroom_sensor_listener_hooks Growroom sensor's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_sensor_listener.
 */

/**
 * Do more with sensor data after it has been stored to the database.
 *
 * @param GrowroomAsset $sensor
 *   The sensor asset.
 * @param string $key
 *   The measurement name (ie: value, sensor1, sensor2, temperature, etc).
 * @param string $value
 *   The sensor value.
 *
 * @return array
 *   Returns a build array to be merged into the sensor asset view page.
 */
function hook_growroom_sensor_listener_data($sensor, $key, $value) {

}

/**
 * @}
 */
