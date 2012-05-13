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
  Color();
  Color(float r, float g, float b);
  Color Multiply(float a);
  Color Add(Color &c);
  Color Sub(Color &c);

  float red, green, blue;
};

#endif /* COLOR_H_ */
