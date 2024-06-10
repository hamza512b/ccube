#include <math.h>
#include "matrix.h"
#include "canvas.h"

M44 rotation_matrix_x(double angle)
{
    M44 m = identity_matrix();
    m.m[1][1] = cos(angle);
    m.m[1][2] = -sin(angle);
    m.m[2][1] = sin(angle);
    m.m[2][2] = cos(angle);
    return m;
}

M44 rotation_matrix_y(double angle)
{
    M44 m = identity_matrix();
    m.m[0][0] = cos(angle);
    m.m[0][2] = sin(angle);
    m.m[2][0] = -sin(angle);
    m.m[2][2] = cos(angle);
    return m;
}

M44 rotation_matrix_z(double angle)
{
    M44 m = identity_matrix();
    m.m[0][0] = cos(angle);
    m.m[0][1] = -sin(angle);
    m.m[1][0] = sin(angle);
    m.m[1][1] = cos(angle);
    return m;
}

M44 translation_matrix(double tx, double ty, double tz)
{
    M44 m = identity_matrix();
    m.m[0][3] = tx;
    m.m[1][3] = ty;
    m.m[2][3] = tz;
    return m;
}

M44 scaling_matrix(double sx, double sy, double sz)
{
    M44 m = identity_matrix();
    m.m[0][0] = sx;
    m.m[1][1] = sy;
    m.m[2][2] = sz;
    return m;
}

M44 projection_matrix(double fov, double aspect, double near, double far)
{
    M44 m = {0};
    double f = 1.0 / tan(fov / 2.0);
    m.m[0][0] = f / aspect;
    m.m[1][1] = f;
    m.m[2][2] = (far + near) / (near - far);
    m.m[2][3] = (2 * far * near) / (near - far);
    m.m[3][2] = -1;
    return m;
}

// Compute back-face culling
int is_back_face(const V3 *v1, const V3 *v2, const V3 *v3)
{
    V3 v1v2 = {v2->x - v1->x, v2->y - v1->y, v2->z - v1->z};
    V3 v1v3 = {v3->x - v1->x, v3->y - v1->y, v3->z - v1->z};
    V3 normal = cross_product(&v1v2, &v1v3);
    V3 view = {0, 0, 1};
    return dot_product(&normal, &view) < 0;
}