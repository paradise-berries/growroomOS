<?php
/**
 * @file
 * Growroom dashboard hooks implemented by growroom calendar module.
 */

/**
 * Implements hook_growroom_dashboard_panes().
 */
function growroom_calendar_growroom_dashboard_panes() {
  return array(
    'growroom_calendar_date' => array(
      'callback' => 'growroom_calendar_dashboard_date',
      'group' => 'logs',
      'weight' => -1,
    ),
  );
}

/**
 * Date dashboard callback.
 */
function growroom_calendar_dashboard_date() {
  return '<h2>' . t('Today is') . ' ' . l(date('m j y'), 'growroom/calendar/day') . '</h2>';
}
