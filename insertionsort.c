// insertion sort

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

int insertionsort(int count, int * lista){
    int aux;
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (lista[j] > lista[j+1])
            {
                aux = lista[j+1];
                lista[j+1] = lista[j];
            }
            lista[j] = aux;
        }
    }
    printarray(count, lista);
}

int main(){
    int count;

    printf("Digite a quantidade de números da lista: ");
    scanf("%d", &count);

    int * lista = array(count);
    printarray(count, lista);
    insertionsort(count, lista);

    return 0;
}