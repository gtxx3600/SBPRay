/*
 * PathTracingEngine.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "PathTracingEngine.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

#include "scene/Scene.h"
#include "scene/Intersect.h"
#include "materials/Material.h"
#include "base/Color.h"
#include "base/Ray.h"
#include "base/Vec.h"

const int PathTracingEngine::kMaxDepth = 6;

Color PathTracingEngine::PathTracing(const Scene & scene, const Ray & ray,
                                     int depth, float diffuse_accumulation)
{
  Color ret = Color::kBlack;
  if(depth > kMaxDepth) {
    return ret;
  }
  Intersect inst = Intersect();
  scene.GetIntersect(ray, &inst);
  Material * m = &(inst.geometry_ptr->material);
  if(inst.IsValid()) {

    //Process diffusion
    if(m->diffusion > 0) {
      int gen_ray_num = GenRayNumber(depth, diffuse_accumulation);
      Color diffuse_color = Color::kBlack;
      //Randomly generate lot of rays and trace these rays
      for (int i = 0; i < gen_ray_num; ++i) {
        Ray new_ray = GenRandomRay(inst.position, inst.normal);
        Color new_color = PathTracing(scene, new_ray, depth + 1,
            diffuse_accumulation + m->diffusion);
        diffuse_color = diffuse_color.Add(new_color.Multiply(
            new_ray.direction.DotProduct(inst.normal)));
      }
      //remember taking the average
      ret = ret.Add(diffuse_color.Multiply(m->diffusion / gen_ray_num));
    }

    //Process reflection, just generate the reflect ray
    if(m->reflection > 0) {
      Vec reflect_direction = ray.direction.Add(inst.normal.Multiply(
          2 * ray.direction.Negate().DotProduct(inst.normal)));
      Ray new_ray = Ray(inst.position, reflect_direction);
      Color new_color = PathTracing(scene, new_ray, depth + 1,
                  diffuse_accumulation + m->diffusion);
      ret = ret.Add(new_color.Multiply(m->reflection));
    }

    //Process emittance
    ret = ret.Add(m->emittance);
  } else {
    return ret;
  }
  return ret;
}

int PathTracingEngine::GenRayNumber(int depth, float diffuse_accumulation){
  return (kMaxDepth - depth) * 5 / (diffuse_accumulation > 0.5 ? diffuse_accumulation : 0.5);
}
/*
 * Generate rays uniformly distributed on an half sphere
 */
Ray PathTracingEngine::GenRandomRay(const Vec &position, const Vec &normal){
  int a = rand();
  int b = rand();
  float theta = M_PI * (static_cast<float>(2 * a) / static_cast<float>(RAND_MAX));
  float gamma = M_PI * (static_cast<float>(2 * b) / static_cast<float>(RAND_MAX));

  float z = sin(gamma);
  float len = abs(cos(gamma));
  float x = len * cos(theta);
  float y = len * sin(theta);
  Vec direction = Vec(x, y, z);
  if(direction.DotProduct(normal) > 0) {
    return Ray(position, direction.Normalize());
  } else {
    return Ray(position, direction.Negate().Normalize());
  }
}

PathTracingEngine::PathTracingEngine(){
}

