#include <math.h>
#include "matrix.h"
#include "canvas.h"

Matrix4 rotation_matrix_x(float angle) {
    Matrix4 m = identity_matrix();
    m.m[1][1] = cos(angle);
    m.m[1][2] = -sin(angle);
    m.m[2][1] = sin(angle);
    m.m[2][2] = cos(angle);
    return m;
}

Matrix4 rotation_matrix_y(float angle) {
    Matrix4 m = identity_matrix();
    m.m[0][0] = cos(angle);
    m.m[0][2] = sin(angle);
    m.m[2][0] = -sin(angle);
    m.m[2][2] = cos(angle);
    return m;
}

Matrix4 rotation_matrix_z(float angle) {
    Matrix4 m = identity_matrix();
    m.m[0][0] = cos(angle);
    m.m[0][1] = -sin(angle);
    m.m[1][0] = sin(angle);
    m.m[1][1] = cos(angle);
    return m;
}

Matrix4 translation_matrix(float tx, float ty, float tz) {
    Matrix4 m = identity_matrix();
    m.m[0][3] = tx;
    m.m[1][3] = ty;
    m.m[2][3] = tz;
    return m;
}

Matrix4 scaling_matrix(float sx, float sy, float sz) {
    Matrix4 m = identity_matrix();
    m.m[0][0] = sx;
    m.m[1][1] = sy;
    m.m[2][2] = sz;
    return m;
}

Matrix4 projection_matrix(float fov, float aspect, float near, float far) {
    Matrix4 m = {0};
    float tan_half_fov = tan(fov / 2.0);

    m.m[0][0] = 1.0 / (aspect * tan_half_fov);
    m.m[1][1] = 1.0 / tan_half_fov;
    m.m[2][2] = -(far + near) / (far - near);
    m.m[2][3] = -(2.0 * far * near) / (far - near);
    m.m[3][2] = -1.0;
    
    return m;
}

// Function to determine if the face should be culled
int is_back_face(Vertex4d* v0, Vertex4d* v1, Vertex4d* v2) {
    Vertex3d v3d0 = vertex4d_to_3d(v0);
    Vertex3d v3d1 = vertex4d_to_3d(v1);
    Vertex3d v3d2 = vertex4d_to_3d(v2);

    Vertex3d edge1 = {v3d1.x - v3d0.x, v3d1.y - v3d0.y, v3d1.z - v3d0.z};
    Vertex3d edge2 = {v3d2.x - v3d0.x, v3d2.y - v3d0.y, v3d2.z - v3d0.z};

    Vertex3d normal = cross_product(&edge1, &edge2);

    Vertex3d camera_to_vertex = {v3d0.x, v3d0.y, v3d0.z};

    return dot_product(&normal, &camera_to_vertex) >= 0;
}

