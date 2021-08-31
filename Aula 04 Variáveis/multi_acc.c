#include "multi_acc.h"

static int x = 2;

void multi_set_x(int _x) {
    x = _x;
}

int multi_acc(int y) {
    static int z = 2;
    x += z + x * y;
    z += x;
    return x;
}