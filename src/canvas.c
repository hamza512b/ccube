#include <stdio.h>
#include "canvas.h"
#include "utils.h"
#include "buffer.h"

void clear_screen()
{
    add_to_buffer("\033[H\033[J");
}

void draw_point(int x, int y, int intensity)
{
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
    char str[13];
    snprintf(command, sizeof(command), "%s#\033[0m", colors[intensity]);
    add_to_buffer(command, x, y);
}

void draw_triangle(const V2 *v1, const V2 *v2, const V2 *v3, int intensity)
{
    /* get the bounding box of the triangle */
    int maxX = MAX(v1->x, MAX(v2->x, v3->x));
    int minX = MIN(v1->x, MIN(v2->x, v3->x));
    int maxY = MAX(v1->y, MAX(v2->y, v3->y));
    int minY = MIN(v1->y, MIN(v2->y, v3->y));

    V2 vs1 = {v2->x - v1->x, v2->y - v1->y};
    V2 vs2 = {v3->x - v1->x, v3->y - v1->y};

    for (int x = minX; x <= maxX; x++)
    {
        for (int y = minY; y <= maxY; y++)
        {
            V2 q = {x - v1->x, y - v1->y};

            double s = (double)cross_product_2d(&q, &vs2) / cross_product_2d(&vs1, &vs2);
            double t = (double)cross_product_2d(&vs1, &q) / cross_product_2d(&vs1, &vs2);

            if ((s >= 0) && (t >= 0) && (s + t <= 1))
            { /* inside triangle */
                draw_point(x, y, intensity);
            }
        }
    }
}
