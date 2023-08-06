#include<stdio.h>

void create_merge(int lista[], int inicio, int meio, int fim){
    //criar listas auxiliares
    int iarray1 = meio - inicio + 1; //inicio de cada lista
    int iarray2 = fim - meio;
 
    int array1[iarray1], array2[iarray2];
    // dividindo a lista em 2
    for (int i = 0; i < iarray1; i++)
        array1[i] = lista[inicio + i];
    for (int j = 0; j < iarray2; j++)
        array2[j] = lista[meio + 1+ j];

    int i = 0, k = inicio, j=0;

    //juntar as 2 listas ordenadamente
    while (i < iarray1 && j < iarray2){
        if (array1[i] <= array2[j]){
            lista[k] = array1[i];
            i++;
        }
        else
        {
        lista[k] = array2[j];
        j++;
        }
        k++;
    }
    
    while (i < iarray1){
        lista[k] = array1[i];
        i++;
        k++;
    }
    
    while (j < iarray2){
        lista[k] = array2[j];
        j++;
        k++;
    }
}