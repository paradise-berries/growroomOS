<?php
/**
 * @file
 * growroom_light.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function growroom_light_taxonomy_default_vocabularies() {
  return array(
    'growroom_light_names' => array(
      'name' => 'Growroom Light Names',
      'machine_name' => 'growroom_light_names',
      'description' => 'A vocabulary of light names.',
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
