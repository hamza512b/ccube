#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "matrix.h"

typedef struct {
    Vertex3d vertices[36];
    int faceColors[6];
} Cube;

// Global variable for the , initialized directly
Cube cube = {
    .vertices = {
        // Front face
        {-1, -1, -1}, {1, -1, -1}, {1, 1, -1},
        {-1, -1, -1}, {1, 1, -1}, {-1, 1, -1},

        // Back face
        {-1, -1, 1}, {-1, 1, 1}, {1, 1, 1},
        {-1, -1, 1}, {1, 1, 1}, {1, -1, 1},

        // Left face
        {-1, -1, -1}, {-1, 1, -1}, {-1, 1, 1},
        {-1, -1, -1}, {-1, 1, 1}, {-1, -1, 1},

        // Right face
        {1, -1, -1}, {1, -1, 1}, {1, 1, 1},
        {1, -1, -1}, {1, 1, 1}, {1, 1, -1},

        // Top face
        {-1, 1, -1}, {1, 1, -1}, {1, 1, 1},
        {-1, 1, -1}, {1, 1, 1}, {-1, 1, 1},

        // Bottom face
        {-1, -1, -1}, {-1, -1, 1}, {1, -1, 1},
        {-1, -1, -1}, {1, -1, 1}, {1, -1, -1}
    },
    .faceColors = {0, 1, 2, 3, 4, 5} // Colors for each face
};

Matrix4 rotation_matrix_x(float angle);

Matrix4 rotation_matrix_y(float angle);

Matrix4 rotation_matrix_z(float angle);

Matrix4 translation_matrix(float tx, float ty, float tz);

Matrix4 scaling_matrix(float sx, float sy, float sz);

Matrix4 projection_matrix(float fov, float aspect, float near, float far);

int is_back_face(Vertex4d* v0, Vertex4d* v1, Vertex4d* v2);
#endif
