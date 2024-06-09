#include <stdio.h>
#include "canvas.h"
#include "utils.h"
#include "buffer.h"

void clear_screen() {
    add_to_buffer("\033[H\033[J");
}

void draw_point(int x, int y, int intensity) {
    extern int canvas_width;
    extern int canvas_height;

    if (x > canvas_width || x < 0)
        return;

    if (y > canvas_height || y < 0)
        return;

    static const char *colors[] = {
        "\033[38;5;236m",
        "\033[38;5;240m",
        "\033[38;5;242m",
        "\033[38;5;247m",
        "\033[38;5;251m",
        "\033[38;5;255m", 
    };

    if (intensity < 0) intensity = 0;
    if (intensity > 5) intensity = 5;

    // Move cursor and set color
    char command[64];
    snprintf(command, sizeof(command), "\033[%d;%dH%s#\033[0m", y, x, colors[intensity]);
    add_to_buffer(command);
}

void draw_triangle(const Vertex2d *v1, const Vertex2d *v2, const Vertex2d *v3, int intensity)
{
    /* get the bounding box of the triangle */
    int maxX = MAX(v1->x, MAX(v2->x, v3->x));
    int minX = MIN(v1->x, MIN(v2->x, v3->x));
    int maxY = MAX(v1->y, MAX(v2->y, v3->y));
    int minY = MIN(v1->y, MIN(v2->y, v3->y));

    Vertex2d vs1 = {v2->x - v1->x, v2->y - v1->y};
    Vertex2d vs2 = {v3->x - v1->x, v3->y - v1->y};

    for (int x = minX; x <= maxX; x++)
    {
        for (int y = minY; y <= maxY; y++)
        {
            Vertex2d q = {x - v1->x, y - v1->y};

            float s = (float)cross_product_2d(&q, &vs2) / cross_product_2d(&vs1, &vs2);
            float t = (float)cross_product_2d(&vs1, &q) / cross_product_2d(&vs1, &vs2);

            if ((s >= 0) && (t >= 0) && (s + t <= 1))
            { /* inside triangle */
                draw_point(x, y, intensity);
            }
        }
    }
}


