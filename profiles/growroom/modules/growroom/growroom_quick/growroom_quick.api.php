<?php

/**
 * @file
 * Hooks provided by growroom_quick.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup growroom_quick Growroom quick module integrations.
 *
 * Module integrations with the growroom_quick module.
 */

/**
 * @defgroup growroom_quick_hooks Growroom quick's hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend growroom_quick.
 */

/**
 * Define quick forms provided by this module
 */
function hook_growroom_quick_forms() {
  return array(
    'myform' => array(

      // This will be displayed as the title of the tab under "Quick forms".
      'label' => t('My form'),

      // This permission will be required to access the form.
      'permission' => 'create growroom_harvest log entities',

      // The form callback function.
      'form' => 'my_quick_form',

      // If the quick form functions are stored in a separate PHP file, specify
      // that as follows (relative to the module's directory).
      'file' => 'mymodule.growroom_quick.inc',
    ),
  );
}

/**
 * @}
 */
