<?php
/**
 * @file
 * Growroom Plants quick forms.
 */

/**
 * Implements hook_growroom_quick_forms().
 */
function growroom_plants_growroom_quick_forms() {
  return array(
    'repop' => array(
      'label' => t('Repop'),
      'permission' => 'create growroom_repop log entities',
      'form' => 'growroom_plants_repop_form',
      'file' => 'growroom_plants.growroom_quick.repop.inc',
    ),
  );
}
