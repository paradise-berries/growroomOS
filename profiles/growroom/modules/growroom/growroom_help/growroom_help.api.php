<?php

/**
 * @file
 * Hooks provided by growroom_help.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_help Growroom help module integrations.
 *
 * Module integrations with the growroom_help module.
 */

/**
 * @defgroup growroom_help_hooks growroom_help's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_help.
 */

/**
 * Add output to the /growroom/help page.
 *
 * @return array
 *   Returns an array of actions and their meta information (see example below).
 */
function hook_growroom_help_page() {

  // Add a link to growroomOS.rog
  $output = array(
    l('growroomOS.org', 'https://growroomos.org'),
  );
  return $output;
}

/**
 * @}
 */
