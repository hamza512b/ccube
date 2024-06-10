#ifndef UTILS_H
#define UTILS_H

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

void swap_vertices(V2 *v1, V2 *v2);
int cross_product_2d(const V2 *v1, const V2 *v2);
#endif
