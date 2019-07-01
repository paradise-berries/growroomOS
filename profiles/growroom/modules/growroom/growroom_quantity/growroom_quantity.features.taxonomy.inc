<?php
/**
 * @file
 * growroom_quantity.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function growroom_quantity_taxonomy_default_vocabularies() {
  return array(
    'growroom_quantity_units' => array(
      'name' => 'Growroom Quantity Units',
      'machine_name' => 'growroom_quantity_units',
      'description' => 'A vocabulary of units for describing quantities.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
