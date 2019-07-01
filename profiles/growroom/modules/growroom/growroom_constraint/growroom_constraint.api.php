<?php

/**
 * @file
 * Hooks provided by growroom_constraint.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_constraint Growroom constraint module integrations.
 *
 * Module integrations with the growroom_constraint module.
 */

/**
 * @defgroup growroom_constraint_hooks Growroom constraint's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_constraint.
 */

/**
 * Defines growroom constraint types.
 *
 * @param $type
 *   The entity type.
 * @param $bundle
 *   The entity bundle.
 * @param $id
 *   The entity id.
 *
 * @return bool
 *   Return TRUE if a constraint exists. FALSE otherwise.
 */
function hook_growroom_constraint($type, $bundle, $id) {

  // Check to see if any other records reference this entity.
  // ...

  // Constraint exists!
  return TRUE;
}

/**
 * @}
 */
