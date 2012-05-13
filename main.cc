/*
 * main.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include <iostream>
using namespace std;

#include "base/Ray.h"
#include "scene/Camera.h"
#include "scene/Scene.h"
#include "materials/Material.h"
#include "pic/PPMFile.h"
#include "engine/PathTracingEngine.h"
#include "engine/RayTracingEngine.h"
int main(int argc, char **argv) {
  cout << "start" << endl;
  double distance = 5.0;
  Camera camera(0.0,0.0,distance, 0.0,1.0,0.0, 0.0,0.0,-1.0, -distance, 45);
  Scene scene;
  Material source(1.0, 0.0, 0.0, Color::kWhite, Color::kRed);
  Material material(1.0, 0.0, 0.0, Color::kBlack, Color::kGreen);
  Material reflect(0.0, 1.0, 0.0, Color::kBlack, Color::kWhite);
//  scene.CreateSphere(Vec(0, 0, 0), 0.5, source);
//  scene.CreateSphere(Vec(1,1,0), 0.5, material);
  scene.CreateSphere(Vec(0,0,0), 1, reflect);
//  scene.CreateSphere(Vec(2, 2, 2), 2, material);
//  scene.CreateSphere(Vec(-2, -2, 0), 3, material);
  int size = 256;
  int i = 0;
  Color *color_arr = new Color [size * size];
  for (int y = 0; y < size; y++) {
    double sy = 1 - static_cast<double>(y) / size;
    for (int x = 0; x < size; x++) {
      double sx = static_cast<double>(x) / size;
      Ray ray = camera.GenerateRay(sx, sy);
      Color color = PathTracingEngine::PathTracing(scene, ray, 0, 0);
      //Color color = RayTracingEngine::RayTracing(scene, ray, 0, 0);
      color_arr[i++] = color;
    }
  }
  PPMFile ppmfile(size, size);
  ppmfile.DataCopy(color_arr, 0, size*size);
  ppmfile.Save("image.ppm");
  cout << "ok" << endl;
  return 0;
}
