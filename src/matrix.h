#ifndef MATRIX_H
#define MATRIX_H
#define M_PI 3.14159265358979323846

typedef struct
{
    int x;
    int y;
} V2;

typedef struct
{
    double x;
    double y;
    double z;
} V3;

typedef struct
{
    double m[4][4];
} M44;

// Multiply a vertex by a matrix
V3 multiply_vertex_matrix(const V3 *v, const M44 *m);

// Multiply two matrices
M44 multiply_matrices(const M44 *m1, const M44 *m2);

// Identity matrix
M44 identity_matrix();

// Function to compute the cross product of two vectors
V3 cross_product(V3 *v1, V3 *v2);

// Function to compute the dot product of two vectors
double dot_product(V3 *v1, V3 *v2);

#endif
