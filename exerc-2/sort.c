#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char *data;
  int key;
} item_t;

//Imprime um registro na tela.
void print_item(gpointer data, gpointer user_data)
{
  int *i = (int *) user_data;
  printf("i = %d - data = %s, key = %d\n",
         *i,
         ((item_t *)data)->data,
         ((item_t *) data)->key);
  (*i)++;
}

//Função que realiza a comparação entre dois elementos da lista de registros de pessoas
gint compare_item(gconstpointer a, gconstpointer b)
{
  if(((item_t *) a)->key < ((item_t *) b)->key)
  {
    return -1;
  }
  else if(((item_t *) a)->key > ((item_t *) b)->key)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

//Função que faz a inicialização do registro de uma pessoa.
item_t* item_init(char *data, int key)
{
  item_t *self = malloc(sizeof(item_t));
  self->data = strdup(data);
  self->key = key;
  return self;
}

void item_destructor(gpointer _self, gpointer unused_data)
{
  item_t *self = (item_t *) _self;
  free(self->data);
  free(self);
}

int main(void)
{
  //Criação e inserção ordenada dos elementos
  GList *people_list = NULL;
  people_list = g_list_insert_sorted(people_list, item_init("bill", 3), compare_item);
  people_list = g_list_insert_sorted(people_list, item_init("neil", 4), compare_item);
  people_list = g_list_insert_sorted(people_list, item_init("john", 2), compare_item);
  people_list = g_list_insert_sorted(people_list, item_init("rick", 5), compare_item);
  people_list = g_list_insert_sorted(people_list, item_init("alex", 1), compare_item);

  /*
  Forma manual de inserção
  item_t person1 = {"bill", 3};
  item_t person2 = {"neil", 4};
  item_t person3 = {"john", 2};
  item_t person4 = {"rick", 5};
  item_t person5 = {"alex", 1};
  people_list = g_list_append(people_list, &person1);
  people_list = g_list_append(people_list, &person2);
  people_list = g_list_append(people_list, &person3);
  people_list = g_list_append(people_list, &person4);
  people_list = g_list_append(people_list, &person5);
  people_list = g_list_sort(people_list, compare_item);
  */

  //Print dos elementos da lista encadeada
  int i = 0;
  g_list_foreach(people_list, print_item, &i);

  //Liberando memória utilizada
  people_list = g_list_first(people_list);
  g_list_foreach(people_list, item_destructor, NULL);
  g_list_free(people_list);

  return 0;
}
