#include <stdio.h>

void foo1(long a, int b, short c, signed char d, unsigned char e, unsigned short f, unsigned int g, unsigned long h) {
    printf("%ld, %d, %d, %d, %d, %d, %d, %lu\n\n", a, b, c, d, e, f, g, h);
}

void bar1() {
    foo1(1, 2, 3, 4, 5, 6, 7, 8);
}