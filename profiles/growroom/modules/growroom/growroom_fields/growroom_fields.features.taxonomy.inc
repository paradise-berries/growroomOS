<?php
/**
 * @file
 * growroom_fields.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function growroom_fields_taxonomy_default_vocabularies() {
  return array(
    'growroom_log_categories' => array(
      'name' => 'Growroom Log Categories',
      'machine_name' => 'growroom_log_categories',
      'description' => 'Vocabulary of growroom log categories.',
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
