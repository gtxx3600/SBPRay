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

class PathTracingEngine {
public:
  static Color PathTracing(const Scene & scene, const Ray & ray,
                           int depth, float diffuse_accumulation);

private:
  PathTracingEngine();
};

#endif /* PATHTRACINGENGINE_H_ */
