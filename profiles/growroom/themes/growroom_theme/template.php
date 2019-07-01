<?php
/**
 * @file
 * Growroom theme template.php.
 */

/**
 * Implements hook_menu_link_alter().
 */
function growroom_theme_menu_link_alter(&$item) {

  // Expand top-level menu link items by default and provide descriptions.
  $paths = array(
    'growroom/areas' => t('Areas are places on/off the growroom.'),
    'growroom/assets' => t('Assets are the "things" you want to manage.'),
    'growroom/WIP' => t('WIP are the "production processes" you want to manage.'),
    'growroom/logs' => t('Logs are the "events" that happen to assets and areas.'),
    'growroom/people' => t('People are who make it happen.'),
    'growroom/plans' => t('Plans provide features for organizing and planning other records.'),
  );
  if (array_key_exists($item['link_path'], $paths)) {
    $item['expanded'] = TRUE;
    $item['options']['attributes']['title'] = $paths[$item['link_path']];
  }
}

/**
 * Implements hook_preprocess_menu_tree().
 */
function growroom_theme_preprocess_menu_tree(&$variables) {

  /**
   * This code will generate a list of places in the growroom dropdown menus where
   * a Bootstrap divider item should be inserted. This is done based on the
   * weights of the menu items. Dividers will be added after all items with a
   * weight < 0, and before items with a weight >= 100.
   */

  // Only do this for the primary menu.
  if ($variables['theme_hook_original'] != 'menu_tree__primary') {
    return;
  }

  // Start an empty array to store menu divider information.
  $dividers = array();

  // Iterate through the top level menu items.
  $menu = $variables['#tree'];
  foreach (element_children($menu) as $child) {

    // Define the menu items we care about.
    $menus = array(
      'growroom/assets' => 'assets',
      'growroom/wip' => 'wip',
      'growroom/logs' => 'logs',
      'growroom/plans' => 'plans',
    );

    // If we don't care about this menu item, skip it.
    if (!array_key_exists($menu[$child]['#href'], $menus)) {
      continue;
    }

    // Get the menu class.
    $menu_class = $menus[$menu[$child]['#href']];

    // Iterate through child items.
    $items = $menu[$child]['#below'];
    $menu_counter = 0;
    foreach (element_children($items) as $mlid) {

      // If the original link has a weight < 0, remember it.
      if ($items[$mlid]['#original_link']['weight'] < 0) {
        $dividers[$menu_class][0] = $menu_counter;
      }

      // Or, if it has a weight >= 100, and we haven't already found one like
      // that, remember it. (We only want to remember the first one, because in
      // this case, we're putting the divider BEFORE it. Whereas with the first
      // divider it is going AFTER the items with a weight < 0.)
      elseif ($items[$mlid]['#original_link']['weight'] >= 100 && !isset($dividers[$menu_class][100])) {
        $dividers[$menu_class][100] = $menu_counter;
      }

      // Keep count of which item we're on.
      $menu_counter++;
    }
  }

  // If divider information was generated, add Javascript.
  if (!empty($dividers)) {
    drupal_add_js(array('growroom_theme' => array('menu_dividers' => $dividers)), 'setting');
    drupal_add_js(drupal_get_path('theme', 'growroom_theme') . '/js/menu.js');
  }
}

/**
 * Implements hook_preprocess_views_view().
 */
function growroom_theme_preprocess_views_view(&$vars) {

  // If the View has a 'footer' or 'feed_icon', wrap it in a div with the
  // 'text-center' class.
  $center_elements = array(
    'footer',
    'feed_icon',
  );
  foreach ($center_elements as $element) {
    if (!empty($vars[$element])) {
      $vars[$element] = '<div class="text-center">' . $vars[$element] . '</div>';
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function growroom_theme_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {

  /* Wrap the exposed form in a Bootstrap collapsible panel. */

  // Collapsible panel ID.
  $panel_head_id = $form['#id'] . '-panel-heading';
  $panel_body_id = $form['#id'] . '-panel-body';

  // Collapse by default.
  $collapse = TRUE;

  // If the form was submitted (if there are values in $_GET other than 'q'),
  // do not collapse the form.
  if (count($_GET) > 1) {
    $collapse = FALSE;
  }

  // Set attributes depending on the collapsed state (used in HTML below).
  if ($collapse) {
    $collapse_class = '';
    $aria_expanded = 'false';
  }
  else {
    $collapse_class = ' in';
    $aria_expanded = 'true';
  }

  // Form prefix HTML:
  $form['#prefix'] = '
<fieldset class="panel panel-default collapsible">
<legend class="panel-heading" role="tab" id="' . $panel_head_id . '">
  <a class="panel-title fieldset-legend collapsed" data-toggle="collapse" href="#' . $panel_body_id . '" aria-expanded="' . $aria_expanded . '" aria-controls="' . $panel_body_id . '">
    Filter/Sort
  </a>
</legend>
<div id="' . $panel_body_id . '" class="panel-collapse collapse' . $collapse_class . '" role="tabpanel" aria-labelledby="' . $panel_head_id . '">
  <div class="panel-body">';

  // Form suffix HTML:
  $form['#suffix'] = '
  </div>
</div>
</fieldset>';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function growroom_theme_form_log_form_alter(&$form, &$form_state, $form_id) {

  // Collapse the "Movement" and "Group Membership" fieldsets in log forms.
  $collapse_fieldsets = array(
    'field_growroom_movement',
    'field_growroom_membership',
  );
  foreach ($collapse_fieldsets as $fieldset) {
    if (!empty($form[$fieldset][LANGUAGE_NONE][0])) {
      $form[$fieldset][LANGUAGE_NONE][0]['#collapsible'] = TRUE;
      $form[$fieldset][LANGUAGE_NONE][0]['#collapsed'] = TRUE;
    }
  }
}

/**
 * Implements hook_views_bulk_operations_form_alter().
 */
function growroom_theme_views_bulk_operations_form_alter(&$form, &$form_state, $vbo) {

  // Add some JavaScript that enhances VBO.
  drupal_add_js(drupal_get_path('theme', 'growroom_theme') . '/js/vbo.js');

  // Move VBO buttons to the bottom.
  $form['select']['#weight'] = 100;

  // Move the certain actions to the end of the list.
  $end_actions = array(
    'action::growroom_map_kml_action',
    'action::growroom_flags_action',
    'action::growroom_log_assign_action',
    'action::growroom_group_asset_membership_action',
    'action::growroom_group_production_membership_action',
    'action::growroom_asset_archive_action',
    'action::growroom_asset_unarchive_action',
    'action::growroom_wip_archive_action',
    'action::growroom_wip_unarchive_action',
    'action::growroom_asset_clone_action',
    'action::log_clone_action',
    'action::views_bulk_operations_delete_item',
  );
  $i = 0;
  foreach ($end_actions as $action) {
    $form['select'][$action]['#weight'] = 100 + $i;
    $i++;
  }

  // If we are viewing a VBO config or confirm form, add Javascript that will
  // hide everything on the page except for the form.
  $vbo_steps = array(
    'views_bulk_operations_config_form',
    'views_bulk_operations_confirm_form',
  );
  if (!empty($form_state['step']) && in_array($form_state['step'], $vbo_steps)) {

    // Set the title to '<none>' so that Views doesn't do drupal_set_title().
    // See https://www.drupal.org/node/2905171.
    $vbo->view->set_title('<none>');

    // Add some information to Javascript settings.
    $settings = array(
      'vbo_hide' => TRUE,
      'view_name' => $vbo->view->name,
      'view_display' => $vbo->view->current_display,
    );
    drupal_add_js(array('growroom_theme' => $settings), 'setting');
  }
}

/**
 * Implements hook_bootstrap_colorize_text_alter().
 */
function growroom_theme_bootstrap_colorize_text_alter(&$texts) {

  // Colorize VBO action buttons.
  $texts['matches'][t('Flag')] = 'info';
  $texts['matches'][t('KML')] = 'success';
  $texts['matches'][t('Move')] = 'success';
  $texts['matches'][t('Weight')] = 'default';
  $texts['matches'][t('Group')] = 'warning';
  $texts['matches'][t('Done')] = 'success';
  $texts['matches'][t('Not Done')] = 'danger';
  $texts['matches'][t('Reschedule')] = 'warning';
  $texts['matches'][t('Assign')] = 'info';
  $texts['matches'][t('Clone')] = 'default';
  $texts['matches'][t('Archive')] = 'danger';
  $texts['matches'][t('Unarchive')] = 'default';
  $texts['matches'][t('Delete')] = 'primary';
}

/**
 * Implements hook_bootstrap_iconize_text_alter().
 */
function growroom_theme_bootstrap_iconize_text_alter(&$texts) {

  // Iconize VBO action buttons.
  $texts['matches'][t('Flag')] = 'flag';
  $texts['matches'][t('KML')] = 'globe';
  $texts['matches'][t('Move')] = 'globe';
  $texts['matches'][t('Weight')] = 'scale';
  $texts['matches'][t('Group')] = 'bookmark';
  $texts['matches'][t('Done')] = 'check';
  $texts['matches'][t('Not Done')] = 'unchecked';
  $texts['matches'][t('Reschedule')] = 'calendar';
  $texts['matches'][t('Assign')] = 'user';
  $texts['matches'][t('Clone')] = 'plus';
  $texts['matches'][t('Archive')] = 'eye-close';
  $texts['matches'][t('Unarchive')] = 'eye-open';
  $texts['matches'][t('Delete')] = 'trash';
}

/**
 * Implements hook_growroom_flags_classes_alter().
 */
function growroom_theme_growroom_flags_classes_alter($flag, &$classes) {

  // Render all flags as extra small buttons using Bootstrap's classes.
  $classes[] = 'btn';
  $classes[] = 'btn-xs';

  // Add a button style class based on the flag used.
  switch ($flag) {
    case 'priority':
      $classes[] = 'btn-primary';
      break;
    case 'monitor':
      $classes[] = 'btn-danger';
      break;
    case 'review':
      $classes[] = 'btn-warning';
      break;
    default:
      $classes[] = 'btn-default';
  }
}

/**
 * Implements hook_entity_view_alter().
 */
function growroom_theme_entity_view_alter(&$build, $type) {

  // If the entity is not a growroom_asset, bail.
  if ($type != 'growroom_asset') {
    return;
  }

  // If certain elements exist, we will split the page into two columns and
  // put them in the right column, and everything else in the left.
  $right_elements = array(
    'inventory',
    'weight',
    'group',
    'location',
  );
  $right_elements_exist = FALSE;
  foreach ($right_elements as $name) {
    if (!empty($build[$name])) {
      $right_elements_exist = TRUE;
      break;
    }
  }
  if ($right_elements_exist) {

    // Create a new container div that spans half of the grid.
    $build['right'] = array(
      '#type' => 'container',
      '#prefix' => '<div class="col-md-6">',
      '#suffix' => '</div>',
      '#weight' => -99,
    );

    // Move the elements into the container.
    foreach ($right_elements as $name) {
      if (!empty($build[$name])) {
        $build['right'][$name] = $build[$name];
        unset($build[$name]);
      }
    }

    // Put everything else into another div and move it to the top so it
    // aligns left.
    $build['left'] = array(
      '#prefix' => '<div class="col-md-6">',
      '#suffix' => '</div>',
      '#weight' => -100,
    );
    $elements = element_children($build);
    foreach ($elements as $element) {
      if (!in_array($element, array('left', 'right', 'views'))) {
        $build['left'][$element] = $build[$element];
        unset($build[$element]);
      }
    }

    // Wrap the Views in a full-width div at the bottom.
    if (!empty($build['views'])) {
      $build['views']['#prefix'] = '<div class="col-md-12">';
      $build['views']['#suffix'] = '</div>';
      $build['views']['#weight'] = 101;
    }
  }
}

/**
 * Implements hook_entityreference_view_widget_rows_alter().
 */
function growroom_theme_entityreference_view_widget_rows_alter(&$rows, $entities, $settings) {

  // Fix "Checkbox titles missing with Bootstrap theme" in Entity Reference
  // View Widget. See issue:
  // https://www.drupal.org/project/entityreference_view_widget/issues/2524296
  foreach (element_children($rows) as $key => $child) {
    if ($rows[$key]['target_id']['#type'] == 'checkbox') {
      $rows[$key]['target_id']['#title'] = $rows[$key]['target_id']['#field_suffix'];
    }
  }
}

/**
 * Implements hook_page_alter().
 */
function growroom_theme_page_alter(&$page) {

  // If an access denied page is displayed and the user is not logged in...
  global $user;
  $status = drupal_get_http_header('status');
  if ($status == '403 Forbidden' && empty($user->uid)) {

    // Display a link to the user login page, and redirect back to this page.
    $page['content']['system_main']['login'] = array(
      '#type' => 'markup',
      '#markup' => '<p>' . l('Please Login', 'user', array('query' => array('destination' => current_path()))) . '</p>',
    );
  }
}

/**
 * Implements hook_preprocess_page().
 */
function growroom_theme_preprocess_page(&$vars) {

  // Add JS for adding Bootstrap glyphicons throughout the UI.
  $glyphicons_text = array(
    t('Dashboard') => 'dashboard',
    t('Calendar') => 'calendar',
    t('Help') => 'question-sign',
    t('Create new account') =>'user',
    t('My account') => 'user',
    t('Log out') => 'log-out',
    t('Log in') => 'log-in',
    t('Request new password') => 'lock',
    t('Areas') => 'globe',
    t('Assets') => 'grain',
    t('Logs') => 'list',
    t('People') => 'user',
    t('Plans') => 'book',
  );
  drupal_add_js(array('growroom_theme' => array('glyphicons_text' => $glyphicons_text)), 'setting');
  drupal_add_js(drupal_get_path('theme', 'growroom_theme') . '/js/glyphicons.js');

  // Add Javascript to automatically collapse the help text.
  if (!empty($vars['page']['help'])) {
    drupal_add_js(drupal_get_path('theme', 'growroom_theme') . '/js/help.js');
  }

  // Split the growroom dashboard into two columns, with the map on the right.
  $current_path = current_path();
  if ($current_path == 'growroom') {

    // Only proceed if the map group exists.
    if (!empty($vars['page']['content']['system_main']['map'])) {

      // Get a list of groups (element children).
      $groups = element_children($vars['page']['content']['system_main']);

      // Create left and right columns.
      $vars['page']['content']['system_main']['left'] = array(
        '#prefix' => '<div class="col-md-6">',
        '#suffix' => '</div>',
      );
      $vars['page']['content']['system_main']['right'] = array(
        '#prefix' => '<div class="col-md-6">',
        '#suffix' => '</div>',
      );

      // Move the map to the right column (and remove it from the groups list).
      $vars['page']['content']['system_main']['right']['map'] = $vars['page']['content']['system_main']['map'];
      unset($vars['page']['content']['system_main']['map']);
      $map_key = array_search('map', $groups);
      unset($groups[$map_key]);

      // Iterate through the remaining groups and move them to the left column.
      foreach ($groups as $group) {
        $vars['page']['content']['system_main']['left'][$group] = $vars['page']['content']['system_main'][$group];
        unset($vars['page']['content']['system_main'][$group]);
      }
    }
  }

  // When the growroom_areas map is added to a page (via growroom_area_page_build()),
  // split the page into two columns.
  if (!empty($vars['page']['content']['growroom_areas'])) {

    // Wrap map and content in "col-md-6" class so they display in two columns.
    $vars['page']['content']['growroom_areas']['#prefix'] = '<div class="col-md-6">';
    $vars['page']['content']['growroom_areas']['#suffix'] = '</div>';
    $vars['page']['content']['system_main']['#prefix'] = '<div class="col-md-6">';
    $vars['page']['content']['system_main']['#suffix'] = '</div>';
  }

  // Remove from taxonomy term pages:
  // "There is currently no content classified with this term."
  if (isset($vars['page']['content']['system_main']['no_content'])) {
    unset($vars['page']['content']['system_main']['no_content']);
  }

  // Add "Powered by growroomOS" to the footer.
  $vars['page']['footer']['growroomos'] = array(
    '#type' => 'markup',
    '#prefix' => '<div style="text-align: center;"><small>',
    '#markup' => t('Powered by') . ' ' . l(t('growroomOS'), 'https://growroomos.org'),
    '#suffix' => '</small></div>',
  );
}

/**
 * Implements hook_preprocess_field().
 */
function growroom_theme_preprocess_field(&$vars) {

  // Add a clearfix class to field_growroom_images to prevent float issues.
  // @see .field-name-field-growroom-images .field-item in styles.css.
  if ($vars['element']['#field_name'] == 'field_growroom_images') {
    $vars['classes_array'][] = 'clearfix';
  }
}

/**
 * Implements hook_preprocess_calendar_item().
 */
function growroom_theme_preprocess_calendar_item(&$vars) {

  // If the item has a Log entity associated with it, add the log type as a
  // CSS class.
  if (!empty($vars['item']->entity->type)) {
    $class = drupal_html_class($vars['item']->entity->type);
    if (empty($vars['item']->class)) {
      $vars['item']->class = $class;
    }
    else {
      $vars['item']->class .= ' ' . $class;
    }
  }
}

/**
 * Implements hook_preprocess_calendar_month().
 */
function growroom_theme_preprocess_calendar_month(&$vars) {
  growroom_theme_calendar_css('month');
}

/**
 * Implements hook_preprocess_calendar_week().
 */
function growroom_theme_preprocess_calendar_week_overlap(&$vars) {
  growroom_theme_calendar_css('week');
}

/**
 * Implements hook_preprocess_calendar_day().
 */
function growroom_theme_preprocess_calendar_day_overlap(&$vars) {
  growroom_theme_calendar_css('day');
}

/**
 * Helper function for adding calendar CSS.
 *
 * @param string $period
 *   The calendar period being displayed (year, month, week, or day).
 */
function growroom_theme_calendar_css($period) {

  // Add general CSS styles.
  drupal_add_css(drupal_get_path('theme', 'growroom_theme') . '/css/calendar.css');

  // Define the log type colors.
  $log_type_colors = array(
    'growroom_activity' => '#f7e6d2',
    'growroom_harvest' => '#daeace',
    'growroom_input' => '#ebdaec',
    'growroom_observation' => '#ccebf5',
  );

  // Use the color information to build CSS rules.
  $css = '';
  foreach ($log_type_colors as $log_type => $color) {

    // Convert the log type to a valid CSS class.
    $log_type_class = drupal_html_class($log_type);

    // Build the item selector based on the period.
    switch ($period) {
      case 'month':
        $calendar_item_selector = '.calendar-calendar .month-view .full td.single-day .' . $log_type_class . ' div.monthview, .calendar-calendar .week-view .full td.single-day .' . $log_type_class . ' div.weekview, .calendar-calendar .day-view .full td.single-day .' . $log_type_class . ' div.dayview';
        break;
      case 'week':
      case 'day':
        $calendar_item_selector = '.calendar-calendar .week-view .full div.single-day .' . $log_type_class . ' div.weekview, .calendar-calendar .day-view .full div.single-day .' . $log_type_class . ' div.dayview';
        break;
      default:
        $calendar_item_selector = '';
    }

    // If a selector was found, add the CSS.
    if (!empty($calendar_item_selector)) {
      $css .= $calendar_item_selector . '{background: ' . $color . ';} ';
    }
  }

  // If we have CSS to add, add it.
  if (!empty($css)) {
    drupal_add_css($css, array('type' => 'inline'));
  }
}
