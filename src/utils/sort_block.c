#include <stdio.h>
#include "create_quick.h"

void sort_block(int *input, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = create_quick(input, inicio, fim);

        sort_block(input, inicio, pivo - 1);
        sort_block(input, pivo, fim);
    }
}