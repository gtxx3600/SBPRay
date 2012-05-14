/*
 * Color.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "base/Color.h"

const Color Color::kRed = Color(1.0, 0.0, 0.0);
const Color Color::kGreen = Color(0.0, 1.0, 0.0);
const Color Color::kBlue = Color(0.0, 0.0, 1.0);
const Color Color::kWhite = Color(1.0, 1.0, 1.0);
const Color Color::kBlack = Color(0.0, 0.0, 0.0);

Color::Color()
    :red(0.0), green(0.0), blue(0.0) {
}

Color::Color(double r, double g, double b)
    :red(r), green(g), blue(b) {
}

Color Color::Multiply(double a) const {
  return Color(red*a, green*a, blue*a);
}

Color Color::Modulate(const Color &c) const {
  return Color(red * c.red, green * c.green, blue * c.blue);
}

Color Color::Add(const Color &c) const {
  return Color(red + c.red, green + c.green, blue + c.blue);
}

Color Color::Sub(const Color &c) const {
  return Color(red - c.red, green - c.green, blue - c.blue);
}

bool Color::IsValid() const{
  return (red > -0.001) && (blue > -0.001) && (green > -0.001);
}


