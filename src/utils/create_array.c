#include <stdlib.h>
#include <stdio.h>
#include "create_array.h"

int * create_array(int count){
    int * lista = (int *) calloc (count, sizeof(int));
    for (int i = 0; i <= count; i++){
        lista[i] = rand() % 100;
    }
    return lista;
}
