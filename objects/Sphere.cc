/*
 * Sphere.cpp
 *
 *  Created on: May 13, 2012
 *      Author: skaby
 */

#include "objects/Sphere.h"

#include <cstdlib>
#include "base/Vec.h"
#include "base/Ray.h"
#include "scene/Intersect.h"

Sphere::Sphere() : position(), radius(0.0) {
}

Sphere::Sphere(const Vec &p, float r)
    : position(p), radius(r) {
}
Sphere::~Sphere() {
}

void Sphere::GetIntersect(const Ray &r, Intersect *out) const {
  Vec v = position.Sub(r.position);
  float a = r.direction.SqrLength();
  float b = 2*v.DotProduct(r.direction);
  float c = a*(v.SqrLength() - radius*radius);
  float delta = b*b - 4*a*c;
  out->geometry_ptr = NULL;
  if (delta >= 0) {
    float tmin = (-b - sqrt(delta)) / (2*a);
    if (tmin < 0)
      return;
    out->geometry_ptr = this;
    out->distance  = tmin;
    out->position = r.GetPoint(tmin);
    out->normal = out->position.Sub(position);
  }
}
