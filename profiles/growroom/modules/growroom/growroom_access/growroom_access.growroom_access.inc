<?php
/**
 * @file
 * Growroom access hooks implemented by growroom access module.
 */

/**
 * Implements hook_growroom_access_roles().
 */
function growroom_access_growroom_access_roles() {

  // Build a list of roles.
  $roles = array(

    'Growroom Manager',
    'Growroom Worker',
    'Growroom Viewer',
  );
  return $roles;
}

/**
 * Implements hook_growroom_access_perms().
 */
function growroom_asset_growroom_access_perms($role) {
  $perms = array();

  // Set up default CRUD permissions for all growroom asset entity types.
  $asset_types = growroom_asset_types();
  $access_types = array(
    'growroom_asset' => array(),
  );
  foreach ($asset_types as $type => $data) {
    $access_types['growroom_asset'][] = $type;
  }
  switch ($role) {

    // Grant full access to Growroom Manager and Worker roles.

    case 'Growroom Manager':
    case 'Growroom Worker':
      $perms = growroom_access_entity_perms($access_types);
      break;

    // Grant read-only access to Growroom Viewer role.
    case 'Growroom Viewer':
      $perms = growroom_access_entity_perms($access_types, array('view'));
      break;
  }

  // Grant access to view growroom assets.
  $perms[] = 'view growroom assets';

  return $perms;
}

/**
 * Implements hook_growroom_access_perms().
 */
function growroom_plan_growroom_access_perms($role) {
  $perms = array();

  // Set up default CRUD permissions for all growroom plan entity types.
  $plan_types = growroom_plan_types();
  $access_types = array(
    'growroom_plan' => array(),
  );
  foreach ($plan_types as $type => $data) {
    $access_types['growroom_plan'][] = $type;
  }
  switch ($role) {

    // Grant full access to Growroom Manager and Worker roles.

    case 'Growroom Manager':
    case 'Growroom Worker':
      $perms = growroom_access_entity_perms($access_types);
      break;

    // Grant read-only access to Growroom Viewer role.
    case 'Growroom Viewer':
      $perms = growroom_access_entity_perms($access_types, array('view'));
      break;
  }

  // Grant access to view growroom plans.
  $perms[] = 'view growroom plans';

  return $perms;
}

/**
 * Implements hook_growroom_access_perms().
 */
function log_growroom_access_perms($role) {
  $perms = array();

  // Set up default CRUD permissions for all log entity types.
  $log_types = log_types();
  $access_types = array(
    'log' => array(),
  );
  foreach ($log_types as $type => $data) {
    $access_types['log'][] = $type;
  }
  switch ($role) {

    // Grant full access to Growroom Manager and Worker roles.

    case 'Growroom Manager':
    case 'Growroom Worker':
      $perms = growroom_access_entity_perms($access_types);
      break;

    // Grant read-only access to Growroom Viewer role.
    case 'Growroom Viewer':
      $perms = growroom_access_entity_perms($access_types, array('view'));
      break;
  }

  // View all logs.
  $perms[] = 'view all logs';

  return $perms;
}

/**
 * Implements hook_growroom_access_perms().
 */
function node_growroom_access_perms($role) {
  $perms = array();

  // This is needed to view nodes and taxonomy terms.
  $perms[] = 'access content';

  return $perms;
}

/**
 * Implements hook_growroom_access_perms().
 */
function system_growroom_access_perms($role) {
  $perms = array();

  // Grant access to admin pages.
  $perms[] = 'access administration pages';

  return $perms;
}

/**
 * Implements hook_growroom_access_perms().
 */
function role_delegation_growroom_access_perms($role) {
  $perms = array();

  // Allow Growroom Managers to delegate roles.
  if ($role == 'Growroom Manager') {

    // Allow role delegation (add one for each defined role).
    $roles = module_invoke_all('growroom_access_roles');
    foreach ($roles as $role) {
      $perms[] = 'assign ' . $role . ' role';
    }
  }

  return $perms;
}

/**
 * Implements hook_growroom_access_perms().
 */
function taxonomy_growroom_access_perms($role) {
  $perms = array();

  // Assemble a list of all taxonomies.
  $vocabularies = taxonomy_get_vocabularies();
  $types = array(
    'taxonomy' => array(),
  );
  foreach ($vocabularies as $vocab) {
    $types['taxonomy'][] = $vocab->machine_name;
  }

  // Grant different CRUD permissions based on the role.
  switch ($role) {

    // Growroom Manager and Worker

    case 'Growroom Manager':
    case 'Growroom Worker':
      $perms = growroom_access_entity_perms($types);
      break;

    // Growroom Viewer
    case 'Growroom Viewer':
      $perms = growroom_access_entity_perms($types, array('view'));
      break;
  }

  // This is needed to add terms.
  if (in_array($role, array('Growroom Manager', 'Growroom Worker'))) {
    $perms[] = 'administer taxonomy';
  }

  return $perms;
}

/**
 * Implements hook_growroom_access_perms().
 */
function user_growroom_access_perms($role) {
  $perms = array();

  // Allow Growroom Managers and Growroom Workers to view user profiles.
  if ($role == 'Growroom Manager' || $role == 'Growroom Worker') {
    $perms[] = 'access user profiles';
  }

  // Allow Growroom Managers to administer users.
  if ($role == 'Growroom Manager') {

    // Administer users.
    $perms[] = 'administer users';
  }

  return $perms;
}
