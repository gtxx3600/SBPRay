/*
 * PPMFile.cpp
 *
 *  Created on: May 13, 2012
 *      Author: skaby
 */

#include "pic/PPMFile.h"

#include <fstream>
using namespace std;
#include "base/Color.h"

const char *PPMFile::kMagicNumber = "P3";


PPMFile::PPMFile(int w, int h)
    : kWidth(w), kHeight(h), kSize(w*h), kMaxColorVal(255) {
  data = new Pixel [kSize];
}

PPMFile::~PPMFile() {
  delete [] data;
}

void PPMFile::DataCopy(const Color color_arr[], int start, int len) {
  for (int i = 0; i < len; ++i) {
    Pixel *dst = &(data[start+i]);
    const Color *src = &(color_arr[i]);
    dst->red = color_f2i(src->red);
    dst->green = color_f2i(src->green);
    dst->blue = color_f2i(src->blue);
  }
}

void PPMFile::Save(const char *filename) {
  ofstream fout(filename);
  fout << kMagicNumber << endl;
  fout << kWidth << ' ' << kHeight << endl;
  fout << kMaxColorVal << endl;
  for (int j = 0; j < kHeight; ++j) {
    for (int i = 0; i < kWidth; ++i) {
      if (i) fout << ' ';
      Pixel *p = &(data[j*kWidth + i]);
      fout << p->red << ' ' << p->green << ' ' << p->blue;
    }
    fout << endl;
  }
  fout.close();
}
