<?php

/**
 * @file
 * Hooks provided by growroom_dashboard.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_dashboard Growroom dashboard module integrations.
 *
 * Module integrations with the growroom_dashboard module.
 */

/**
 * @defgroup growroom_dashboard_hooks Growroom dashboard's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_dashboard.
 */

/**
 * Defines growroom dashboard panes.
 *
 * @return array
 *   Returns an array of growroom dashboard pane configurations.
 */
function hook_growroom_dashboard_panes() {
  return array(

    // Specify a 'view' and 'view_display ID' to automatically load a View.
    // This will take precedence over 'title' and 'callback' below.
    'view' => 'my_view',
    'view_display_id' => 'block_1',

    // Specify the title and callback function that produces output.
    'title' => t('My pane title'),
    'callback' => 'my_callback_function',

    // Optionally specify a group and weight for display sorting.
    'group' => 'custom_group',
    'weight' => 100,
  );
}

/**
 * @}
 */
