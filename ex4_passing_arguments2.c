#include <stdio.h>

void foo2(long a, long b, int c, int d) {
    printf("%ld, %ld, %d, %d\n\n", a, b, c, d);
}

void bar2() {
    foo2(0x123456789abcdef0, -1, 0x12345678, -1);
}
