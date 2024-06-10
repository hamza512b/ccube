#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "matrix.h"

typedef struct
{
    V3 vertices[36];
    int faceColors[6];
} Cube;

// Global variable for the cube (clockwise order so culling works)
Cube cube = {
    .vertices = {
        // Front face
        {-1, -1, -1}, {1, -1, -1}, {1, 1, -1},
        {-1, -1, -1}, {1, 1, -1}, {-1, 1, -1},

     

        // Back face
        {1, -1, 1}, {-1, -1, 1}, {-1, 1, 1},
        {1, -1, 1}, {-1, 1, 1}, {1, 1, 1},
        
        // Left face
        {-1, -1, 1}, {-1, -1, -1}, {-1, 1, -1},
        {-1, -1, 1}, {-1, 1, -1}, {-1, 1, 1},

        // Right face
        {1, -1, -1}, {1, -1, 1}, {1, 1, 1},
        {1, -1, -1}, {1, 1, 1}, {1, 1, -1},

        // Top face
        {-1, 1, -1}, {1, 1, -1}, {1, 1, 1},
        {-1, 1, -1}, {1, 1, 1}, {-1, 1, 1},

        // Bottom face
        {1, -1, -1}, {-1, -1, -1}, {-1, -1, 1},
        {1, -1, -1}, {-1, -1, 1}, {1, -1, 1},
    },
};
M44 rotation_matrix_x(double angle);

M44 rotation_matrix_y(double angle);

M44 rotation_matrix_z(double angle);

M44 translation_matrix(double tx, double ty, double tz);

M44 scaling_matrix(double sx, double sy, double sz);

M44 projection_matrix(double fov, double aspect, double near, double far);

int is_back_face(V3 *v0, V3 *v1, V3 *v2);
#endif
