#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(void) {
    pid_t p;

    printf("creating process\n");
    if((p = fork()) == 0) { //Cria um novo processo
        printf("child process\n");
    } else {
        printf("main process with child PID %d\n", p);
    }

    return 0;
}