#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(void) {
    pid_t p;

    printf("creating process\n");
    if((p = fork()) == 0) { //Cria um novo processo (duplica o programa na memória)
        printf("child process\n");
        execl("/usr/bin/ls", "ls", "-l", NULL);
    } else {
        printf("main process with child PID %d\n", p);
        sleep(1);
    }

    return 0;
}