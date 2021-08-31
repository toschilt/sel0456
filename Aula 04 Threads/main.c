#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "sqr.h"
#include "mult_acc.h"

double x = 9;

void *count(void *ptr) {
    volatile unsigned int i;
    for(i = 0; i < 0xfffffff; i++);
    printf("finished in thread\n");
    pthread_exit(NULL); //Valor de retorno da thread, é salvo no ponteiro de pthread_join
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
    //Cria uma nova thread

    printf("O quadrado de %g é %g\n", y, sqr(y));
    /* inicializar x no módulo mult_acc */
    mult_set_x(1);
    z = mult_acc(2);
    printf("multacc=%d\n", z);
    z = mult_acc(4);
    printf("multacc=%d\n", z);

    // volatile unsigned int i;
    // for(i = 0; i < 0xfffffff; i++);
    sleep(10); 
    printf("finished in main\n");


    pthread_join(thr, NULL);
    //Faz com que a main espere a finalização da thread para encerrar o programa

    return 0;
}