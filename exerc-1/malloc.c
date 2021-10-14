#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"

void* aMalloc_(size_t size, const char *file, int line, const char *func) {
  void *ret = malloc(size);
  //printf("%s:%d: in func %s: aMalloc %ld\n",file,line,func,size);
  if(ret == NULL) {
    printf("%s:%d: in func %s: aMalloc error out of memory!\n",file,line,func);
    //system("pause");
    exit(1);
  }
  return ret;
}

void* aRealloc_(void *p, size_t size, const char *file, int line, const char *func) {
  void *ret = realloc(p, size);
  //printf("%s:%d: in func %s: aRealloc %ld\n",file,line,func,size);
  if(ret == NULL) {
    printf("%s:%d: in func %s: aRealloc error out of memory!\n",file,line,func);
    //system("pause");
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
