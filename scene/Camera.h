/*
 * Camera.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "base/Vec.h"

class Ray;
class Camera {
public:
  Camera(const Vec &p, const Vec &u, const Vec &f, double d, double v);
  Camera(double px, double py, double pz,
      double ux, double uy, double uz,
      double fx, double fy, double fz, double d, double v);
  Ray GenerateRay(double x, double y);

  Vec position;
  Vec upward;
  Vec forward;
  Vec rightward;
  double distance;
  double fov_scale;
};

#endif /* CAMERA_H_ */
