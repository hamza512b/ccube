#include "buffer.h"

char buffer[BUFFER_SIZE];
int buffer_index = 0;

void flush_buffer() {
    if (buffer_index > 0) {
        fwrite(buffer, 1, buffer_index, stdout);
        fflush(stdout);
        buffer_index = 0;
    }
}

void add_to_buffer(const char *str) {
    int len = strlen(str);
    if (buffer_index + len >= BUFFER_SIZE) {
        flush_buffer();
    }
    strcpy(buffer + buffer_index, str);
    buffer_index += len;
}

