<?php
/**
 * @file
 * growroom_area.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function growroom_area_taxonomy_default_vocabularies() {
  return array(
    'growroom_areas' => array(
      'name' => 'Growroom Areas',
      'machine_name' => 'growroom_areas',
      'description' => 'Distinct areas (fields, beds, greenhouses, etc) that crops are planted into.',
      'hierarchy' => 1,
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
