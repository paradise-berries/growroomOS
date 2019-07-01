<?php
/**
 * @file
 * Growroom access hooks implemented by growroom_api module.
 */

/**
 * Implements hook_growroom_access_perms().
 */
function growroom_api_growroom_access_perms($role) {
  $perms = array();

  // Grant access to RESTful Web Services resources.
  $perms[] = 'access farm api info';
  $perms[] = 'access resource growroom_asset';
  $perms[] = 'access resource field_collection';
  $perms[] = 'access resource production_log';
  $perms[] = 'access resource conditions_log';
  $perms[] = 'access resource operations_log';
  $perms[] = 'access resource taxonomy_term';
  $perms[] = 'access resource taxonomy_vocabulary';
  $perms[] = 'access resource user';

  return $perms;
}
