// bubble sort

#include <stdio.h>
#include <stdlib.h>

int main(){
    int count = 9, aux, lista[count];

    for (int i = 0; i <= count; i++){
        lista[i] = rand() % count+2;
    }

    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }

    printf("\n");


    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (lista [j] > lista[j+1])
            {
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
        }
    }



    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");

    return;
}