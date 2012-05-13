/*
 * Intersect.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef INTERSECT_H_
#define INTERSECT_H_
class Vec;
class Object;
class Intersect {
public:
  const static Intersect  kNoHit;

  Intersect(const Object &_geometry, Vec _position, Vec _normal, float _distance);

  Object &geometry;
  Vec position;
  Vec normal;
  float distance;
};

#endif /* INTERSECT_H_ */
