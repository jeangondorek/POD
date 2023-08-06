#include <stdio.h>

void create_heap(int lista[], int count, int i) {
    int maior = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < count && lista[left] > lista[maior])
        maior = left;

    if (right < count && lista[right] > lista[maior])
        maior = right;

    if (maior != i) {
        int aux = lista[i];
        lista[i]= lista[maior];
        lista[maior]= aux;
        create_heap(lista, count, maior);
    }
}