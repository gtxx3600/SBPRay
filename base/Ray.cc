/*
 * Ray.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */
#include "base/Vec.h"
#include "base/Ray.h"


Ray::Ray(Vec p, Vec d) : position(p), direction(d)
{
  direction = direction.Normalize();
}

Ray::Ray(const Ray &r)
    : position(r.position), direction(r.direction) {

}


Vec Ray::GetPoint(double length) const {
  return position.Add(direction.Normalize().Multiply(length));
}



