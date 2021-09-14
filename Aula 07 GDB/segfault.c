#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = (char*)malloc(1024);
    ptr[1024] = 2;
}