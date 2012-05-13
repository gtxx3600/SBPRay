/*
 * Color.h
 *
 *  Created on: 2012-5-13
 *      Author: gtxx3600
 */

#ifndef COLOR_H_
#define COLOR_H_

class Color {
public:

  const static Color kRed;
  const static Color kGreen;
  const static Color kBlue;
  const static Color kWhite;
  const static Color kBlack;

  Color();
  Color(float r, float g, float b);
  Color Multiply(float a) const;
  Color Modulate(const Color &c) const;
  Color Add(const Color &c) const;
  Color Sub(const Color &c) const;

  float red, green, blue;
};

#endif /* COLOR_H_ */
