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

const int PathTracingEngine::kMaxDepth = 2;
#include <iostream>
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
    if(m->emittance.red != 0) {
      return m->emittance;
    }
    //Process diffusion
    if(m->diffusion > 0) {
      int gen_ray_num = GenRayNumber(depth, diffuse_accumulation);
      Color diffuse_color = Color::kBlack;
      Color sum_color = Color::kBlack;
      //Randomly generate lot of rays and trace these rays
      for (int i = 0; i < gen_ray_num; ++i) {
        if (!diffuse_color.IsValid()) {
          cout << "begin("<<i<<"): diffuse_color:" << diffuse_color.red << ' ' <<
              diffuse_color.green << ' ' <<
              diffuse_color.blue << endl;
        }
        Ray new_ray = GenRandomRay(inst.position.Add(inst.normal.Multiply(0.00001)), inst.normal);
        Color new_color = PathTracing(scene, new_ray, depth + 1,
            diffuse_accumulation + m->diffusion);
        float cosa = new_ray.direction.DotProduct(inst.normal);
        diffuse_color = diffuse_color.Add(new_color.Multiply(cosa));
//        sum_color = sum_color.Add(new_color);
        if ((new_color.IsValid() && !diffuse_color.IsValid())) {
          cout << "new_color:" << new_color.red << ' ' << new_color.green << ' ' << new_color.blue << endl;
          cout << "sum_color:" << sum_color.red << ' ' << sum_color.green << ' ' << sum_color.blue << endl;
          cout << "diffuse_color:" << diffuse_color.red << ' ' <<
              diffuse_color.green << ' ' <<
              diffuse_color.blue << endl;
          if (i!=25)
          exit(1);
        }
      }
      //remember taking the average
      ret = ret.Add(diffuse_color.Multiply(m->diffusion / gen_ray_num));
//      diffuse_color = diffuse_color.Add(ret);
//      sum_color = diffuse_color.Add(ret);
//      ret = diffuse_color.MyDiv(sum_color);
    }
    if(!ret.IsValid())
    {
      std::cout << "error1\n";
    }
    //Process reflection, just generate the reflect ray
    if(m->reflection > 0) {
//    if(false) {
      Vec reflect_direction = ray.direction.Add(inst.normal.Multiply(
          2 * ray.direction.Negate().DotProduct(inst.normal)));
      Ray new_ray = Ray(inst.position.Add(inst.normal.Multiply(0.00001)), reflect_direction);
      Color new_color = PathTracing(scene, new_ray, depth + 1,
                  diffuse_accumulation + m->diffusion);
      ret = ret.Add(new_color.Multiply(m->reflection));
    }
    if(!ret.IsValid())
    {
      std::cout << "error2\n";
    }

  } else {
    return ret;
  }
  return ret;
}

int PathTracingEngine::GenRayNumber(int depth, double diffuse_accumulation){
  return (kMaxDepth - depth + 1) * 50; // (diffuse_accumulation > 0.5 ? diffuse_accumulation : 0.5);
}
/*
 * Generate rays uniformly distributed on an half sphere
 */
Ray PathTracingEngine::GenRandomRay(const Vec &position, const Vec &normal){
//  return Ray(position, Vec(0,0,0).Sub(position).Normalize());
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

