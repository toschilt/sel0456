#ifndef _RANGE_H
#define _RANGE_H



//Estrutrura pública
typedef struct range {
    char buf[sizeof(struct _range)];
} range_t;


/* Métodos */
range_t* range_init(int min, int max); //Construtor
void range_destroy(range_t *r); //Destrutor

void range_print(range_t *r, FILE *stream);
void range_inc(range_t *r, int step);
void range_set(range_t *r, int val);

#endif