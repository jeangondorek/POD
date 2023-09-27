#include <stdio.h>

long bubble_sort(int lista[], int count) {
    int aux;
    long counts=0;
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (lista [j] > lista[j+1])
            {
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
                counts++;
            }
        }
    }
    return counts;
}
