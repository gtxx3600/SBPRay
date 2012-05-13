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
}

Material::Material(float _diffusion, float _reflection, float _refraction, Color _emittance)
:diffusion(_diffusion), reflection(_reflection), refraction(_refraction), emittance(_emittance){

}

Material::~Material(){
}


