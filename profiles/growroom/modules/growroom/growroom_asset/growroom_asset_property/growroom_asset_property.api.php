<?php

/**
 * @file
 * Hooks provided by growroom_asset_property.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_asset_property Growroom asset property module integrations.
 *
 * Module integrations with the growroom_asset_property module.
 */

/**
 * @defgroup growroom_asset_property_hooks Growroom asset property's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_asset_property.
 */

/**
 * Defines growroom asset properties maintained by this module.
 *
 * @return array
 *   Returns an array of growroom asset property names.
 */
function hook_growroom_asset_property() {
  return array(
    'growroom_grazing_plant_type',
    'growroom_grazing_planned_arrival',
    'growroom_grazing_planned_departure',
  );
}

/**
 * @}
 */
