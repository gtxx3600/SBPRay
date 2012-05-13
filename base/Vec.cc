/*
 * Vec.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */
#include <math.h>
#include "Vec.h"

const Vec Vec::kZero = Vec(0.0, 0.0, 0.0);

Vec::Vec() {
  // TODO Auto-generated constructor stub
  x = y = z = 0.0;
}

Vec::Vec(float a, float b, float c)
:x(a),y(b),z(c)
{
}

Vec Vec::Copy()
{
  return Vec(x,y,z);
}



Vec Vec::Normalize()
{
  float len = this->Length();
  if (len > 0) {
    return Vec(x/len, y/len, z/len);
  } else {
    return Vec(0,0,0);
  }
}



Vec Vec::Negate()
{
  return Vec(-x, -y, -z);
}



Vec Vec::Add(const Vec & v)
{
  return Vec(x + v.x, y + v.y, z + v.z);
}



Vec Vec::Sub(const Vec & v)
{
  return Vec(x - v.x, y - v.y, z - v.z);
}



Vec Vec::Multiply(float val)
{
  return Vec(x*val, y*val, z*val);
}



Vec Vec::XProduct(const Vec & v)
{
  return Vec(y*v.z - v.y*z, z*v.x - v.z*x, x*v.y - v.x*y);
}



float Vec::Length()
{
  return sqrt(x*x + y*y + z*z);
}



float Vec::SqrLength()
{
  return x*x + y*y + z*z;
}



float Vec::DotProduct(const Vec & v)
{
  return x*v.x + y*v.y + z*v.z;
}





