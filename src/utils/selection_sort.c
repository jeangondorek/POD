#include<stdio.h>

long selection_sort(int lista[], int count) {
    long counts = 0;
    for (int i = 0; i < count - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < count; j++) {
            if (lista[j] < lista[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int aux = lista[i];
            lista[i] = lista[min_index];
            lista[min_index] = aux;
            counts++;
        }
    }
    return counts;
}
