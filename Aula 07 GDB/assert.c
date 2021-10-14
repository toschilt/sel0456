#include <stdio.h>
#include <assert.h>

int main() {
    int x;
    printf("Insira um numero positivo: ");
    scanf("%d", &x);
    assert(x > 0);
}