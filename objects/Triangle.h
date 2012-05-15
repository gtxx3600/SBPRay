/*
 * Triangle.h
 *
 *  Created on: May 14, 2012
 *      Author: skaby
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "objects/Object.h"
#include "base/Vec.h"

class Triangle: public Object {
public:
  Triangle(Vec _p1, Vec _p2, Vec _p3, Material m);
  virtual ~Triangle();
  void GetIntersect(const Ray &r, Intersect *out_ptr) const;

  Vec p1, p2, p3;
};

#endif /* TRIANGLE_H_ */
