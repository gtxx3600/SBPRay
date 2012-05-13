/*
 * Intersect.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "scene/Intersect.h"
#include <cstdlib>
#include "objects/Object.h"

const Intersect Intersect::kNoHit = Intersect(Object::kNoObject, Vec(), Vec(), 0.0);

Intersect::Intersect(const Object & _geometry, Vec _position, Vec _normal, float _distance)
:geometry(_geometry), position(_position), normal(_normal), distance(_distance)
{
}



