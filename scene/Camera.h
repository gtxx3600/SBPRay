/*
 * Camera.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef CAMERA_H_
#define CAMERA_H_

class Vec;

class Camera {
public:
  Camera(const Vec &p, const Vec &u, const Vec &f, float d);
  Camera(float px, float py, float pz,
      float ux, float uy, float uz,
      float fx, float fy, float fz, float d);

  Vec position;
  Vec upward;
  Vec forward;
  float distance;
};

#endif /* CAMERA_H_ */
