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
#include "engine/AntiAliasingEngine.h"
int main(int argc, char **argv) {
  cout << "start" << endl;
  double distance = 5.0;
  Camera camera(0.0,0.0,distance, 0.0,1.0,0.0, 0.0,0.0,-1.0, -distance, 45);
  Scene scene;
  Material source(Color(1,0,0), Color(), Color(), Color::kWhite.Multiply(1));
  Material source2(Color(1,0,0), Color(), Color(), Color::kWhite.Multiply(3));
  Material diffuse1(Color(0,1,0), Color(), Color());
  Material diffuse2(Color::kWhite, Color(), Color());
  Material diffuse3(Color(1,0,0), Color(), Color());
  Material reflect(Color::kWhite.Multiply(0.9), Color::kWhite.Multiply(0.1), Color());
  scene.CreateSphere(Vec(0, 100000, 0), 99997, source);
  scene.CreateSphere(Vec(-1,-0.5,0), 0.5, diffuse1);
  scene.CreateSphere(Vec(0,-0.5,0), 0.5, source2);
  scene.CreateSphere(Vec(1,-0.5,0), 0.5, diffuse3);
//  scene.CreateSphere(Vec(0,-10000,0), 9999, reflect);
  scene.CreatePlane(0, 1, 0, -1, reflect);

  //scene.CreateSphere(Vec(-1,-1,0), 0.5, reflect);
//  scene.CreateSphere(Vec(2, 2, 2), 2, material);
//  scene.CreateSphere(Vec(-2, -2, 0), 3, material);
  int size = 256;
  int samples = 64;
  int i = 0, super_count = 0;
  Color *color_arr = new Color [size * size];
  AntiAliasingEngine aae = AntiAliasingEngine(size, size);
  aae.LoadScene(scene, camera);
  int super_sample_num = 2;
  double sp_len = 1.0 / (size * 2 * super_sample_num);
  for (int y = 0; y < size; y++) {
    double sy = 1 - static_cast<double>(y) / size;
    cout << "y:" << y << endl;
    for (int x = 0; x < size; x++) {
      double sx = static_cast<double>(x) / size;
      Color color = Color::kBlack;
      if(aae.ShouldSuperSample(x, y)) {
        ++super_count;
        Color sp_color = Color::kBlack;
        Color aa_color = Color::kBlack;
        double spx,spy;
        for (int k = -super_sample_num; k < super_sample_num + 1; ++k) {
          spy = sy + k * sp_len;
          for (int l = -super_sample_num; l < super_sample_num + 1; ++l) {
            spx = sx + l * sp_len;
            Ray ray = camera.GenerateRay(spx, spy);
            for(int j = 0; j < samples; j++) {
              sp_color = sp_color.Add(PathTracingEngine::PathTracing(scene, ray, 0));
            }
            sp_color = sp_color.Multiply(1.0 / samples);
            color = color.Add(sp_color);
          }
        }
        color_arr[i++] = color.Multiply(1.0 / ((2 * super_sample_num + 1) * (2 * super_sample_num + 1)));

      } else {
        Ray ray = camera.GenerateRay(sx, sy);

        for(int j = 0; j < samples; j++) {
          color = color.Add(PathTracingEngine::PathTracing(scene, ray, 0));

        }
        //Color color = RayTracingEngine::RayTracing(scene, ray, 0, 0);

        color_arr[i++] = color.Multiply(1.0/samples);

      }
    }
  }
  cout << "i=" << i << ", super_count=" << super_count << endl;
  PPMFile ppmfile(size, size);
  ppmfile.DataCopy(color_arr, 0, size*size);
  ppmfile.Save("image.ppm");
  cout << "ok" << endl;
  return 0;
}
