/*
 * Material.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "base/Color.h"

class Material {
public:
  Material();
  Material(Material & m);
  Material(double _diffusion, double _reflection, double _refraction,
           Color _emittance, Color _color);
  virtual ~Material();

  double diffusion;
  double reflection;
  double refraction;
  Color emittance;
  Color color;

};

#endif /* MATERIAL_H_ */
