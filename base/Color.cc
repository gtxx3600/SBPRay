/*
 * Color.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "Color.h"

Color::Color()
    :red(0.0), green(0.0), blue(0.0) {
}

Color::Color(float r, float g, float b)
    :red(r), green(g), blue(b) {
}

Color Color::Multiply(float a) {
  return Color(red*a, green*a, blue*a);
}

Color Color::Add(Color &c) {
  return Color(red + c.red, green + c.green, blue + c.blue);
}

Color Color::Sub(Color &c) {
  return Color(red - c.red, green - c.green, blue - c.blue);
}
