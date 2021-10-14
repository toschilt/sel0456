#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

// Estrutura para armazenar informações de um nó específico
struct node {
    int key;
    char *data;
    node_t *next, *prev;
};

// Estrutura para armazenar todos os nós (equivale ao item_t)
typedef struct {
    node_t *head, *last;
    int size;
} list_t;

// Construtor
list_t *list_create() {
    // Alocação e definição dos parâmetros de uma lista vazia
    list_t *list = (list_t*)malloc(sizeof(list_t));
    list->size = 0;
    list->head = NULL;
    list->last = NULL;
}

// Destrutor
void list_destroy(list_t *list) {
    // Desalocação dos nós e, em seguida, da lista
    node_t *node = list->head;
    while(node != NULL) {
        list->head = node->next;
        free(node);
        node = list->head;
    }
    free(list);
}

// Função responsável por alocar um novo nó na lista
void list_insert(list_t *list, int key, char *data) {
    node_t *node = (node_t*)malloc(sizeof(node_t));
    // Caso list->head == NULL, a lista está vazia
    if(list->head == NULL) { 
        list->head = node;
        node->prev = NULL;
    }
    // Caso contrário, a lista possui pelo menos um elemento
    else { 
        list->last->next = node; 
        node->prev = list->last;
    }

    // Definição dos parâmetros do nó
    list->last = node;
    list->size++;
    node->next = NULL;
    node->key = key;

    // Alocação da string para um vetor com o tamanho desejado
    int string_size = 0;
    while(data[string_size++] != '\0');
    char *data_string = (char*)malloc(string_size * sizeof(char));
    data_string = data;
    node->data = data_string;    
}

// Função para realizar a ordenação da lista com base nas chaves
void list_sort(list_t *list) {
    // Caso o tamanho seja menor ou igual a 1, não é necessário fazer nada
    if(list->size <= 1) { return; }
    int s = 1;

    for(int i = 0; i < list->size && s != 0; i++) {
        s = 0;
        node_t *node = list->head;
        while(node != NULL) {
            // Verifica se as chaves estão fora de ordem
            if(node->next != NULL && node->key > node->next->key) {
                node_t *next = node->next;

                //Elemento é o primeiro da lista, deve ser alterado para elemento seguinte
                if(list->head == node) { list->head = next; }
                
                // Elemento seguinte é o último da lista, deve ser alterado para elemento
                if(list->last == next) { list->last = node; }

                // Atualização dos valores de próximo e anterior para os nós adjacentes
                if(node->prev != NULL) { node->prev->next = next; }
                if(next->next != NULL) { next->next->prev = node; }

                // Definição dos valores de próximo e anterior para os nós trocados
                node_t *prev = node->prev;
                node->next = next->next;
                node->prev = next;
                next->next = node;
                next->prev = prev;

                s++; // Flag que simboliza que houve alguma alteração
            }
            node = node->next;
        }
    }
}

// Função para realizar a impressão da lista
void list_print(list_t *list) {
    int i = 0;
    node_t *node = list->head;
    while(node != NULL) {
        printf("list[%d]: { key: %d, data: %s }\n", i++, node->key, node->data);
        node = node->next;
    }
}


int main(void) {
    list_t *list = list_create();
    list_insert(list, 3, "bill");
    list_insert(list, 4, "neil");
    list_insert(list, 2, "john");
    list_insert(list, 5, "rick");
    list_insert(list, 1, "alex");
    
    list_print(list);
    list_sort(list);
    printf("\n\n");
    list_print(list);

    list_destroy(list);
    return;
}
