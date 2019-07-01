<?php
/**
 * @file
 * growroom_plants.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function growroom_plants_taxonomy_default_vocabularies() {
  return array(
    'growroom_individual_cultivars' => array(
      'name' => 'Growroom Individual Cultivars',
      'machine_name' => 'growroom_individual_cultivars',
      'description' => 'A vocabulary of growroom individual cultivars.',
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
