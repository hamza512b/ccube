#include <math.h>
#include "matrix.h"

// Multiply a vertex by a matrix
Vertex4d multiply_vertex_matrix(const Vertex4d *v, const Matrix4 *m) {
    Vertex4d result;
    result.x = v->x * m->m[0][0] + v->y * m->m[0][1] + v->z * m->m[0][2] + v->w * m->m[0][3];
    result.y = v->x * m->m[1][0] + v->y * m->m[1][1] + v->z * m->m[1][2] + v->w * m->m[1][3];
    result.z = v->x * m->m[2][0] + v->y * m->m[2][1] + v->z * m->m[2][2] + v->w * m->m[2][3];
    result.w = v->x * m->m[3][0] + v->y * m->m[3][1] + v->z * m->m[3][2] + v->w * m->m[3][3];
    return result;
}

// Multiply two matrices
Matrix4 multiply_matrices(const Matrix4 *m1, const Matrix4 *m2) {
    Matrix4 result = {0};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.m[i][j] = m1->m[i][0] * m2->m[0][j] +
                             m1->m[i][1] * m2->m[1][j] +
                             m1->m[i][2] * m2->m[2][j] +
                             m1->m[i][3] * m2->m[3][j];
        }
    }
    return result;
}

// Identity matrix
Matrix4 identity_matrix() {
    Matrix4 m = {0};
    for (int i = 0; i < 4; ++i) {
        m.m[i][i] = 1.0f;
    }
    return m;
}

// Function to compute the cross product of two vectors
Vertex3d cross_product(Vertex3d* v1, Vertex3d* v2) {
    Vertex3d result;
    result.x = v1->y * v2->z - v1->z * v2->y;
    result.y = v1->z * v2->x - v1->x * v2->z;
    result.z = v1->x * v2->y - v1->y * v2->x;
    return result;
}

// Function to compute the dot product of two vectors
float dot_product(Vertex3d* v1, Vertex3d* v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

Vertex3d vertex4d_to_3d(Vertex4d* v) {
    Vertex3d result;
    result.x = v->x / v->w;
    result.y = v->y / v->w;
    result.z = v->z / v->w;
    return result;
}

Vertex4d vertex3d_to_4d(const Vertex3d *v) {
    return (Vertex4d){v->x, v->y, v->z, 1.0f};
}

Vertex2d project_vertex(const Vertex4d *v) {
    return (Vertex2d){v->x / v->w, v->y / v->w};
}

