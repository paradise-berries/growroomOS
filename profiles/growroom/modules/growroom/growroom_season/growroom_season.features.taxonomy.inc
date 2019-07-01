<?php
/**
 * @file
 * growroom_season.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function growroom_season_taxonomy_default_vocabularies() {
  return array(
    'growroom_season' => array(
      'name' => 'Growroom Season',
      'machine_name' => 'growroom_season',
      'description' => 'A list of growroom seasons.',
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
