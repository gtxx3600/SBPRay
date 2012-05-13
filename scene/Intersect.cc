/*
 * Intersect.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "scene/Intersect.h"
#include <cstdlib>
#include "objects/Object.h"

Intersect::Intersect()
    : geometry_ptr(NULL) {

}

Intersect::Intersect(const Object * _geometry, Vec _position, Vec _normal, float _distance)
    :geometry_ptr(_geometry), position(_position), normal(_normal), distance(_distance)
{
}

Intersect::Intersect(const Intersect &intersect)
    : geometry_ptr(intersect.geometry_ptr),
      position(intersect.position),
      normal(intersect.normal),
      distance(intersect.distance) {
}

bool Intersect::IsValid() {
  return geometry_ptr != NULL;
}
