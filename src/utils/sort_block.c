#include <stdio.h>
#include "create_quick.h"

void sort_block(int *input, int inicio, int fim) {
    long quick_count = 0;
    long *counts = &quick_count;
    if (inicio < fim) {
        int pivo = create_quick(input, inicio, fim, counts);

        sort_block(input, inicio, pivo - 1);
        sort_block(input, pivo, fim);
    }
}