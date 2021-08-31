#include <stdlib.h>
#include <stdio.h>

#include "sqr.h"
#include "mult_acc.h"
#include <pthread.h>

double x = 9;

void *count(void *ptr) {
    volatile unsigned int i;
    for(i = 0; i < 0xfffffff; i++);
    printf("finished in thread\n");
    return NULL;
}

int main(void) {

    double y;
    int z;

    pthread_t thr;

    #ifdef OPTION2
    y = 2;
    #else
    x = 1.4142;
    #endif

    int r = pthread_create(&thr, NULL, count, NULL);

    printf("O quadrado de %g é %g\n", y, sqr(y));
    /* inicializar x no módulo mult_acc */
    mult_set_x(1);
    z = mult_acc(2);
    printf("multacc=%d\n", z);
    z = mult_acc(4);
    printf("multacc=%d\n", z);

    volatile unsigned int i;
    for(i = 0; i < 0xfffffff; i++);
    printf("finished in main\n");

    return 0;
}