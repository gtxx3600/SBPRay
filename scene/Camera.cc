/*
 * Camera.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "scene/Camera.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "base/Vec.h"
#include "base/Ray.h"

Camera::Camera(const Vec &p, const Vec &u, const Vec &f, float d, float v)
    : position(p), upward(u), forward(f), distance(d){
  rightward = forward.XProduct(upward).Normalize();
  upward = upward.Normalize();
  forward = forward.Normalize().Multiply(distance);
  fov_scale = tan(v * 0.5 * M_PI / 180) * 2;
}

Camera::Camera(float px, float py, float pz,
    float ux, float uy, float uz,
    float fx, float fy, float fz, float d, float v)
    : position(px, py, pz), upward(ux, uy, uz), forward(fx, fy, fz),
      distance(d){
  rightward = forward.XProduct(upward).Normalize();
  upward = upward.Normalize();
  forward = forward.Normalize().Multiply(distance);
  fov_scale = tan(v * 0.5 * M_PI / 180) * 2;
}

Ray Camera::GenerateRay(float x, float y)
{
  Vec r = rightward.Multiply((x - 0.5) * fov_scale);
  Vec u = upward.Multiply((y - 0.5) * fov_scale);
  return Ray(position, forward.Add(r).Add(u).Normalize());
}





