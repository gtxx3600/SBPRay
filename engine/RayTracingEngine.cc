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
Vec light_dir = Vec(1,1,-1).Normalize();
Color light = Color(0.5,0.5,0.5);
Color RayTracingEngine::RayTracing(const Scene & scene, const Ray & ray, int depth, double diffuse_accumulation)
{
  Color ret = Color::kBlack;
  if(depth > kMaxDepth) {
    return ret;
  }
  Intersect inst = Intersect();
  scene.GetIntersect(ray, &inst);

  if(inst.IsValid()) {
    const Material * m = &(inst.geometry_ptr->material);
    //Process emittance

    //Process diffusion
    if(m->diffusion > 0.1) {
      Color diffuse_color = Color::kBlack;
      double n_dot_l = inst.normal.DotProduct(light_dir);
      if(n_dot_l < 0)
      {
        Color a1 = light.Multiply(-n_dot_l);
        Color a2 = a1.Modulate(m->color);
        ret = ret.Add(a2);
        //ret = ret.Add(light.Multiply(-n_dot_l).Modulate(m->color));

      }
    }
    if(!ret.IsValid())
    {
      std::cout << "error1\n";
    }
    //Process reflection, just generate the reflect ray
    if(m->reflection > 0.1) {
      Vec reflect_direction = ray.direction.Add(inst.normal.Multiply(
          2 * ray.direction.Negate().DotProduct(inst.normal))).Normalize();
      Ray new_ray = Ray(inst.position.Add(inst.normal.Multiply(0.001)), reflect_direction);
      Color new_color = RayTracing(scene, new_ray, depth + 1,
                  diffuse_accumulation + m->diffusion);
      ret = ret.Add(new_color.Multiply(m->reflection));
    }
    if(!ret.IsValid())
    {
      std::cout << "error2\n";
    }
    return ret;
  } else {
    return ret;
  }
}

RayTracingEngine::RayTracingEngine() {
  // TODO Auto-generated constructor stub

}

