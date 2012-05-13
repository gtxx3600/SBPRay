/*
 * RayTracingEngine.cc
 *
 *  Created on: 2012-5-14
 *      Author: gtxx3600
 */

#include "RayTracingEngine.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

#include "scene/Scene.h"
#include "scene/Intersect.h"
#include "materials/Material.h"
#include "base/Color.h"
#include "base/Ray.h"
#include "base/Vec.h"
const int RayTracingEngine::kMaxDepth = 6;
#include <iostream>
Vec light_dir = Vec(-1,-1,-1).Normalize();
Color light = Color(0.5,0.5,0.5);
Color RayTracingEngine::RayTracing(const Scene & scene, const Ray & ray, int depth, float diffuse_accumulation)
{
  Color ret = Color::kBlack;
  if(depth > kMaxDepth) {
    return ret;
  }
  Intersect inst = Intersect();
  scene.GetIntersect(ray, &inst);
  const Material * m = &(inst.geometry_ptr->material);
  if(inst.IsValid()) {
    //Process emittance

    //Process diffusion
    if(m->diffusion > 0.1) {
      Color diffuse_color = Color::kBlack;
      float n_dot_l = inst.normal.DotProduct(light_dir);
      if(n_dot_l > 0)
      {
        ret = ret.Add(light.Multiply(n_dot_l).Modulate(m->color));
        std::cout<<"hit\n";
      }
    }

    //Process reflection, just generate the reflect ray
    if(m->reflection > 0.1) {
      Vec reflect_direction = ray.direction.Add(inst.normal.Multiply(
          2 * ray.direction.Negate().DotProduct(inst.normal))).Normalize();
      Ray new_ray = Ray(inst.position, reflect_direction);
      Color new_color = RayTracing(scene, new_ray, depth + 1,
                  diffuse_accumulation + m->diffusion);
      ret = ret.Add(new_color.Multiply(m->reflection));
    }


  } else {
    return ret;
  }
  return ret;
}

RayTracingEngine::RayTracingEngine() {
  // TODO Auto-generated constructor stub

}

