/*
 * main.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include <iostream>
using namespace std;

#include "scene/Camera.h"
#include "scene/Scene.h"

int main(int argc, char **argv) {
  cout << "start" << endl;
  float distance = 1.0;
  Camera camera(0.0,0.0,-distance, 0.0,1.0,0.0, 0.0,0.0,1.0, distance);
  Scene scene;
  cout << "ok" << endl;
  return 0;
}
