<?php
/**
 * @file
 * growroom_solution.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function growroom_solution_taxonomy_default_vocabularies() {
  return array(
    'growroom_solution_names' => array(
      'name' => 'Growroom Solution Names',
      'machine_name' => 'growroom_solution_names',
      'description' => 'A vocabulary of solution names.',
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
