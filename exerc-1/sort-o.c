#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "malloc.h"

void printTitle(void);

typedef struct {
  char * data;
  int key;
} item_t;

item_t * add_array(item_t * a, int * n, char * d, int k);
void del_array(item_t * a, int * n);
void print_array(item_t * a, int n);
void sort(item_t * a, int n);

int main(void) {
  printTitle();

  // Data
  char *data[] = { "bill", "neil", "john", "rick", "alex" };
  int key[] = { 3, 4, 2, 5, 1 };

  // Object
  item_t * array;
  int n_array = 0;

  for(int i=0; i<5; i++)
    array = add_array(array, &n_array, data[i], key[i]);

  sort(array, 5);
  print_array(array, n_array);
  del_array(array, &n_array);

  return 0;
}

void printTitle(void) {
  printf("\n");
  printf("          (=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-)\n");
  printf("          (                     SEL0456 - Exercício 1                      )\n");
  printf("          (    __     __    ____    ___           __  __    ____  _____    )\n");
  printf("          (  /'__`\\ /'__`\\ /',__\\  /'___\\ _______/\\ \\/\\ \\  /',__\\/\\ '__`\\  )\n");
  printf("          ( /\\  __//\\  __//\\__, `\\/\\ \\__//\\______\\ \\ \\_\\ \\/\\__, `\\ \\ \\L\\ \\ )\n");
  printf("          ( \\ \\____\\ \\____\\/\\____/\\ \\____\\/______/\\ \\____/\\/\\____/\\ \\ ,__/ )\n");
  printf("          (  \\/____/\\/____/\\/___/  \\/____/         \\/___/  \\/___/  \\ \\ \\/  )\n");
  printf("          (                                                         \\ \\_\\  )\n");
  printf("          (                                                          \\/_/  )\n");
  printf("          (                                                                )\n");
  printf("          (=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-)\n\n");
}

item_t * add_array(item_t * a, int * n, char * d, int k) {
  item_t * array;
  if (*n == 0)
    array = aMalloc(sizeof(item_t));
  else
    array = aRealloc(a, sizeof(item_t) * ((*n)+1));

  array[*n].data = aMalloc(strlen(d)+1);
  strcpy(array[*n].data, d);
  array[*n].key = k;
  (*n)++;

  return array;
}

void del_array(item_t * a, int * n) {
  for(int i=0; i<*n; i++)
    aFree(a[i].data);
  aFree(a);
  *n = 0;
}

void print_array(item_t * a, int n) {
  for(int i=0; i<n; i++)
    printf("array[%d] = {%s, %d}\n", i, a[i].data, a[i].key);
}

void sort(item_t * a, int n) {
  int i = 0, j = 0;
  int s = 1;

  for(int n0 = n; i < n0 && s != 0; i++) {
    s = 0;
    for(j = 0; j < n-1; j++)
      if(a[j].key > a[j+1].key) {
        item_t t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
        s++;
      }
    n--;
  }
}
