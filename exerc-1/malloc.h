#ifndef _MALLOC_H_
#define _MALLOC_H_

#define   ALC_MARK      __FILE__, __LINE__, __func__
#define   aMalloc(n)    aMalloc_(n,ALC_MARK)
#define   aRealloc(p,n) aRealloc_(p,n,ALC_MARK)
#define   aFree(p)      aFree_(p,ALC_MARK)

void* aMalloc_(size_t size, const char *file, int line, const char *func);
void* aRealloc_(void *p, size_t size, const char *file, int line, const char *func);
void aFree_(void *p, const char *file, int line, const char *func);

#endif
