/**
 * @file tp1.c
 * @author Jean Carlos Canova Gondorek
 * @version 1.0
 * @date 2023-09-11
 *
 * @copyright Copyright (c) 2023
 *
 * 
 * Atenção: Antes de entregar, conferir se dos dados acima da documentação estão
 * preenchidos corretamente.
 *
 * https://docs.google.com/spreadsheets/d/18EfC-9DBctZAxrB3jfeXbegzUGeH3m_pfbL-Z6ANA-E/edit?usp=sharing
 * 
 * 
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copia(int *A, int *v, int size);
int bubbleSort(int *A, int size);
int selection_sort(int *A, int size);
int insertion_sort(int *A, int size);
int quick_sort(int *A, int init ,int size);
void printarray(int *A, int size);
int create_quick(int *A, int inicio, int fim);
long *create_array(int size);

int main(){
	int i;
    int count = 200000;
    long *lista = create_array(count);

	int bubbleVec[count];
	copia(lista, bubbleVec, count);
    clock_t begin = clock();
    long bubbleSwaps = (long)malloc(count * sizeof(long));
    bubbleSwaps = bubbleSort(bubbleVec, count);
    clock_t end = clock();
    double time_spent_bubble = (double)(end - begin) / CLOCKS_PER_SEC;

    int selection_sortVec[count];
	copia(lista, selection_sortVec, count);
    begin = clock();
    long selectionSwaps = (long)malloc(count * sizeof(long));
    selectionSwaps = selection_sort(selection_sortVec, count);
    end = clock();
    double time_spent_selection = (double)(end - begin) / CLOCKS_PER_SEC;

    int insertion_sortVec[count];
	copia(lista, insertion_sortVec, count);
    begin = clock();
    long insertionSwaps = (long)malloc(count * sizeof(long));
    insertionSwaps = insertion_sort(insertion_sortVec, count);
    end = clock();
    double time_spent_insertion = (double)(end - begin) / CLOCKS_PER_SEC;

    int quick_sortVec[count];
	copia(lista, quick_sortVec, count);
    begin = clock();
    long quickSwaps = (long)malloc(count * sizeof(long));
    quickSwaps = quick_sort(quick_sortVec, 0, count - 1);
    end = clock();
    double time_spent_quick = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n end time bubble: %f", time_spent_bubble);
    printf("\n end time insertion: %f", time_spent_insertion);
    printf("\n end selection: %f", time_spent_selection);
    printf("\n end time quick: %f\n", time_spent_quick);
    
    printf("Trocas bubble: %ld\n", bubbleSwaps);
    printf("Trocas insertion: %ld\n", insertionSwaps);
    printf("Trocas selection: %ld\n", selectionSwaps);
    printf("Trocas quick: %ld\n", quickSwaps);

    printf("\n");

    free(lista);
	return 0;
}

void copia(int *A, int *V, int size){
	int i;
	for (i = 0 ; i < size ; i++)
    	     V[i] = A[i];
}

int bubbleSort(int *lista, int count) {
    int swapped, aux, swaps = 0;
    for (int i = 0; i < count - 1; i++) {
        swapped = 0;
        for (int j = 0; j < count - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
                swapped = 1;
                swaps++;
            }
        }
        if (swapped == 0)
            break;
    }
    return swaps;
}

int selection_sort(int lista[], int count) {
    int aux, swaps = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (lista[i] < lista[j]) {
                aux = lista[j];
                lista[j] = lista[i];
                lista[i] = aux;
                swaps++;
            }
        }
    }
    return swaps;
}

int insertion_sort(int *lista, int count) {
    int aux, j, i, swaps = 0;
    for (i = 0; i < count; i++) {
        aux = lista[i];
        j = i - 1;
        while (j >= 0 && lista[j] > aux) {
            lista[j + 1] = lista[j];
            j = j - 1;
            swaps++;
        }
        lista[j + 1] = aux;
    }
    return swaps;
}

int create_quick(int lista[], int inicio, int fim){
    int aux;
    int pivo=fim, k=inicio;
    for (int i=inicio; i < fim; i++){
        if (lista[i] <= lista[pivo]){
            aux = lista[i];
            lista[i]= lista[k];
            lista[k]= aux;
            k++;
        }
    }
    if (lista[k] > lista[pivo]){
        aux = lista[pivo];
        lista[pivo] = lista[k];
        lista[k] = aux;
        pivo=k;
    }
    return pivo;
}

int quick_sort(int lista[], int inicio, int fim){
    int pivo;
    if (inicio < fim){
        pivo = create_quick(lista, inicio, fim);
        quick_sort(lista, inicio, pivo-1);
        quick_sort(lista, pivo, fim);
    }
}

void printarray(int lista[], int count){
    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");
}

long *create_array(int count) {
    long *lista = (long *)malloc(count * sizeof(long));
    if (lista == NULL) {
        perror("Falha na alocação de memória");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL)); 
    for (int i = 0; i < count; i++) {
        lista[i] = rand() % count;
    }
    return lista;
}
