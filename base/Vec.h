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
  Vec(const Vec &v);
  Vec Normalize() const;
  Vec Negate() const;
  Vec Add(const Vec &v) const;
  Vec Sub(const Vec &v) const;
  Vec Multiply(float val) const;
  Vec XProduct(const Vec &v) const;
  float Length() const;
  float SqrLength() const;
  float DotProduct(const Vec &v) const;

  float x,y,z;
};

#endif /* VEC_H_ */
