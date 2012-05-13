/*
 * Sphere.cpp
 *
 *  Created on: May 13, 2012
 *      Author: skaby
 */

#include "objects/Sphere.h"

#include "base/Vec.h"
#include "scene/Intersect.h"

Sphere::Sphere() : position(), radius(0.0) {
}

Sphere::Sphere(const Vec &p, float r)
    : position(p), radius(r) {
}


Intersect Sphere::intersect(const Ray &r) {
  Vec v = position.Sub(r.position);
  float a = r.direction.SqrLength();
  float b = 2*v.DotProduct(r.direction);
  float c = a*(v.SqrLength() - radius*radius);
  float delta = b*b - 4*a*c;
  if (delta >= 0) {
    float tmin = (-b - sqrt(delta)) / (2*a);
    Intersect intersect; // TODO
  }
  return Intersect::kNoHit;
}
