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
  Vec(double a, double b, double c);
  Vec(const Vec &v);
  Vec Normalize() const;
  Vec Negate() const;
  Vec Add(const Vec &v) const;
  Vec Sub(const Vec &v) const;
  Vec Multiply(double val) const;
  Vec XProduct(const Vec &v) const;
  double Length() const;
  double SqrLength() const;
  double DotProduct(const Vec &v) const;
  void Print() const;

  double x,y,z;
};

#endif /* VEC_H_ */
