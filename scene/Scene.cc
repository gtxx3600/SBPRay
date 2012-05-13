/*
 * Scene.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "scene/Scene.h"

Scene::Scene() {
  // TODO Auto-generated constructor stub

}

void Scene::CreateSphere(const Vec &p, float r) {
  object_list.push_back(Sphere(p, r));
}

void Scene::GetIntersect(const Ray &r, Intersect *out_ptr) const {
  list<Object>::const_iterator itr;
  for (itr = object_list.begin(); itr != object_list.end(); ++itr) {
    itr->GetIntersect(r, out_ptr);
  }
}
