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
                                     int depth, double diffuse_accumulation)
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
    if(m->emittance.red > 0.001 || m->emittance.green > 0.001 || m->emittance.blue > 0.001) {
      return m->emittance;
    }
    //Process diffusion
    if(m->diffusion > 0) {
      Color diffuse_color = Color::kBlack;
      //Randomly generate lot of rays and trace these rays

      Ray new_ray = GenRandomRay(inst.position.Add(inst.normal.Multiply(0.00001)), inst.normal);
      Color new_color = PathTracing(scene, new_ray, depth + 1,
          diffuse_accumulation + m->diffusion);

      float cosine = new_ray.direction.DotProduct(inst.normal);
      if(depth < 1) {
        diffuse_color = diffuse_color.Add(new_color.Multiply(cosine));
      } else {
        diffuse_color = diffuse_color.Add(new_color);
      }
      //remember taking the average
      ret = ret.Add(diffuse_color.Multiply(m->diffusion).Modulate(m->color));

      /*float n_dot_l = inst.normal.DotProduct(light2);
      if(n_dot_l < 0) {
        ret = ret.Add(light_color2.Modulate(m->color).Multiply(-n_dot_l));
      }*/
    }

    //Process reflection, just generate the reflect ray
    if(m->reflection > 0) {
      Vec reflect_direction = ray.direction.Add(inst.normal.Multiply(
          2 * ray.direction.Negate().DotProduct(inst.normal)));
      Ray new_ray = Ray(inst.position.Add(inst.normal.Multiply(0.00001)), reflect_direction);
      Color new_color = PathTracing(scene, new_ray, depth + 1,
                  diffuse_accumulation + m->diffusion);
      ret = ret.Add(new_color.Multiply(m->reflection));
    }

  } else {
    return ret;
  }
  return ret;
}

int PathTracingEngine::GenRayNumber(int depth, double diffuse_accumulation){
  return (kMaxDepth - depth + 1) * 10; // (diffuse_accumulation > 0.5 ? diffuse_accumulation : 0.5);
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
  double len = abs(cos(gamma));
  double x = len * cos(theta);
  double y = len * sin(theta);
  Vec direction = Vec(x, y, z);
  if(direction.DotProduct(normal) > 0) {
    return Ray(position, direction.Normalize());
  } else {
    return Ray(position, direction.Negate().Normalize());
  }
}

PathTracingEngine::PathTracingEngine(){
}

