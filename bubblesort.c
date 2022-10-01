// bubble sort

#include <stdio.h>
#include <stdlib.h>

int main(){
    int count = 9, aux[count], lista[count];

    for (int i = 0; i <= count; i++){
        lista[i] = rand() % count+2;
        aux[i] = lista[i];
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
                lista[i] = lista[i+1];
                lista[i] = lista[j];

            }
        }
        
    }



    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");

    return;
}