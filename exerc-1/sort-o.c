#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define ERRO (-32000)

typedef struct item_t ITEM;
struct item_t {
    char *data;
    int key;
};

ITEM *item_criar(char *data, int key);
int item_apagar(ITEM **item);
char *item_get_data(ITEM *item);
int item_get_key(ITEM *item);


//Dados de entrada são obtidos pelo array "inputs[]"
//Implementação permite que o tamanho do vetor de inputs seja variável assim como seus nomes
ITEM inputs[] = {
        {"bill", 3},
        {"neil", 4},
        {"john", 2},
        {"rick", 5},
        {"alex", 1},
        };


void sort(ITEM **a, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++)
            if(item_get_key(a[j]) > item_get_key(a[j+1])) {
                ITEM *t;
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
    }
}

int main(void) {
    printf("ALuno: Felipe Alvarenga Carvalho - 10310526\n");
    printf("Executando arquivo sort-o.c\n");
    int n = sizeof(inputs) / sizeof(inputs[0]);
    ITEM *arrayItens[n];

    //Alocando itens criados e armazenando em um array de itens
    for(int i = 0; i < n; i++) {
        ITEM *item;
        item = item_criar(inputs[i].data, inputs[i].key);
        arrayItens[i] = item;
    }

    //Realizando o Bubble Sort no vetor de itens
    sort(arrayItens, n);

    //Printando resultado ordenado na tela
    //Desalocando memória
    for(int i = 0; i < n; i++) {
        printf("array[%d] = {%s, %d}\n", i, item_get_data(arrayItens[i]), item_get_key(arrayItens[i]));
        ITEM *itemApagar;
        itemApagar = arrayItens[i];
        item_apagar(&itemApagar);
    }
}


//Funções auxiliares usadas para programação com orientação a objetos
ITEM *item_criar(char *data, int key) {
    ITEM *item;
    item = (ITEM *) malloc(sizeof(ITEM) * 1);
    if(item != NULL) {
        item->data = data;
        item->key = key;
        return item;
    }
    return NULL;
}
int item_apagar(ITEM **item) {
    if((*item) != NULL) {
        free((*item));
        (*item) = NULL;
        return TRUE;
    }
    return FALSE;
}

char *item_get_data(ITEM *item) {
    if(item != NULL) {
        return item->data;
    }
    return NULL;
}
int item_get_key(ITEM *item) {
    if(item != NULL) {
        return item->key;
    }
    return ERRO;
}
