/*
 * Ray.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef RAY_H_
#define RAY_H_

#include "base/Vec.h"

class Ray {
public:
  Ray(Vec p, Vec d);
  Ray(const Ray &r);
  Vec GetPoint(double length) const;

  Vec position, direction;
};

#endif /* RAY_H_ */
