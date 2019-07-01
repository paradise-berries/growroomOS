<?php
/**
 * @file
 * Growroom dashboard hooks implemented by growroom log module.
 */

/**
 * Implements hook_growroom_dashboard_panes().
 */
function growroom_log_growroom_dashboard_panes() {
  return array(
    'growroom_log_upcoming' => array(
      'view' => 'growroom_log',
      'view_display_id' => 'block_upcoming',
      'group' => 'logs',
      'weight' => 10,
    ),
    'growroom_log_late' => array(
      'view' => 'growroom_log',
      'view_display_id' => 'block_late',
      'group' => 'logs',
      'weight' => 11,
    ),
  );
}

