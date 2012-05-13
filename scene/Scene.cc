/*
 * Scene.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "scene/Scene.h"

#include <cstdlib>
#include "base/Color.h"
#include "objects/Sphere.h"
#include "scene/Intersect.h"

Scene::Scene() {

}

Scene::~Scene() {
  list<Object*>::const_iterator itr;
  for (itr = object_list.begin(); itr != object_list.end(); ++itr) {
    delete *itr;
  }
}

void Scene::CreateSphere(const Vec &p, float r, Material m) {
  Object *o_ptr = new Sphere(p, r, m);
  object_list.push_back(o_ptr);
}

void Scene::GetIntersect(const Ray &r, Intersect *out_ptr) const {
  list<Object*>::const_iterator itr;
  Intersect intersect;
  out_ptr->geometry_ptr = NULL;
  for (itr = object_list.begin(); itr != object_list.end(); ++itr) {
    (*itr)->GetIntersect(r, &intersect);
    if (intersect.IsValid() && !out_ptr->IsValid() &&
        intersect.distance < out_ptr->distance) {
      *out_ptr = intersect;
    }
  }
}
