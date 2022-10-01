// bubble sort

#include <stdio.h>
#include <stdlib.h>

int main(){
    int count = 9, aux, listaux[count], lista[count];

    for (int i = 0; i <= count; i++){
        lista[i] = rand() % count+2;
    }

    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }

    printf("\n");


    for (int i = 0; i <= count; i++)
    {
        for (int j = i+1; j < count; j++)
        {
            if (lista [i] > lista[j])
            {
                aux = lista[j];
                for (int k = 0; k < count; k++)
                {
                    listaux[k] = lista[k+1];
                }
                listaux[i] = aux;
            }
        }
    }



    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");

    return;
}