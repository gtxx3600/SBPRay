/*
 * Scene.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <list>
using namespace std;

class Object;
class Ray;
class Intersect;
class Scene {
public:
  Scene();
  ~Scene();
  void CreateSphere(const Vec &p, float r);
  void GetIntersect(const Ray &r, Intersect *out_ptr) const;

private:
  list<Object> object_list;
};

#endif /* SCENE_H_ */
