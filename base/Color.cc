/*
 * Color.cc
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#include "base/Color.h"

#include <iostream>
using namespace std;

const Color Color::kRed = Color(1.0, 0.0, 0.0);
const Color Color::kGreen = Color(0.0, 1.0, 0.0);
const Color Color::kBlue = Color(0.0, 0.0, 1.0);
const Color Color::kWhite = Color(1.0, 1.0, 1.0);
const Color Color::kBlack = Color(0.0, 0.0, 0.0);

void Color::Print() const {
  cout << "{red:" << red << ",green:" << green << ",blue:" << blue << "}" << endl;
}

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

Color Color::MyAdd(const Color &c) const {
  return Color(red*red + c.red*c.red, green*green + c.green*c.green, blue*blue+c.blue*c.blue);
}

Color Color::MyDiv(const Color &c) const {
  float r = 0, g = 0, b = 0;
  if (c.red >= red) {
    r = red/c.red;
  }
  if (c.green >= green) {
    g = green/c.green;
  }
  if (c.blue >= blue) {
    b = blue/c.blue;
  }
  return Color(r, g, b);
}

bool Color::IsValid() const{
  return (red > -0.001) && (blue > -0.001) && (green > -0.001);
}

bool Color::IsBlack() const {
  const float th = 0.00001;
  return red < th && blue < th && green < th;
}

bool Color::IsTooLarge() const {
  const float th = 1;
  return red > th || blue > th || green > th;
}


