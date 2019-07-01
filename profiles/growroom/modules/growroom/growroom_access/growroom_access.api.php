<?php

/**
 * @file
 * Hooks provided by growroom_access.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_access Growroom access module integrations.
 *
 * Module integrations with the growroom_access module.
 */

/**
 * @defgroup growroom_access_hooks Growroom access's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_access.
 */

/**
 * Defines growroom access roles.
 *
 * @return array
 *   Returns an array of growroom access roles.
 */
function hook_growroom_access_roles() {

  // Build a list of roles.
  $roles = array(

    'Growroom Manager',
    'Growroom Worker',
    'Growroom Viewer',
  );
  return $roles;
}

/**
 * Defines growroom access permissions.
 * Use growroom_access_entity_perms() to generate permissions for common entity
 * types.
 *
 * @param string $role
 *   The role name to add permissions for.
 *
 * @return array
 *   Returns an array of growroom access permissions.
 *
 * @see growroom_access_entity_perms()
 */
function hook_growroom_access_perms($role) {

  // Assemble a list of entity types provided by this module.
  $types = array(
    'growroom_asset' => array(
      'planting',
    ),
    'log' => array(
      'growroom_harvest',
      'growroom_input',
      'growroom_seeding',
      'growroom_transplanting',
    ),
    'taxonomy' => array(
      'growroom_crops',
      'growroom_crop_families',
    ),
  );

  // Grant different CRUD permissions based on the role.
  $perms = array();
  switch ($role) {

    // Growroom Admin and Manager and Worker

    case 'Growroom Manager':
    case 'Growroom Worker':
      $perms = growroom_access_entity_perms($types);
      break;

    // Growroom Viewer
    case 'Growroom Viewer':
      $perms = growroom_access_entity_perms($types, array('view'));
      break;
  }

  return $perms;
}

/**
 * Alter permissions that were defined by modules using hook_growroom_access_perms().
 *
 * @param string $role
 *   The role name that permissions are being built for.
 * @param array $perms
 *   The permissions provided by other modules, passed by reference.
 */
function hook_growroom_access_perms_alter($role, &$perms) {


  // Give Growroom Managers permission to administer modules.
  if ($role == 'Growroom Manager') {
    $perms[] = 'administer modules';
  }
}

/**
 * @}
 */
