#include<stdio.h>

int create_quick(int lista[], int inicio, int fim, long *counts){
    int aux;
    int pivo=fim, k=inicio;
    for (int i=inicio; i < fim; i++){
        if (lista[i] <= lista[pivo]){
            aux = lista[i];
            lista[i]= lista[k];
            lista[k]= aux;
            k++;
            (*counts)++;
        }
    }
    if (lista[k] > lista[pivo]){
        aux = lista[pivo];
        lista[pivo] = lista[k];
        lista[k] = aux;
        pivo=k;
        (*counts)++;
    }
    return pivo;
}
