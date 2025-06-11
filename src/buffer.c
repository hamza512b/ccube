#include "buffer.h"

char buffer[BUFFER_SIZE];
int width;
int height;

void flush_buffer() {
    if (buffer_index > 0) {
        fwrite(buffer, 1, buffer_index, stdout);
        fflush(stdout);
        buffer_index = 0;
    }
}

void add_to_buffer(const char str[13], const int x, const int y) {
    int buffer_index = y * (canvas_width + 1) * 13 + x * 13;
    strcpy(buffer, str);
}

