/*
 * Material.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "materials/Material.h"
#include "base/Color.h"

Material::Material() {
  // TODO Auto-generated constructor stub
  diffusion = 0;
  reflection = 0;
  refraction = 0;
  emittance = Color::kBlack;
  color = Color::kBlack;
}

Material::Material(float _diffusion, float _reflection,
                   float _refraction, Color _emittance, Color _color)
:diffusion(_diffusion), reflection(_reflection),
 refraction(_refraction), emittance(_emittance), color(_color){

}

Material::Material(Material & m)
{
  diffusion = m.diffusion;
  reflection = m.reflection;
  refraction = m.refraction;
  emittance = m.emittance;
  color = m.color;
}

Material::Material(float _diffusion, float _reflection, float _refraction,
                   Color _emittance, Color _color)
{
}

Material::~Material(){
}


