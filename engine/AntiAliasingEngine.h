/*
 * AntiAliasingEngine.h
 *
 *  Created on: 2012-5-14
 *      Author: gtxx3600
 */

#ifndef ANTIALIASINGENGINE_H_
#define ANTIALIASINGENGINE_H_

class Ray;
class Scene;
class Camera;
class AntiAliasingEngine {
public:
  int width;
  int height;
  const void*** map;
  AntiAliasingEngine(int _width, int _height);
  ~AntiAliasingEngine();
  void LoadScene(const Scene & scene, const Camera & camera);
  bool ShouldSuperSample(int x, int y) const;
private:
  const void* AATracing(const Scene & scene, const Ray & ray);

};

#endif /* ANTIALIASINGENGINE_H_ */
