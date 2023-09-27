#include <stdio.h>

long bubble_sort_wtf(int lista[], int count) {
int swapped, aux;
long counts = 0;
    for (int i = 0; i < count - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (lista[j] > lista[j+1])
            {
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
                swapped = 1;
                counts++;
            }
        }
        if (swapped == 0) 
            break;
    }
    return counts;
}
