/*
 * PPMFile.h
 *
 *  Created on: May 13, 2012
 *      Author: skaby
 */

#ifndef PPMFILE_H_
#define PPMFILE_H_

typedef struct {
  int red, green, blue;
} Pixel;

class Color;
class PPMFile {
public:
  PPMFile(int w, int h);
  virtual ~PPMFile();
  void DataCopy(const Color color_arr[], int start, int len);
  void Save(const char *filename);

private:
  static const char *kMagicNumber;
  int color_f2i(float f) {return static_cast<int>(f*kMaxColorVal);}
  const int kWidth;
  const int kHeight;
  const int kSize;
  const int kMaxColorVal;
  Pixel *data;
};

#endif /* PPMFILE_H_ */
