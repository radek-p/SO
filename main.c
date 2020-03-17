#include <stdio.h>
#include <stdint.h>

#include "ex1_square.h"
#include "ex2_mul_div.h"
#include "ex3_passing_arguments.h"
#include "ex4_passing_arguments2.h"
#include "ex5_casts.h"
#include "ex6.h"

void exercise1() {
    int n = -20;
    printf("ssquare(%d) == %ld\n", n, ssquare(n));
    printf("usquare(%d) == %lu\n\n", n, usquare(n));
}

void exercise2() {
    printf("%ld, %ld, %lu, %lu, %ld, %ld, %lu, %lu\n\n",
            sddiv(1),
            ssdiv(2),
            uddiv(3),
            usdiv(4),
            smmul(5),
            ssmul(6),
            ummul(7),
            usmul(8)
    );
}

void exercise3() {
    bar1();
}

void exercise4() {
    bar2();
}

void exercise5() {
    printf("%d\n", foo14(-20));
    printf("%u\n", foo15(-20));
}

void exercise6() {
    uint128_t a = (uint128_t) { 0xB101010101010101,  0xA101010101010101};
    uint128_t x = (uint128_t) { 0xB90A0B0C0D0E0F01, 0xA102030405060708 };
    uint128_t y = (uint128_t) { 0xB100010001000100, 0xA100010001000100 };
    uint128_t res = mac(&a, &x, &y);
    printf("hi: %lu, lo: %lu", res.hi, res.lo);
}

void exercise6b() {
    __uint128_t a = ((__uint128_t)0xA101010101010101 << 64) | 0xB101010101010101;
    __uint128_t x = ((__uint128_t)0xA102030405060708 << 64) | 0xB90A0B0C0D0E0F01;
    __uint128_t y = ((__uint128_t)0xA100010001000100 << 64) | 0xB100010001000100;
    __uint128_t res = mac128(a, x, y);
    __uint128_t res2 = mac128(res, x, y);
}


int main() {
    exercise1();
    exercise2();
    exercise3();
    exercise4();
    exercise5();
    exercise6();
    exercise6b();
    return 0;
}