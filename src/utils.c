#include "canvas.h"

void swap_vertices(Vertex2d *v1, Vertex2d *v2)
{
    int tempx = v1->x;
    int tempy = v1->y;

    v1->x = v2->x;
    v1->y = v2->y;

    v2->x = tempx;
    v2->y = tempy;
}

int cross_product_2d(const Vertex2d *v1, const Vertex2d *v2)
{
    return v1->x * v2->y - v1->y * v2->x;
}

