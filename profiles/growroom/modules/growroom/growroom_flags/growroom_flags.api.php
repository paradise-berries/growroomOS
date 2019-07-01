<?php

/**
 * @file
 * Hooks provided by growroom_flags.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_flags Growroom flag module integrations.
 *
 * Module integrations with the growroom_flags module.
 */

/**
 * @defgroup growroom_flags_hooks Growroom flag's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_flags.
 */

/**
 * Provide a list of flags that can be applied to records for filtering.
 *
 * @return array
 *   Returns an associative array of flags, with machine name and translatable.
 */
function hook_growroom_flags() {
  return array(
    'priority' => t('Priority'),
    'monitor' => t('Monitor'),
    'treatment' => t('Treatment'),
    'group1' => t('Group1'),
    'test1' => t('Test1'),
    'test2' => t('Test2'),
    'control' => t('Control'),
  );
}

/**
 * Allow modules to alter the classes that are added to flags when they are
 * displayed in growroomOS.
 */
function hook_growroom_flags_classes_alter($flag, &$classes) {
  if ($flag == 'priority') {
    $classes[] = 'my-priority-class';
  }
}

/**
 * @}
 */
