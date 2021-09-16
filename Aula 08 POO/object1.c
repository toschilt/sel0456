#include <stdlib.h>
#include <stdio.h>
#include "object1.h"

/*
 * Conta do valor min ao valor max, sempre limitado a estes
*/
/* Métodos */

//Construtor
range_t* range_init(int min, int max) {
    range_t *r = (range_t*)malloc(sizeof(range_t));
    _range_t *_r = (_range_t*)r;
    if(min > max) {
        _r->min = max;
        _r->max = min;
    } else if(min == max) {
        _r->max = max + 1;
        _r->min = min;
    } else {
        _r->min = min;
        _r->max = max;
    }
    _r->val = min;
    return r;
}

//Destrutor
void range_destroy(range_t *r) {
    free(r);
}

void range_print(range_t *r, FILE *stream) {
    _range_t* _r = (_range_t*)r;
    fprintf(stream, "range_t: [%d, %d[ = %d\n", _r->min, _r->max, _r->val);
}

void range_inc(range_t *r, int step) {
    _range_t* _r = (_range_t*)r;
    _r->val += step;
    if(_r->val >= _r->max) {
        _r->val = _r->max - 1;
    }
}

void range_set(range_t *r, int val) {
    _range_t* _r = (_range_t*)r;
    if(val >= _r->max) { val = _r->max - 1; }
    else if(val <= _r->min) { val = _r->min; }
    _r->val = val;
}

/* Inicialização de estrurura manualmente */
// Salvo em .data (Já foi inicializado)
_range_t r1 = {
    .min = 0, .max = 10, .val = 0
};

//Salvo em .bss (Foi apenas declarado, mas nao inicializado)
range_t r2;

int main(void) {
    range_t *r = range_init(0, 10);
    
    for(int i = 0; i < 12; i++) {
        range_inc(r, 1);
    }

    range_destroy(r);
    return 0;

}