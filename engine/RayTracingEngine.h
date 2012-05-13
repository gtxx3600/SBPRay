/*
 * RayTracingEngine.h
 *
 *  Created on: 2012-5-14
 *      Author: gtxx3600
 */

#ifndef RAYTRACINGENGINE_H_
#define RAYTRACINGENGINE_H_

class Color;
class Scene;
class Ray;
class Vec;
class RayTracingEngine {
public:
  static const int kMaxDepth;
  static Color RayTracing(const Scene & scene, const Ray & ray,
                           int depth, float diffuse_accumulation);
  RayTracingEngine();
};

#endif /* RAYTRACINGENGINE_H_ */
