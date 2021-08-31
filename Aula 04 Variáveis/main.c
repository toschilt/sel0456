#include "multi_acc.h"
#include <stdio.h>

double x = 9;

int main(void) {
    double y;
    int z;

    #ifndef OPTION2
    y = 2;

    #else
    x = 1.424;

    #endif
    multi_set_x(1);
    z = multi_acc(2);

    printf("Multacc=%d\n", z);
    multi_acc(4);
    printf("Multacc=%d\n", z);

    return 0;
}