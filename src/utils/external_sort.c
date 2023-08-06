#include <stdio.h>
#include <stdlib.h>
#include "sort_block.h"
#include "merge_block.h"

void external_sort(int lista[], int count) {
    int block_size = 5; 

    int temp[500];

    for (int inicio = 0; inicio < count; inicio += block_size) {
        int fim = inicio + block_size - 1;
        if (fim >= count) {
            fim = count - 1;
        }

        sort_block(lista, inicio, fim);
    }

    for (int bloco = block_size; bloco < count; bloco *= 2) {
        for (int inicio = 0; inicio < count - 1; inicio += 2 * bloco) {
            int meio = inicio + bloco - 1;
            int fim = inicio + 2 * bloco - 1;
            if (fim >= count) {
                fim = count - 1;
            }
            merge_block(lista, temp, inicio, meio, fim);
        }
    }
}
