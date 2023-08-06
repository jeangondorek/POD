#include<stdio.h>
#include "create_quick.h"

void quick_sort(int lista[], int inicio, int fim){
    int pivo;
    if (inicio < fim){
        pivo = create_quick(lista, inicio, fim);
        
        quick_sort(lista, inicio, pivo-1);
        quick_sort(lista, pivo, fim);
    }
}