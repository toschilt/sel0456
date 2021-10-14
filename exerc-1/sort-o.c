#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node {
    int key;
    char *data;
    node_t *next, *prev;
};

typedef struct {
    node_t *head, *last;
    int size;
} list_t;

// Construtor
list_t *list_create() {
    list_t *list = (list_t*)malloc(sizeof(list_t));
    list->size = 0;
    list->head = NULL;
    list->last = NULL;
}

// Destrutor
void list_destroy(list_t *list) {
    node_t *node = list->head;
    while(node != NULL) {
        list->head = node->next;
        free(node);
        node = list->head;
    }
    free(list);
}

void list_insert(list_t *list, int key, char *data) {
    node_t *node = (node_t*)malloc(sizeof(node_t));
    if(list->head == NULL) { 
        list->head = node;
        node->prev = NULL;
    }
    else { 
        list->last->next = node; 
        node->prev = list->last;
    }
    list->last = node;
    list->size++;
    node->next = NULL;
    node->key = key;

    int string_size = 0;
    while(data[string_size++] != '\0');
    char *data_string = (char*)malloc(string_size * sizeof(char));
    data_string = data;
    node->data = data_string;    
}

void list_sort(list_t *list) {
    if(list->size <= 1) { return; }
    int s = 1;
    for(int i = 0; i < list->size && s != 0; i++) {
        s = 0;
        node_t *node = list->head;
        while(node != NULL) {
            if(node->next != NULL && node->key > node->next->key) {
                node_t *next = node->next;

                if(list->head == node) { list->head = next; }
                if(list->last == next) { list->last = node; }

                if(node->prev != NULL) { node->prev->next = next; }
                if(next->next != NULL) { next->next->prev = node; }

                node_t *prev = node->prev;
                node->next = next->next;
                node->prev = next;
                next->next = node;
                next->prev = prev;
                s++;
            }
            node = node->next;
        }
    }
}

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

    printf("\n\n");
    list_sort(list);

    list_print(list);

    list_destroy(list);
}
