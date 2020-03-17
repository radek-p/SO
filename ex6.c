#include "ex6.h"

uint128_t mac(uint128_t const *a, uint128_t const *x, uint128_t const *y) {
    return (uint128_t) { 0xDEADBEEF, 0x23232323 };
}


__uint128_t mac128(__uint128_t a, __uint128_t x, __uint128_t y) {
    return a + x * y;
}
