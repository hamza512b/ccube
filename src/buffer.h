#ifndef BUFFER_H
#define BUFFER_H

#include <stdio.h>
#include <string.h>

#define STR_SIZE 30

char *init_buffer();
void flush_buffer();
void add_to_buffer(const char *str, const int x, const int y);

#endif // BUFFER_H
