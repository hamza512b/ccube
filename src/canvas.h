#ifndef CANVAS_H
#define CANVAS_H

#include "matrix.h"

void clear_screen();
void draw_point(int x, int y, int intensity);
void draw_triangle(const Vertex2d *v1, const Vertex2d *v2, const Vertex2d *v3, int intensity);

#endif
