<?php
/**
 * @file
 * Growroom light quick forms.
 */

/**
 * Implements hook_growroom_quick_forms().
 */
function growroom_light_growroom_quick_forms() {
  return array(
    'amendment' => array(
      'label' => t('Light amendment'),
      'permission' => 'create growroom_input log entities',
      'form' => 'growroom_light_amendment_form',
      'file' => 'growroom_light.growroom_quick.amendment.inc',
    ),
  );
}
