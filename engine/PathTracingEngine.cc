/*
 * PathTracingEngine.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "PathTracingEngine.h"
#include "scene/Scene.h"
#include "scene/Intersect.h"
#include "base/Color.h"
#include "base/Ray.h"
#include "base/Vec.h"

Color PathTracingEngine::PathTracing(const Scene & scene, const Ray & ray,
                                     int depth, float diffuse_accumulation)
{
  Intersect inst = Intersect();
  scene.GetIntersect(ray, &inst);
  if(inst.IsValid()) {

  } else {
    return Color::kBlack;
  }
  return Color::kBlack;
}



PathTracingEngine::PathTracingEngine()
{
}

