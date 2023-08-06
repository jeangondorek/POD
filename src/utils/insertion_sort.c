#include <stdio.h>
#include "print_array.h"

int insertion_sort(int * lista, int count){
    int aux, j, i;
    for (i = 1; i < count+1; i++)
    {
        aux = lista[i];
        j = i-1;
        while (j >= 0 && lista[j]>aux)
        {
            lista[j+1] = lista[j];
            j = j-1;
        }
        lista[j+1] = aux;
    }
}