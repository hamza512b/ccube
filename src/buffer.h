#ifndef BUFFER_H
#define BUFFER_H

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1300

extern char buffer[BUFFER_SIZE];
extern int buffer_index;

void flush_buffer();
void add_to_buffer(const char str[13], const int x, const int y);

#endif // BUFFER_H

