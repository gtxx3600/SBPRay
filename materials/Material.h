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
  Material(Color _diffusion, Color _reflection,
      Color _refraction);
  Material(Color _diffusion, Color _reflection,
      Color _refraction, Color _emittance);
  virtual ~Material();
  virtual bool IsLightSource() const;
  virtual Color get_emittance() const;

  Color diffusion;
  Color reflection;
  Color refraction;
  Color emittance;
};

#endif /* MATERIAL_H_ */
