/*
 * AntiAliasingEngine.cc
 *
 *  Created on: 2012-5-14
 *      Author: gtxx3600
 */

#include "AntiAliasingEngine.h"
#include <cstdlib>
#include "base/Ray.h"
#include "scene/Scene.h"
#include "scene/Camera.h"
#include "scene/Intersect.h"
AntiAliasingEngine::AntiAliasingEngine(int _width, int _height)
    :width(_width), height(_height){
  // TODO Auto-generated constructor stub
  map = new const void**[_width];
  for (int i = 0; i < _width; ++i) {
    map[i] = new const void* [_height];
  }
  for (int i = 0; i < _width; ++i) {
    for (int j = 0; j < _height; ++j) {
      map[i][j] = NULL;
    }
  }
}

AntiAliasingEngine::~AntiAliasingEngine()
{
  delete map;
}

void AntiAliasingEngine::LoadScene(const Scene & scene, const Camera & camera)
{
  for (int y = 0; y < height; y++) {
    double sy = 1 - static_cast<double>(y) / height;
    for (int x = 0; x < width; x++) {
      double sx = static_cast<double>(x) / width;
      Ray ray = camera.GenerateRay(sx, sy);
      map[x][y] = AATracing(scene, ray);
    }
  }
}

bool AntiAliasingEngine::ShouldSuperSample(int x, int y) const
{
  if((x > 0) && (map[x][y] != map[x - 1][y])) return true;
  if((x < width - 1) && (map[x][y] != map[x + 1][y])) return true;
  if((y > 0) && (map[x][y] != map[x][y - 1])) return true;
  if((y < height - 1) && (map[x][y] != map[x][y + 1])) return true;
  return false;
}

const void *AntiAliasingEngine::AATracing(const Scene & scene, const Ray & ray)
{
  Intersect inst = Intersect();
  scene.GetIntersect(ray, &inst);
  return inst.geometry_ptr;
}



