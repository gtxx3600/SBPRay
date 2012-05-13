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
  const static Object kNoObject;

  Object();
  virtual ~Object();

  virtual Intersect intersect(const Ray &r);
};

#endif /* OBJECT_H_ */
