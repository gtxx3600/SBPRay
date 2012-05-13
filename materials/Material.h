/*
 * Material.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

class Color;

class Material {
public:
  Material();
  Material(Material & m);
  Material(float _diffusion, float _reflection, float _refraction,
           Color _emittance, Color _color);
  virtual ~Material();

  float diffusion;
  float reflection;
  float refraction;
  Color emittance;
  Color color;

};

#endif /* MATERIAL_H_ */
