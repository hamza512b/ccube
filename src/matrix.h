#ifndef MATRIX_H
#define MATRIX_H
#define M_PI 3.14159265358979323846

typedef struct {
    int x;
    int y;
} Vertex2d;

typedef struct {
    float x;
    float y;
    float z;
} Vertex3d;

typedef struct {
    float x;
    float y;
    float z;
    float w;
} Vertex4d;

typedef struct {
    float m[4][4];
} Matrix4;

// Multiply a vertex by a matrix
Vertex4d multiply_vertex_matrix(const Vertex4d *v, const Matrix4 *m);

// Multiply two matrices
Matrix4 multiply_matrices(const Matrix4 *m1, const Matrix4 *m2);

// Identity matrix
Matrix4 identity_matrix();

// Function to compute the cross product of two vectors
Vertex3d cross_product(Vertex3d* v1, Vertex3d* v2);

// Function to compute the dot product of two vectors
float dot_product(Vertex3d* v1, Vertex3d* v2);

Vertex3d vertex4d_to_3d(Vertex4d* v);

Vertex4d vertex3d_to_4d(const Vertex3d *v);

Vertex2d project_vertex(const Vertex4d *v);

#endif
