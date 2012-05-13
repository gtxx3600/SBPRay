/*
 * Sphere.cpp
 *
 *  Created on: May 13, 2012
 *      Author: skaby
 */

#include "objects/Sphere.h"

#include <cstdlib>
#include <cmath>
#include "base/Vec.h"
#include "base/Ray.h"
#include "scene/Intersect.h"

Sphere::Sphere(const Vec &p, double r, Material m)
    : Object(m), position(p), radius(r) {
}

Sphere::~Sphere() {
}

void Sphere::GetIntersect(const Ray &r, Intersect *out) const {
  bool is_in_sphere = false;
  out->geometry_ptr = NULL;
  Vec v = position.Sub(r.position);
  double slen_of_v = v.SqrLength();
  double sqr_radius = radius*radius;
  if (slen_of_v <= sqr_radius) {
    is_in_sphere = true;
  } else if (v.DotProduct(r.direction) <= 0) { // Fixme
    return;
  }
  double a = r.direction.SqrLength();
  double b = -2*v.DotProduct(r.direction);
  double c = a*(slen_of_v - sqr_radius);
  double delta = b*b - 4*a*c;
  if (delta >= 0) {
    double sqrt_delta = sqrt(delta);
    double t1 = (-b - sqrt_delta) / (2*a);
    double t2 = (-b + sqrt_delta) / (2*a);
    double tmin;
    if (t2 <= Object::kThreshold) {
      return;
    } else if (t1 <= Object::kThreshold) {
      tmin = t2;
    } else {
      tmin = t1;
    }
    out->geometry_ptr = this;
    out->distance  = tmin;
    out->position = r.GetPoint(tmin);
    if (is_in_sphere) { // Fixme
      out->normal = position.Sub(out->position).Normalize();
    } else {
      out->normal = out->position.Sub(position).Normalize();
    }
  }
}
