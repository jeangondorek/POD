#include<stdio.h>
#include "create_quick.h"

void quick_sort(int lista[], int inicio, int fim, long *counts){
    int pivo;
    if (inicio < fim){
        pivo = create_quick(lista, inicio, fim, counts);
        
        quick_sort(lista, inicio, pivo-1, counts);
        quick_sort(lista, pivo, fim, counts);
    }
}
