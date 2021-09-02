#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> //Threads
#include <unistd.h> //Sleep
#include <semaphore.h> //Semáforos

#include "sqr.h"
#include "mult_acc.h"

double x = 9;
sem_t sem;

void *count(void *ptr) {
    volatile unsigned int i;
    int n = *(int*)ptr;
    for(i = 0; i < 0xfffffff; i++);
    // printf("finished in thread %d\n", n);

    sem_wait(&sem);
    printf("critical code in thread %d\n", n);
    sleep(1);
    sem_post(&sem);
    // Apenas uma thread passa por esse trecho de código por vez

    printf("exiting thread %d\n", n);
    pthread_exit(NULL); //Valor de retorno da thread, é salvo no ponteiro de pthread_join
    return NULL;
}

int main(void) {

    double y;
    int z;

    sem_init(&sem, 0, 2);
    //Endereço do semáforo, shared, quantidade de tarefas que podem acessá-lo por vez

    pthread_t thr[3];

    #ifdef OPTION2
    y = 2;
    #else
    x = 1.4142;
    #endif

    for(int n = 0; n < 3; n++) {
        int r = pthread_create(&(thr[n]), NULL, count, &n);
        if(r == 0) { printf("created thread %d\n", n); }
    }
    
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
    sleep(4);
    printf("finished in main\n");


    pthread_join(thr[0], NULL);
    pthread_join(thr[1], NULL);
    pthread_join(thr[2], NULL);
    //Faz com que a main espere a finalização da thread para encerrar o programa

    return 0;
}