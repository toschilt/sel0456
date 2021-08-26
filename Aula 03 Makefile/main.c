#include <stdio.h>
#include <stdlib.h>
#include "square.h"

int main(int args, char* argv[]) {
    double x;
    scanf("%lf", &x);
    printf("Quadrado de %.2f é %.2f\n", x, square(x));
    return 0;
}