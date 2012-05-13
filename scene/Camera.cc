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

Camera::Camera(const Vec &p, const Vec &u, const Vec &f, double d, double v)
    : position(p), upward(u), forward(f), distance(d){
  rightward = forward.XProduct(upward).Normalize();
  upward = upward.Normalize();
  forward = forward.Normalize().Multiply(distance);
  fov_scale = tan(v * 0.5 * M_PI / 180) * 2;
}

Camera::Camera(double px, double py, double pz,
    double ux, double uy, double uz,
    double fx, double fy, double fz, double d, double v)
    : position(px, py, pz), upward(ux, uy, uz), forward(fx, fy, fz),
      distance(d){
  rightward = forward.XProduct(upward).Normalize();
  upward = upward.Normalize();
  forward = forward.Normalize();
  fov_scale = tan(v * 0.5 * M_PI / 180) * 2;
}

Ray Camera::GenerateRay(double x, double y)
{
  Vec r = rightward.Multiply((x - 0.5) * fov_scale);
  Vec u = upward.Multiply((y - 0.5) * fov_scale);
  return Ray(position, forward.Add(r).Add(u).Normalize());
}
