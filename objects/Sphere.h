/*
 * Sphere.h
 *
 *  Created on: May 13, 2012
 *      Author: skaby
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "objects/Object.h"
#include "base/Vec.h"

class Material;
class Sphere: public Object {
public:
  Sphere(const Vec &p, float radius, Material m);
  virtual ~Sphere();
  void GetIntersect(const Ray &r, Intersect *out_ptr) const;

  Vec position;
  float radius;
};

#endif /* SPHERE_H_ */
