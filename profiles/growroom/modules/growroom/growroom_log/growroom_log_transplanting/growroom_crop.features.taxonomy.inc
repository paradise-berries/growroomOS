<?php
/**
 * @file
 * growroom_crop.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function growroom_crop_taxonomy_default_vocabularies() {
  return array(
    'growroom_crop_families' => array(
      'name' => 'Growroom Crop Families',
      'machine_name' => 'growroom_crop_families',
      'description' => 'A taxonomy of crop families, for organizing crops.',
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
    'growroom_crops' => array(
      'name' => 'Growroom Crops/Varieties',
      'machine_name' => 'growroom_crops',
      'description' => 'A taxonomy of crops and varieties.',
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
