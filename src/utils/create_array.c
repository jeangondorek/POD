#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "create_array.h"

int *create_array(int count) {
    int *lista = (int *)malloc(count * sizeof(int));
    if (lista == NULL) {
        perror("Falha na alocação de memória");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL)); 

    for (int i = 0; i < count; i++) {
        lista[i] = rand() % 100000;
    }
    return lista;
}
