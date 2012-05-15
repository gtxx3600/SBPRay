/*
 * Triangle.cc
 *
 *  Created on: May 14, 2012
 *      Author: skaby
 */

#include "objects/Triangle.h"
#include <cstdlib>
#include "base/Ray.h"
#include "base/Vec.h"
#include "scene/Intersect.h"

Triangle::Triangle(Vec _p1, Vec _p2, Vec _p3, Material m)
    : Object(m), p1(_p1), p2(_p2), p3(_p3) {
}

Triangle::~Triangle() {
}

void Triangle::GetIntersect(const Ray &r, Intersect *out_ptr) const {
  Vec u = p2.Sub(p1);
  Vec v = p3.Sub(p1);
  Vec normal = u.XProduct(v);
  out_ptr->geometry_ptr = NULL;
  float coef = r.direction.DotProduct(normal);
  if (coef < Object::kThreshold && coef > -Object::kThreshold) {
    return;
  }
  float bias = p1.Sub(r.position).DotProduct(normal);
  float t = bias / coef;
  if (t > Object::kThreshold) {
    Vec intp = r.GetPoint(t);
    Vec nu = normal.XProduct(u);
    Vec nv = normal.XProduct(v);
    float t1 = intp.Sub(p1).DotProduct(nv) / u.DotProduct(nv);
    float t2 = intp.Sub(p1).DotProduct(nu) / v.DotProduct(nu);
    if (t1 < 0 || t2 < 0 || t1 + t2 > 1) {
      return;
    }
    out_ptr->geometry_ptr = this;
    out_ptr->distance = t;
    out_ptr->position = intp;
    if (0 > bias) {
      out_ptr->normal = normal.Normalize();
    } else {
      out_ptr->normal = normal.Normalize().Negate();
    }
  }
}
