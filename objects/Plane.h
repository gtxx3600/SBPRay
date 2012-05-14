/*
 * Plane.h
 *
 *  Created on: May 14, 2012
 *      Author: skaby
 */

#ifndef PLANE_H_
#define PLANE_H_

#include "objects/Object.h"
#include "base/Vec.h"

class Plane: public Object {
public:
  Plane(float _a, float _b, float _c, float _d, Material m);
  virtual ~Plane();
  void GetIntersect(const Ray &r, Intersect *out_ptr) const;

  float a, b, c, d; // a*x + b*y + c*z = d
};

#endif /* PLANE_H_ */
