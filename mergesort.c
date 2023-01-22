// Merge Sort

#include<stdlib.h>
#include<stdio.h>

int printarray(int lista[], int count){
    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");
}

int * array(int count){
    int * lista = (int *) calloc (count, sizeof(int));
    for (int i = 0; i <= count; i++){
        lista[i] = rand() % 100;
    }
    return lista;
}


void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // Create temp arrays
    int L[n1], R[n2];
    // Copy data to temp array
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    // Merge the temp arrays
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else
        {
        arr[k] = R[j];
        j++;
        }
        k++;
    }
    // Copy the remaining elements of L[]
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[]
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
if (l < r){
    int m = l+(r-l)/2;

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    //test array printer
    //printArray(arr, r+1);

    merge(arr, l, m, r);
    }
}

int main(){
    int count;

    printf("Digite a quantidade de números da lista: ");
    scanf("%d", &count);
    int * lista = array(count);

    printarray(lista, count);
    mergeSort(lista, 0, count - 1);
    printarray(lista, count);
    return 0;
}