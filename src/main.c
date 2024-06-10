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
    if (argc == 2)
    {
        canvas_height = atoi(argv[1]);
        canvas_width = canvas_height;
    }

    if (argc == 3)
    {
        canvas_height = atoi(argv[1]);
        canvas_width = atoi(argv[2]);
    }

    if (argc != 2 && argc != 3)
    {
        printf("Usage: %s <canvas_height> <canvas_width>\n", argv[0]);
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator with the current time

    double i = 0;
    double j = M_PI / 2;
    while (1)
    {
        // Define transformation parameters
        double angle_x = (i += 0.075);
        double angle_y = (j += 0.05);
        double angle_z = 0;
        double tx = 0, ty = 2.2, tz = 10;
        double sx = 1, sy = 1, sz = 1;
        double fov = M_PI / 4; // 45 degrees
        double aspect = 0.5;   // 1:2 aspect ratio
        double near = 0.1, far = 100.0;

        // Combine the transformation matrices
        M44 transformation = identity_matrix();

        M44 projection = projection_matrix(fov, aspect, near, far);
        transformation = multiply_matrices(&transformation, &projection);

        M44 translation = translation_matrix(tx, ty, tz);
        transformation = multiply_matrices(&transformation, &translation);

        M44 rotation_z = rotation_matrix_z(angle_z);
        transformation = multiply_matrices(&transformation, &rotation_z);

        M44 rotation_y = rotation_matrix_y(angle_y);
        transformation = multiply_matrices(&transformation, &rotation_y);

        M44 rotation_x = rotation_matrix_x(angle_x);
        transformation = multiply_matrices(&transformation, &rotation_x);

        M44 scaling = scaling_matrix(sx, sy, sz);
        transformation = multiply_matrices(&transformation, &scaling);

        // Clear screen and draw the transformed and projected cube
        clear_screen();

        int currnet_color = -1;
        // Draw the cube
        for (int k = 0; k < 36; k += 3)
        {
            V3 v1 = cube.vertices[k];
            V3 v2 = cube.vertices[k + 1];
            V3 v3 = cube.vertices[k + 2];

            // Transform vertices
            V3 v1_transformed = multiply_vertex_matrix(&v1, &transformation);
            V3 v2_transformed = multiply_vertex_matrix(&v2, &transformation);
            V3 v3_transformed = multiply_vertex_matrix(&v3, &transformation);

            // Back-face culling
            if (is_back_face(&v1_transformed, &v2_transformed, &v3_transformed))
                continue;

            // Project vertices
            V2 v1_projected = {(v1_transformed.x / v1_transformed.z + 1) * canvas_width / 2,
                               (v1_transformed.y / v1_transformed.z + 1) * canvas_height / 2};
            V2 v2_projected = {(v2_transformed.x / v2_transformed.z + 1) * canvas_width / 2,
                               (v2_transformed.y / v2_transformed.z + 1) * canvas_height / 2};
            V2 v3_projected = {(v3_transformed.x / v3_transformed.z + 1) * canvas_width / 2,
                               (v3_transformed.y / v3_transformed.z + 1) * canvas_height / 2};

            // Draw the triangle
            int col = (int)(k / 6);
            draw_triangle(&v1_projected, &v2_projected, &v3_projected, col);
        }

        flush_buffer();
        usleep(500000); // sleep for 500 milliseconds
    }
    printf("\n");
    return 0;
}
