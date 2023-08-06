#include<stdio.h>
#include "create_merge.h"

void merge_sort(int lista[], int inicio, int fim){
if (inicio < fim){
    int meio = inicio+(fim-inicio)/2;

    merge_sort(lista, inicio, meio);
    merge_sort(lista, meio+1, fim);
    //teste array printer
    //printarray(lista, fim+1);

    create_merge(lista, inicio, meio, fim);
    }
}