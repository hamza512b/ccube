#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "canvas.h"
#include "utils.h"
#include "graphics.h"
#include "matrix.h"
#include "buffer.h"

int canvas_height, canvas_width;

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <canvas_height> <canvas_width>\n", argv[0]);
        return 1;
    }

    canvas_height = atoi(argv[1]);
    canvas_width = atoi(argv[2]);

    srand(time(NULL)); // Seed the random number generator with the current time

    float i = 0;
    float j = 0;
    while (1)
    {
//        Matrix4 transformation = identity_matrix();
//        Matrix4 m = identity_matrix();

//        m = projection_matrix(M_PI / 2.0f * 0.5, 1.0f, 0.1f, 100.0f); 
//        transformation = multiply_matrices(&transformation, &m);

//        m = rotation_matrix_y(i += 0.2);
//        transformation = multiply_matrices(&transformation, &m);

//        m = rotation_matrix_x(j + 0.15);
//        transformation = multiply_matrices(&transformation, &m);

//        m = scaling_matrix(1.0f, 1.0f, 1.0f);
//        transformation = multiply_matrices(&transformation, &m);

//        m = translation_matrix(25.0f, 10.0f, 2.0f);
//        transformation = multiply_matrices(&transformation, &m);


//        Matrix4 transformation = identity_matrix();
//        Matrix4 temp = identity_matrix();
//
//        // Apply scaling
//        temp = scaling_matrix(1, 1, 1);
//        transformation = multiply_matrices(&temp, &transformation);
//
//        // Apply rotation around X-axis
//        temp = rotation_matrix_x(j += 0.15);
//        transformation = multiply_matrices(&temp, &transformation);
//
//        // Apply rotation around Y-axis
//        temp = rotation_matrix_y(i += 0.2);
//        transformation = multiply_matrices(&temp, &transformation);
//
//        // Apply rotation around Z-axis
//        temp = rotation_matrix_z(0);
//        transformation = multiply_matrices(&temp, &transformation);
//
//
//        // Apply translation
//        temp = translation_matrix(10, 10, 2);
//        transformation = multiply_matrices(&temp, &transformation);
//
//        // Apply projection first (last in reverse order)
//        temp = projection_matrix(M_PI / 2.0f * 0.5, 0.5f, 0.1f, 100.0f);
//        transformation = multiply_matrices(&temp, &transformation);


    // Define transformation parameters
    float angle_x = (i += 0.1); 
    float angle_y = (j += 0.2);
    float angle_z = 0;
    float tx = 0, ty = 0, tz = 2;
    float sx = 20.0, sy = 20.0, sz = 20.0;
    float fov = M_PI / 4; // 45 degrees
    float aspect = 0.5; // 1:2 aspect ratio
    float near = 0.1, far = 100.0;

    // Create transformation matrices
    Matrix4 scale_matrix = scaling_matrix(sx, sy, sz);
    Matrix4 rotation_matrix_X = rotation_matrix_x(angle_x);
    Matrix4 rotation_matrix_Y = rotation_matrix_y(angle_y);
    Matrix4 rotation_matrix_Z = rotation_matrix_z(angle_z);
    Matrix4 translate_matrix = translation_matrix(tx, ty, tz);
    Matrix4 proj_matrix = projection_matrix(fov, aspect, near, far);

    // Combine transformations: Model = Scale * RotationZ * RotationY * RotationX * Translation
    Matrix4 model_matrix = multiply_matrices(&scale_matrix, &rotation_matrix_Z);
    model_matrix = multiply_matrices(&model_matrix, &rotation_matrix_Y);
    model_matrix = multiply_matrices(&model_matrix, &rotation_matrix_X);
    model_matrix = multiply_matrices(&model_matrix, &translate_matrix);

    // View-projection matrix
    Matrix4 view_projection_matrix = proj_matrix; // Assuming the view matrix is identity for simplicity

    // Final transformation matrix
    Matrix4 transformation = multiply_matrices(&view_projection_matrix, &model_matrix);

       
// for debuging
//        Matrix4 transformation = {.m = {{2.41421342, 0, -25, 0}, {0, 2.41421342, -10, 0}, {0, 0, -3.002002, -0.2002002}, {0, 0, -1, 0}}};
       

        // Clear screen and draw the transformed and projected cube
        clear_screen();

        flush_buffer();
        usleep(500000); // sleep for 500 milliseconds
    }
    printf("\n");
    return 0;
}
