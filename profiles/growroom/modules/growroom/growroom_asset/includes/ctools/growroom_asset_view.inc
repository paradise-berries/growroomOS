<?php

/**
 * @file
 * Handle the 'growroom_asset view' override task.
 *
 * This plugin overrides growroom/asset/%growroom_asset and reroutes it to the page
 * manager, where a list of tasks can be used to service this request based upon
 * criteria supplied by access plugins.
 */

/**
 * Specialized implementation of hook_growroom_asset_task_tasks().
 *
 * See api-task.html for more information.
 */
function growroom_asset_growroom_asset_view_page_manager_tasks() {
  return array(
    // This is a 'page' task and will fall under the page admin UI.
    'task type' => 'page',

    'title' => t('growroom_asset template'),

    'admin title' => t('growroom_asset template'),
    'admin description' => t('When enabled, this overrides the default Drupal behavior for displaying growroom assets at <em>growroom/asset/%growroom_asset</em>. If you add variants, you may use selection criteria such as growroom asset type or language or user access to provide different views of growroom assets. If no variant is selected, the default Drupal growroom asset view will be used. This page only affects growroom assets viewed as pages, it will not affect growroom assets viewed in lists or at other locations. Also please note that if you are using pathauto, aliases may make a growroom asset to be somewhere else, but as far as Drupal is concerned, they are still at growroom/asset/%growroom_asset.'),
    'admin path' => 'growroom/asset/%growroom_asset',

    // Menu hooks so that we can alter the growroom/asset/%growroom_asset menu entry to
    // point to us.
    'hook menu' => 'growroom_asset_growroom_asset_view_menu',
    'hook menu alter' => 'growroom_asset_growroom_asset_view_menu_alter',

    // This is task uses 'context' handlers and must implement these to give the
    // handler data it needs.
    'handler type' => 'context',
    'get arguments' => 'growroom_asset_growroom_asset_view_get_arguments',
    'get context placeholders' => 'growroom_asset_growroom_asset_view_get_contexts',

    // Allow this to be enabled or disabled:
    'disabled' => variable_get('growroom_asset_growroom_asset_view_disabled', TRUE),
    'enable callback' => 'growroom_asset_growroom_asset_view_enable',
    'access callback' => 'growroom_asset_growroom_asset_view_access_check',
  );
}

/**
 * Callback defined by growroom_asset_growroom_asset_view_growroom_asset_tasks().
 *
 * Alter the growroom_asset view input so that growroom_asset view comes to us rather
 * than the normal growroom_asset view process.
 *
 * @param array $items
 *   Array of menu items.
 * @param array $task
 *   The task array.
 */
function growroom_asset_growroom_asset_view_menu_alter(array &$items, array $task) {
  if (variable_get('growroom_asset_growroom_asset_view_disabled', TRUE)) {
    return;
  }

  // Override the growroom_asset view handler for our purpose.
  $callback = $items['growroom/asset/%growroom_asset']['page callback'];
  if ($callback == 'growroom_asset_view' || variable_get('growroom_asset_override_anyway', FALSE)) {
    $items['growroom/asset/%growroom_asset']['page callback'] = 'growroom_asset_growroom_asset_view_page';
    $items['growroom/asset/%growroom_asset']['file path'] = $task['path'];
    $items['growroom/asset/%growroom_asset']['file'] = $task['file'];
  }
  else {
    // Automatically disable this task if it cannot be enabled.
    variable_set('growroom_asset_growroom_asset_view_disabled', TRUE);
    if (!empty($GLOBALS['growroom_asset_enabling_growroom_asset_view'])) {
      drupal_set_message(t('Page manager module is unable to enable growroom/asset/%growroom_asset because some other module already has overridden with %callback.', array('%callback' => $callback)), 'error');
    }
  }

  // @todo override growroom_asset revision handler as well?
}

/**
 * Entry point for our overridden growroom_asset view.
 *
 * This function asks its assigned handlers who, if anyone, would like
 * to run with it. If no one does, it passes through to Drupal core's
 * growroom_asset view, which is growroom_asset_view().
 *
 * @param GrowroomAsset $growroom_asset
 *   The growroom asset entity.
 *
 * @return array
 *   Returns a render array.
 */
function growroom_asset_growroom_asset_view_page(GrowroomAsset $growroom_asset) {
  // Load growroom_asset task plugin.
  $task = page_manager_get_task('growroom_asset_view');

  // Load the growroom_asset into a context.
  ctools_include('context');
  ctools_include('context-task-handler');

  // We need to mimic Drupal's behavior of setting the growroom_asset title here.
  drupal_set_title($growroom_asset->name);
  $uri = entity_uri('growroom_asset', $growroom_asset);
  // Set the growroom_asset path as the canonical URL to prevent duplicate content.
  drupal_add_html_head_link(array(
    'rel' => 'canonical',
    'href' => url($uri['path'], $uri['options'])), TRUE);
  // Set the non-aliased path as a default shortlink.
  drupal_add_html_head_link(array(
    'rel' => 'shortlink',
    'href' => url($uri['path'], array_merge($uri['options'], array('alias' => TRUE)))), TRUE);
  $contexts = ctools_context_handler_get_task_contexts($task, '', array($growroom_asset));

  $output = ctools_context_handler_render($task, '', $contexts, array($growroom_asset->id));
  if ($output != FALSE) {
    return $output;
  }

  module_load_include('inc', 'growroom_asset', 'growroom_asset.pages');
  $function = 'growroom_asset_view';
  foreach (module_implements('growroom_asset_override') as $module) {
    $call = $module . '_growroom_asset_override';
    if (($rc = $call('growroom_asset_view')) && function_exists($rc)) {
      $function = $rc;
      break;
    }
  }

  // Otherwise, fall back.
  return $function($growroom_asset);
}

/**
 * Callback to get arguments provided by this task handler.
 *
 * Since this is the growroom_asset view and there is no UI on the arguments, we
 * create dummy arguments that contain the needed data.
 *
 * @param array $task
 *   The task array.
 * @param string $subtask_id
 *   The subtask id.
 *
 * @return array
 *   Returns an array of arguments.
 */
function growroom_asset_growroom_asset_view_get_arguments(array $task, $subtask_id) {
  return array(
    array(
      'keyword' => 'growroom_asset',
      'identifier' => t('growroom_asset being viewed'),
      'id' => 1,
      'name' => 'entity_id:growroom_asset',
      'settings' => array(),
    ),
  );
}

/**
 * Callback to get context placeholders provided by this handler.
 *
 * @param array $task
 *   The task array.
 * @param string $subtask_id
 *   The subtask id.
 *
 * @return array
 *   Returns an array of contexts.
 */
function growroom_asset_growroom_asset_view_get_contexts(array $task, $subtask_id) {
  return ctools_context_get_placeholders_from_argument(growroom_asset_growroom_asset_view_get_arguments($task, $subtask_id));
}

/**
 * Callback to enable/disable the page from the UI.
 *
 * @param object $cache
 *   Cache object for the page manager view.
 * @param bool $status
 *   Whether or no the page manager override should be enabled.
 */
function growroom_asset_growroom_asset_view_enable($cache, $status) {
  variable_set('growroom_asset_growroom_asset_view_disabled', $status);

  // Set a global flag so that the menu routine knows it needs
  // to set a message if enabling cannot be done.
  if (!$status) {
    $GLOBALS['growroom_asset_enabling_growroom_asset_view'] = TRUE;
  }
}

/**
 * Callback to determine if a page is accessible.
 *
 * @param string $task
 *   The task plugin.
 * @param int $subtask_id
 *   The subtask id.
 * @param array $contexts
 *   The contexts loaded for the task.
 *
 * @return bool
 *   TRUE if the current user can access the page.
 */
function growroom_asset_growroom_asset_view_access_check($task, $subtask_id, array $contexts) {
  $context = reset($contexts);
  return growroom_asset_access('view', $context->data);
}
