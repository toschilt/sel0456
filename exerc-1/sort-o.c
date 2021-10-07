#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define   ALC_MARK      __FILE__, __LINE__, __func__
#define   aMalloc(n)    aMalloc_(n,ALC_MARK)
#define   aRealloc(p,n) aRealloc_(p,n,ALC_MARK)
#define   aFree(p)      aFree_(p,ALC_MARK)

void* aMalloc_( size_t size, const char *file, int line, const char *func ) {
  void *ret = malloc(size);
  //printf("%s:%d: in func %s: aMalloc %ld\n",file,line,func,size);
  if(ret == NULL){
    printf("%s:%d: in func %s: aMalloc error out of memory!\n",file,line,func);
    system("pause");
    exit(1);
  }
  return ret;
}

void* aRealloc_(void *p, size_t size, const char *file, int line, const char *func) {
  void *ret = realloc(p, size);
  //printf("%s:%d: in func %s: aRealloc %ld\n",file,line,func,size);
  if(ret == NULL){
    printf("%s:%d: in func %s: aMalloc error out of memory!\n",file,line,func);
    system("pause");
    exit(1);
  }
  return ret;
}

void aFree_(void *p, const char *file, int line, const char *func) {
  //printf("%s:%d: in func %s: aFree %p\n",file,line,func,p);
  if (p)
    free(p);
  p = NULL;
}

void printTitle() {
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

typedef struct {
  char * data;
  int key;
} item_t;

item_t * add_array(item_t * a, int * n, char * d, int k) {
  item_t * self;
  
  if ( (*n) == 0 ) { self = aMalloc(sizeof(item_t)); }
  else { self = aRealloc(a, sizeof(item_t) * ((*n)+1)); }
  self[*n].data = aMalloc( strlen(d)+1 );
  strcpy(self[*n].data, d);
  self[*n].key = k;
  (*n)++;
  
  return self;
}

void del_array(item_t * a, int n) {
  for(int i=0; i<n; i++)
    aFree(a[i].data);
  aFree(a);
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

int main(void) {
  printTitle();
  
  // Data
  char *data[] = { "bill", "neil", "john", "rick", "alex" };
  int key[] = { 3, 4, 2, 5, 1 };

  // Objeto
  item_t * array;
  int n_array = 0;
  
  for(int i=0; i<5; i++) {
    array = add_array(array, &n_array, data[i], key[i]);
  }
  
  sort(array, 5);
  print_array(array, n_array);
  del_array(array, n_array);

  return 0;
}
