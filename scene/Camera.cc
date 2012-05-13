/*
 * Camera.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "scene/Camera.h"
#include "base/Vec.h"


Camera::Camera(const Vec &p, const Vec &u, const Vec &f, float d)
    : position(p), upward(u), forward(f), distance(d) {
  position.Normalize();
  upward.Normalize();
  forward.Normalize();
}

Camera::Camera(float px, float py, float pz,
    float ux, float uy, float uz,
    float fx, float fy, float fz, float d)
    : position(px, py, pz), upward(ux, uy, uz), forward(fx, fy, fz), distance(d) {
  position.Normalize();
  upward.Normalize();
  forward.Normalize();
}
