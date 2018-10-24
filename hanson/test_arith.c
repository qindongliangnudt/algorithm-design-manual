#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "arith.h"

#define TRUE 0
#define FALSE -1

int test_max(int x, int y, int result);
int test_min(int x, int y, int result);
int test_div(int x, int y, int result);
int test_mod(int x, int y, int result);
int test_ceiling(int x, int y, int result);
int test_floor(int x, int y, int result);

int main(int argc, char *argv[]) {
    div_t mydiv = div(-13, 5);
    printf("the quotient is %d and the rem is %d\n", mydiv.quot, mydiv.rem);
    printf("test for max is %d\n", test_max(1, 2, 2));
    printf("test for min is %d\n", test_min(1, 2, 1));
    printf("test for div is %d\n", test_div(-13, 5, -3));
    printf("test for div is %d\n", test_div(-10, 5, -2));
    printf("test for mod is %d\n", test_mod(-13, 5, 2));
    printf("test for mod is %d\n", test_mod(-10, 5, 0));
    printf("test for ceiling is %d\n", test_ceiling(-13, 5, -2));
    printf("test for ceiling is %d\n", test_ceiling(-10, 5, -2));
    printf("test for floot is %d\n", test_floor(-13, 5, -3));
    printf("test for floot is %d\n", test_floor(-10, 5, -2));

    return 0;
}

int test_max(int x, int y, int result) {
    if (Arith_max(x, y) == result)
        return TRUE;
    else
        return FALSE;
}
int test_min(int x, int y, int result) {
    if (Arith_min(x, y) == result)
        return TRUE;
    else
        return FALSE;
}

int test_div(int x, int y, int result) {
    if (Arith_div(x, y) == result)
        return TRUE;
    else
        return FALSE;
}

int test_mod(int x, int y, int result){
    if (Arith_mod(x, y) == result) 
        return TRUE;
    else
        return FALSE;
}
int test_ceiling(int x, int y, int result) {
    if (Arith_ceiling(x, y) == result) 
        return TRUE;
    else
        return FALSE;
}

int test_floor(int x, int y, int result) {
    if (Arith_floor(x, y) == result) 
        return TRUE;
    else
        return FALSE;
}