/*
 * Vec.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef VEC_H_
#define VEC_H_

class Vec {
public:
  static const Vec kZero;

  Vec();
  Vec(float a, float b, float c);
  Vec(Vec &v);
  Vec Normalize();
  Vec Negate();
  Vec Add(const Vec &v);
  Vec Sub(const Vec &v);
  Vec Multiply(float val);
  Vec XProduct(const Vec &v);
  float Length();
  float SqrLength();
  float DotProduct(const Vec &v);

  float x,y,z;
};

#endif /* VEC_H_ */
