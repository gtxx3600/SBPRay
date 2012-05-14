/*
 * Plane.cpp
 *
 *  Created on: May 14, 2012
 *      Author: skaby
 */

#include "objects/Plane.h"
#include <cstdlib>
#include "base/Ray.h"
#include "base/Vec.h"
#include "scene/Intersect.h"

Plane::Plane(float _a, float _b, float _c, float _d, Material m)
    : Object(m), a(_a), b(_b), c(_c), d(_d) {
}

Plane::~Plane() {
}

void Plane::GetIntersect(const Ray &r, Intersect *out_ptr) const {
  out_ptr->geometry_ptr = NULL;
  float coef = a*r.direction.x + b*r.direction.y + c*r.direction.z;
  if (coef < Object::kThreshold && coef > -Object::kThreshold) {
    return;
  }
  float bias = d - (a*r.position.x + b*r.position.y + c*r.position.z);
  float t = bias / coef;
  if (t > Object::kThreshold) {
    out_ptr->geometry_ptr = this;
    out_ptr->distance = t;
    out_ptr->position = r.GetPoint(t);
    if (0 > bias) {
      out_ptr->normal = Vec(a, b, c).Normalize();
    } else {
      out_ptr->normal = Vec(a, b, c).Normalize().Negate();
    }
  }
}
