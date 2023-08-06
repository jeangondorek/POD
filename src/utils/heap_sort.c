#include <stdio.h>
#include "create_heap.h"

void heap_sort(int lista[], int count) {
    
    for (int i = count / 2 - 1; i >= 0; i--)
        create_heap(lista, count, i);

    for (int i = count - 1; i >= 0; i--) {
        int aux = lista[0];
        lista[0] = lista[i];
        lista[i] = aux;
        create_heap(lista, i, 0);
    }
}