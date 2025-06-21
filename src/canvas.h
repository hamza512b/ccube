#ifndef CANVAS_H
#define CANVAS_H

#include "matrix.h"

void draw_point(int x, int y, int intensity);
void draw_triangle(const V2 *v1, const V2 *v2, const V2 *v3, int intensity);

#endif
