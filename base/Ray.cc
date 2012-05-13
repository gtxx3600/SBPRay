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


Vec Ray::getPoint(float length)
{
  return position.Add(direction.Normalize().Multiply(length));
}



