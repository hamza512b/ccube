#include <math.h>
#include "matrix.h"

// Multiply a vertex by a matrix
V3 multiply_vertex_matrix(const V3 *v, const M44 *m)
{
    V3 result = {0};
    result.x = v->x * m->m[0][0] + v->y * m->m[0][1] + v->z * m->m[0][2] + m->m[0][3];
    result.y = v->x * m->m[1][0] + v->y * m->m[1][1] + v->z * m->m[1][2] + m->m[1][3];
    result.z = v->x * m->m[2][0] + v->y * m->m[2][1] + v->z * m->m[2][2] + m->m[2][3];

    double w = v->x * m->m[3][0] + v->y * m->m[3][1] + v->z * m->m[3][2] + m->m[3][3];
    if (w != 0)
    {
        result.x /= w;
        result.y /= w;
        result.z /= w;
    }
    return result;
}

// Multiply two matrices
M44 multiply_matrices(const M44 *m1, const M44 *m2)
{
    M44 result = {0};
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 4; ++k)
                result.m[i][j] += m1->m[i][k] * m2->m[k][j];
        }
    }
    return result;
}

// Identity matrix
M44 identity_matrix()
{
    M44 m = {0};
    for (int i = 0; i < 4; ++i)
    {
        m.m[i][i] = 1.0f;
    }
    return m;
}

// Function to compute the cross product of two vectors
V3 cross_product(V3 *v1, V3 *v2)
{
    V3 result = {0};
    result.x = v1->y * v2->z - v1->z * v2->y;
    result.y = v1->z * v2->x - v1->x * v2->z;
    result.z = v1->x * v2->y - v1->y * v2->x;
    return result;
}

// Function to compute the dot product of two vectors
double dot_product(V3 *v1, V3 *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}
