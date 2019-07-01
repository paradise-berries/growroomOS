<?php

/**
 * @file
 * Growroom plan views hooks.
 */

/**
 * Implements hook_views_plugins().
 */
function growroom_plan_views_plugins() {
  return array(
    'argument validator' => array(
      'growroom_plan' => array(
        'title' => t('Growroom plan'),
        'handler' => 'growroom_plan_plugin_argument_validate_growroom_plan',
        'path' => drupal_get_path('module', 'growroom_plan') . '/views/plugins',
      ),
    ),
  );
}
