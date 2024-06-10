#include "canvas.h"

void swap_vertices(V2 *v1, V2 *v2)
{
    int tempx = v1->x;
    int tempy = v1->y;

    v1->x = v2->x;
    v1->y = v2->y;

    v2->x = tempx;
    v2->y = tempy;
}

int cross_product_2d(const V2 *v1, const V2 *v2)
{
    return v1->x * v2->y - v1->y * v2->x;
}

