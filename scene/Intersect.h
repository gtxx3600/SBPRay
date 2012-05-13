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
  Intersect();
  Intersect(const Object *_geometry_ptr, Vec _position, Vec _normal, float _distance);
  Intersect(const Intersect &intersect);
  bool IsValid() const;

  Object *geometry_ptr;
  Vec position;
  Vec normal;
  float distance;
};

#endif /* INTERSECT_H_ */
