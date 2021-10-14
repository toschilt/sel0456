#include <stdlib.h>
#include <stdio.h>

struct item{
   char *data;
   int key; 
};

typedef struct item item_t;

void sort(item_t *a, int n);
item_t *new_array (int size);


//inicializador
void sort(item_t*a, int n){
    int i = 0, j =0;
    int s = 1;

    for(;i < n && s != 0; i++){
        s = 0;

        for(j = 0; j < n-1; j++){ // bug: falta da abertura de chave

      if(a[j].key > a[j+1].key){
        item_t t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
        s++;
      }
    }
    }
}

//construtor
item_t *new_array(int size){
    
    item_t*array;

    array = malloc(size*sizeof(item_t)); //permite tamanho variável
        if (array == NULL){
            printf("ERRO na construção");
            exit(EXIT_FAILURE);
        }

    for(int i = 0; i< size; i++){
        array[i].data = NULL;
        array[i].key = 0;
    }

    return array;    
}

//destrutor (necessário por conta do malloc)
void array_del (item_t *array, int size){
    for(int i=0; i < size; i++){
        free(array[i].data);
    }
    free(array);
}

//adição de elemento
void add_inarray(item_t *array, int key, const char *string){
    
    int tam = 0;
    for(; ; tam++){
        if(string[tam] == '\0'){break;}
    }

    int el = 0;
    for(; ; el++){
        if(array[el].data == NULL){break;}
    }

    array[el].data = malloc((tam)*sizeof(char));

    for(int i = 0; i< tam; i++){
        array[el].data[i] = string[i];
    }

    array[el].key = key;
}

int main(void){

    item_t *array;

    array = new_array(5);
    add_inarray(array, 3, "bill");
    add_inarray(array, 4, "neil");
    add_inarray(array, 2, "john");
    add_inarray(array, 5, "rick");
    add_inarray(array, 1, "alex");

    sort(array, 5);

    for(int i = 0; i < 5; i++){
        printf("array[%d} = {%s, %d} \n", i, array[i].data, array[i].key);
    }

    array_del(array, 5);

    return 0;
}

