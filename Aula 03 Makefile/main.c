#include <stdio.h>
#include <stdlib.h>
#include "square.h"

int main(int args, char* argv[]) {

    //Compilação condicional
    #ifdef OPTION2
    double x = 3;
    //Para definir OPTION2 de forma externa, é possível utilizar o Makefile

    #else
    double x;
    scanf("%lf", &x);
    
    #endif

    printf("Quadrado de %.2f é %.2f\n", x, square(x));
    return 0;
}