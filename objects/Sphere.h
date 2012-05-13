/*
 * Sphere.h
 *
 *  Created on: May 13, 2012
 *      Author: skaby
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Object.h"

class Vec;

class Sphere: public Object {
public:
  Sphere();
  Sphere(const Vec &p, float radius);

  Vec position;
  float radius;
};

#endif /* SPHERE_H_ */
