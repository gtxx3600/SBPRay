/*
 * Object.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef OBJECT_H_
#define OBJECT_H_

class Intersect;
class Object {
public:
  Object();
  virtual ~Object();

  virtual void GetIntersect(const Ray &r, Intersect *out_ptr) const = 0;
};

#endif /* OBJECT_H_ */
