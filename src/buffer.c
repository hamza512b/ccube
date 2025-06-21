#include "buffer.h"
#include <stdlib.h>

const char *CLER_ESCAPE_STR = "\033[H\033[J";

extern int canvas_width;
extern int canvas_height;
extern char *buffer;

char *init_buffer()
{
    char *buffer = malloc(canvas_height * (canvas_width + 1) * STR_SIZE);
    return buffer;
}

void flush_buffer()
{
    // FLush
    fwrite(CLER_ESCAPE_STR, sizeof(char), strlen(CLER_ESCAPE_STR), stdout);
    char *str = buffer;
    for (int i = 0; i <= STR_SIZE * canvas_height * (canvas_width + 1); str++, i++)
    {
        // If it is end line chunk

        if (*str != '\0')
        {
            fputc(*str, stdout);
            continue;
        }
    }
    fflush(stdout);

    // Reset
    str = buffer;
    for (int i = 0; i <= STR_SIZE * canvas_height * (canvas_width + 1); str++, i++)
    {
        if (i % (STR_SIZE * (canvas_width + 1)) == 0)
        {

            *str = '\n';
            continue;
        }
        if (i % STR_SIZE == 0)
        {

            *str = ' ';
            continue;
        }
        *str = '\0';
    }
}

void add_to_buffer(const char *str, const int x, const int y)
{
    char *buffer_ptr = buffer + (y * (canvas_width + 1) * STR_SIZE + x * STR_SIZE);
    int i = 0;
    for (; i < STR_SIZE && str[i] != '\0'; i++)
    {
        *buffer_ptr = str[i];
        buffer_ptr++;
    }
}
