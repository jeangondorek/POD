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

int printarray(int count, int * lista){
    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");
}

int heapsort(int count, int * lista){
    int aux, j, i;
    for (i = 1; i < count-1; i++)
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
    printarray(count, lista);
}

int main(){
    int count;

    printf("Digite a quantidade de números da lista: ");
    scanf("%d", &count);

    int * lista = array(count);
    printarray(count, lista);
    heapsort(count, lista);

    return 0;
}