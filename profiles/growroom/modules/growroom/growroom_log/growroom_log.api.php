<?php

/**
 * @file
 * Hooks provided by growroom_log.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_log Growroom log module integrations.
 *
 * Module integrations with the growroom_log module.
 */

/**
 * @defgroup growroom_log_hooks Growroom log's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_log.
 */

/**
 * Provide a list of log categories that should be created when the module
 * is installed. Note that these will be passed through the t() function when
 * they are created so that they can be translated. This does mean that they
 * will only be translated once, to whatever the site's default language is.
 *
 * @return array
 *   Returns an array of log categories (as simple strings).
 */
function hook_growroom_log_categories() {
  return array(
    'My module category',
    'My other category',
  );
}

/**
 * Allow modules to automatically populate log categories in log forms. The
 * category must exist already. Note that these will be passed through the t()
 * function when they are added so that they can be translated. This does mean
 * that they will only be translated once, to whatever the site's default
 * language is.
 *
 * @param object $log
 *   A log entity.
 *
 * @return array
 *   Returns an array of log categories (as simple strings).
 */
function hook_growroom_log_categories_populate($log) {
  $categories = array();

  if ($log->type == 'growroom_water_test') {
    $categories[] = 'Water';
  }

  return $categories;
}

/**
 * Allow modules to provide information about fields that should be
 * prepopulated in log forms.
 *
 * @param string $log_type
 *   The log type.
 *
 * @return array
 *   Returns an array of field information.
 */
function hook_growroom_log_prepopulate_reference_fields($log_type) {
  return array(
    'field_growroom_asset' => array(
      'entity_type' => 'growroom_asset',
      'url_param' => 'growroom_asset',
    ),
  );
}

/**
 * Allow modules to alter information about fields that should be
 * prepopulated in log forms.
 *
 * @param array $fields
 *   An array of field information defined via
 *   hook_growroom_log_prepopulate_reference_fields().
 * @param string $log_type
 *   The log type.
 *
 * @return array
 *   Returns an array of field information.
 */
function hook_growroom_log_prepopulate_reference_fields_alter(&$fields, $log_type) {

  // Example: don't allow prepopulating the asset field on activity logs.
  if ($log_type == 'growroom_activity') {
    unset($fields['field_growroom_asset']);
  }
}

/**
 * @}
 */
