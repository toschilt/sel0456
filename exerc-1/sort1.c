#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char data[4096];
    int key;
} item_t;

item_t array[] = {
        {"bill", 3},
        {"neil", 4},
        {"john", 2},
        {"rick", 5},
        {"alex", 1},
        };

void sort(item_t * a, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++)
            if(a[j].key > a[j+1].key) {
                item_t t;
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
    }
}

int main(void) {
    printf("ALuno: Felipe Alvarenga Carvalho - 10310526\n");
    printf("Executando arquivo sort.c\n");
    sort(array,5);
    for(int i = 0; i < 5; i++)
        printf("array[%d] = {%s, %d}\n", i, array[i].data, array[i].key);
}
