// heap sort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * array(int count){
    int * lista = (int *) calloc (count, sizeof(int));
    for (int i = 0; i <= count; i++){
        lista[i] = rand() % 100;
    }
    return lista;
}

int printarray(int count, int lista[]){
    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");
}

void creaheap(int lista[], int count, int i) {
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
        creaheap(lista, count, maior);
    }
}

void heapsort(int lista[], int count) {
    // criando heap máximo
    for (int i = count / 2 - 1; i >= 0; i--)
        creaheap(lista, count, i);

    for (int i = count - 1; i >= 0; i--) {
        int aux = lista[0];
        lista[0] = lista[i];
        lista[i] = aux;
        creaheap(lista, i, 0);
    }
}

int main(){
    int count;

    printf("Digite a quantidade de números da lista: ");
    scanf("%d", &count);

    int * lista = array(count);
    printarray(count, lista);
    heapsort(lista, count);
    printarray(count, lista);

    return 0;
}