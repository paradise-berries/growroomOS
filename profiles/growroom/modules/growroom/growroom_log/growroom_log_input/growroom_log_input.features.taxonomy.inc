<?php
/**
 * @file
 * growroom_log_input.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function growroom_log_input_taxonomy_default_vocabularies() {
  return array(
    'growroom_materials' => array(
      'name' => 'Growroom Materials',
      'machine_name' => 'growroom_materials',
      'description' => 'A vocabulary of growroom materials.',
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
