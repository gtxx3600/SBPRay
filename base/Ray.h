/*
 * Ray.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef RAY_H_
#define RAY_H_

class Vec;

class Ray {
public:
  Vec position, direction;

  Ray(Vec p, Vec d);
  Vec getPoint(float length);

};

#endif /* RAY_H_ */
