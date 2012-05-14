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

const int PathTracingEngine::kMaxDepth = 5;
#include <iostream>

Vec light2 = Vec(0,-0.3,-1).Normalize();
Color light_color2 = Color(0.5,0.5,0.5);

Color PathTracingEngine::PathTracing(const Scene & scene, const Ray & ray,
                                     int depth)
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
    if(m->IsLightSource()) {
      return m->get_emittance();
    }
    Color diffuse_color = Color::kBlack;
    Color reflect_color = Color::kBlack;
    //Process diffusion
    if(!m->diffusion.IsBlack()) {
      Ray new_ray = GenRandomRay(inst.position.Add(inst.normal.Multiply(0.00001)), inst.normal);
      Color new_color = PathTracing(scene, new_ray, depth + 1);
      float cosa = new_ray.direction.DotProduct(inst.normal);
      if (depth < kMaxDepth) { // Fixme
        diffuse_color = new_color.Modulate(m->diffusion).Multiply(cosa);
      } else {
        diffuse_color = new_color.Modulate(m->diffusion);
      }
    }

    //Process reflection, just generate the reflect ray
    if(!m->reflection.IsBlack()) {
      Vec reflect_direction = ray.direction.Add(inst.normal.Multiply(
          2 * ray.direction.Negate().DotProduct(inst.normal)));
      Ray new_ray = Ray(inst.position.Add(inst.normal.Multiply(0.00001)), reflect_direction);
      Color new_color = PathTracing(scene, new_ray, depth + 1);
      float cosa = new_ray.direction.DotProduct(inst.normal);
      reflect_color = new_color.Modulate(m->reflection).Multiply(cosa);
    }
    ret = diffuse_color.Add(reflect_color);
  }
  return ret;
}

/*
 * Generate rays uniformly distributed on an half sphere
 */
Ray PathTracingEngine::GenRandomRay(const Vec &position, const Vec &normal){
  //return Ray(position, Vec(0,0,0).Sub(position).Normalize());
  int a = rand();
  int b = rand();
  double theta = M_PI * (static_cast<double>(2 * a) / static_cast<double>(RAND_MAX));
  double gamma = M_PI * (static_cast<double>(2 * b) / static_cast<double>(RAND_MAX));

  double z = sin(gamma);
//  double len = abs(cos(gamma));
  double x = cos(gamma) * cos(theta);
  double y = cos(gamma) * sin(theta);
  Vec direction = Vec(x, y, z);
  if(direction.DotProduct(normal) > 0) {
    return Ray(position, direction.Normalize());
  } else {
    return Ray(position, direction.Negate().Normalize());
  }
}

PathTracingEngine::PathTracingEngine(){
}

