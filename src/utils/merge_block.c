#include <stdio.h>

void merge_block(int *input, int *temp, int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim) {
        if (input[i] < input[j]) {
            temp[k++] = input[i++];
        } else {
            temp[k++] = input[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = input[i++];
    }

    while (j <= fim) {
        temp[k++] = input[j++];
    }

    for (i = inicio; i <= fim; i++) {
        input[i] = temp[i];
    }
}