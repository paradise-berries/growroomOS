<?php
/**
 * @file
 * Growroom solution quick forms.
 */

/**
 * Implements hook_growroom_quick_forms().
 */
function growroom_solution_growroom_quick_forms() {
  return array(
    'amendment' => array(
      'label' => t('Solution amendment'),
      'permission' => 'create growroom_input log entities',
      'form' => 'growroom_solution_amendment_form',
      'file' => 'growroom_solution.growroom_quick.amendment.inc',
    ),
  );
}
