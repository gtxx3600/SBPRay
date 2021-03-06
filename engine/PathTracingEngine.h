/*
 * PathTracingEngine.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef PATHTRACINGENGINE_H_
#define PATHTRACINGENGINE_H_

class Color;
class Scene;
class Ray;
class Vec;
class PathTracingEngine {
public:
  static const int kMaxDepth;
  static Color PathTracing(const Scene & scene, const Ray & ray,
                           int depth, double diffuse_accumulation);
  static int GenRayNumber(int depth, double diffuse_accumulation);
  static Ray GenRandomRay(const Vec &position, const Vec &normal);

private:
  PathTracingEngine();
};

#endif /* PATHTRACINGENGINE_H_ */
