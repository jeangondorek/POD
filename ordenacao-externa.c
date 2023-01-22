// ordenacao externa

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

int ordenacaoexterna(int count, int lista[]){


    printarray(count, lista);
}

int main(){
    int count;

    printf("Digite a quantidade de números da lista: ");
    scanf("%d", &count);

    int * lista = array(count);
    printarray(count, lista);
    ordenacaoexterna(count, lista);
    printarray(count, lista);

    return 0;
}