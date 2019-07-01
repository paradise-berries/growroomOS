<?php

/**
 * @file
 * Hooks provided by growroom_map.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_map Growroom map module integrations.
 *
 * Module integrations with the growroom_map module.
 */

/**
 * @defgroup growroom_map_hooks Growroom map's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_map.
 */

/**
 * Extract geometries from an entity.
 *
 * @param $entity_type
 *   The entity type machine name.
 * @param $entity
 *   The entity object.
 *
 * @return array
 *   Return an array of geometry strings in WKT format. An associative array
 *   is allowed, and the keys can be used to differentiate multiple geometries
 *   from the same entity.
 */
function hook_growroom_map_entity_geometries($entity_type, $entity) {
  $geometries = array();

  // Find geometry in the standard geofield.
  if (empty($entity->field_growroom_geofield[LANGUAGE_NONE][0]['geom'])) {
    $geometries[] = $entity->field_growroom_geofield[LANGUAGE_NONE][0]['geom'];
  }

  return $geometries;
}

/**
 * @}
 */
