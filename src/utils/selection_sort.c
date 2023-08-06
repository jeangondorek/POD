#include<stdio.h>

void selection_sort(int lista[], int count){
int aux;
for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1; j++)
        {
            if (lista [i] < lista[j])
            {
                aux = lista[j];
                lista[j] = lista[i];
                lista[i] = aux;
            }
        }
    }
}