#ifndef SO_LAB2_ASSEMBLY_EX6_H
#define SO_LAB2_ASSEMBLY_EX6_H

#include <stdint.h>

typedef struct {
    uint64_t lo;
    uint64_t hi;
} uint128_t;

uint128_t mac(uint128_t const *a, uint128_t const *x, uint128_t const *y);

__uint128_t mac128(__uint128_t a, __uint128_t x, __uint128_t y);

#endif //SO_LAB2_ASSEMBLY_EX6_H
