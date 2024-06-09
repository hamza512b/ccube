#ifndef UTILS_H
#define UTILS_H

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

void swap_vertices(Vertex2d *v1, Vertex2d *v2);
int cross_product_2d(const Vertex2d *v1, const Vertex2d *v2);
#endif
