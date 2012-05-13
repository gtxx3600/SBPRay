/*
 * Object.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "materials/Material.h"

class Ray;
class Intersect;
class Object {
public:
  Object(Material m);
  virtual ~Object();

  static const float kThreshold;

  virtual void GetIntersect(const Ray &r, Intersect *out_ptr) const = 0;
  Material material;
};

#endif /* OBJECT_H_ */
