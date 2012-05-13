/*
 * Sphere.cpp
 *
 *  Created on: May 13, 2012
 *      Author: skaby
 */

#include "Sphere.h"

Sphere::Sphere() : position(), radius(0.0) {
}

Sphere::Sphere(const Vec &p, float r)
    : position(p), radius(r) {
}
