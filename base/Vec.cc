/*
 * Vec.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */
#include <math.h>
#include "base/Vec.h"

const Vec Vec::kZero = Vec(0.0, 0.0, 0.0);

Vec::Vec()
    :x(0.0), y(0.0), z(0.0) {
}

Vec::Vec(double a, double b, double c)
    :x(a),y(b),z(c) {
}

Vec::Vec(const Vec &v)
    :x(v.x), y(v.y), z(v.z) {
}

Vec Vec::Normalize() const {
  double len = this->Length();
  if (len > 0.0) {
    return Vec(x/len, y/len, z/len);
  } else {
    return Vec(0.0,0.0,0.0);
  }
}



Vec Vec::Negate() const {
  return Vec(-x, -y, -z);
}



Vec Vec::Add(const Vec & v)const
{
  return Vec(x + v.x, y + v.y, z + v.z);
}



Vec Vec::Sub(const Vec & v) const
{
  return Vec(x - v.x, y - v.y, z - v.z);
}



Vec Vec::Multiply(double val) const
{
  return Vec(x*val, y*val, z*val);
}



Vec Vec::XProduct(const Vec & v) const
{
  return Vec(y*v.z - v.y*z, z*v.x - v.z*x, x*v.y - v.x*y);
}



double Vec::Length() const
{
  return sqrt(x*x + y*y + z*z);
}



double Vec::SqrLength() const
{
  return x*x + y*y + z*z;
}



double Vec::DotProduct(const Vec & v) const
{
  return x*v.x + y*v.y + z*v.z;
}





