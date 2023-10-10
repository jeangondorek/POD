/**
 * @file tp1.c
 * @author Jean Carlos Canova Gondorek
 * @version 1.0
 * @date 2023-09-11
 *
 * @copyright Copyright (c) 2023
 *
 *
 * Atenção: Antes de entregar, conferir se os dados acima da documentação estão
 * preenchidos corretamente.
 *
 * https://docs.google.com/spreadsheets/d/18EfC-9DBctZAxrB3jfeXbegzUGeH3m_pfbL-Z6ANA-E/edit?usp=sharing
 * 
 * Código teve diversos problemas e existem algumas limitações quanto ao uso de algumas variáveis dentro desse código,
 * porém como me parece ser obrigatório o uso, os problemas persistem e não foram resolvidos.
 * Existe um código funcional feito sem esses problemas no repositório do github.
 * https://github.com/jeangondorek/POD
 * Boa parte do código já havia sido desenvolvida com outro professor, porém implementações de medição de tempo e trocas
 * foram implementadas para atender a este trabalho PORÉM, neste código não funcionou.
 * Na contagem de parte dos algoritmos quando os valores ficam muito altos, estoura a memória deles e não faz a contagem.
 * Já no outro código tudo funciona corretamente.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copia(unsigned long long *A, unsigned long long *v, int size);
unsigned long long bubbleSort(unsigned long long *A, int size);
unsigned long long selection_sort(unsigned long long *A, int size);
unsigned long long insertion_sort(unsigned long long *A, int size);
unsigned long long quick_sort(unsigned long long *A, unsigned long long inicio, unsigned long long fim, unsigned long long *trocas);
unsigned long long create_quick(unsigned long long *A, unsigned long long inicio, unsigned long long fim, unsigned long long *trocas);
void printarray(unsigned long long *A, int size);
unsigned long long *create_array(int size);

int main() {
    int i;
    int count = 10000;
    unsigned long long *lista = create_array(count);

    unsigned long long bubbleVec[count];
    unsigned long long bubbleSwaps;
    copia(lista, bubbleVec, count);
    clock_t begin = clock();
    bubbleSwaps = bubbleSort(bubbleVec, count);
    clock_t end = clock();
    double time_spent_bubble = (double)(end - begin) / CLOCKS_PER_SEC;

    unsigned long long selection_sortVec[count];
    unsigned long long selectionSwaps;
    copia(lista, selection_sortVec, count);
    begin = clock();
    selectionSwaps = selection_sort(selection_sortVec, count);
    end = clock();
    double time_spent_selection = (double)(end - begin) / CLOCKS_PER_SEC;

    unsigned long long insertion_sortVec[count];
    unsigned long long insertionSwaps;
    copia(lista, insertion_sortVec, count);
    begin = clock();
    insertionSwaps = insertion_sort(insertion_sortVec, count);
    end = clock();
    double time_spent_insertion = (double)(end - begin) / CLOCKS_PER_SEC;

    unsigned long long quick_sortVec[count];
    copia(lista, quick_sortVec, count);
    unsigned long long quickSwaps = 0;
    begin = clock();
    quick_sort(quick_sortVec, 0, count - 1, &quickSwaps);
    end = clock();
    double time_spent_quick = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n end time bubble: %f", time_spent_bubble);
    printf("\n end time insertion: %f", time_spent_insertion);
    printf("\n end selection: %f", time_spent_selection);
    printf("\n end time quick: %f\n", time_spent_quick);

    printf("Trocas bubble: %lld\n", bubbleSwaps);
    printf("Trocas insertion: %lld\n", insertionSwaps);
    printf("Trocas selection: %lld\n", selectionSwaps);
    printf("Trocas quick: %lld\n", quickSwaps);

    printf("\n");

    free(lista);
    return 0;
}

void copia(unsigned long long *A, unsigned long long *V, int size) {
    int i;
    for (i = 0; i < size; i++)
        V[i] = A[i];
}

unsigned long long bubbleSort(unsigned long long *lista, int count) {
    unsigned long long swapped;
    int aux;
    unsigned long long swaps = 0;
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

unsigned long long selection_sort(unsigned long long lista[], int count) {
    unsigned long long counts = 0;
    for (int i = 0; i < count - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < count; j++) {
            if (lista[j] < lista[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int aux = lista[i];
            lista[i] = lista[min_index];
            lista[min_index] = aux;
            counts++;
        }
    }
    return counts;
}

unsigned long long insertion_sort(unsigned long long *lista, int count) {
    int aux, j, i;
    unsigned long long swaps = 0;
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

unsigned long long create_quick(unsigned long long *lista, unsigned long long inicio, unsigned long long fim, unsigned long long *trocas) {
    int aux;
    unsigned long long pivo = fim, k = inicio;
    for (int i = inicio; i < fim; i++) {
        if (lista[i] <= lista[pivo]) {
            aux = lista[i];
            lista[i] = lista[k];
            lista[k] = aux;
            k++;
            (*trocas)++;
        }
    }
    if (lista[k] > lista[pivo]) {
        aux = lista[pivo];
        lista[pivo] = lista[k];
        lista[k] = aux;
        (*trocas)++;
    }
    return k;
}

unsigned long long quick_sort(unsigned long long *lista, unsigned long long inicio, unsigned long long fim, unsigned long long *trocas) {
    if (inicio < fim) {
        unsigned long long pivo = create_quick(lista, inicio, fim, trocas);
        quick_sort(lista, inicio, pivo - 1, trocas);
        quick_sort(lista, pivo + 1, fim, trocas);
    }
}

void printarray(unsigned long long *lista, int count) {
    for (int i = 0; i < count; i++) {
        printf("%lld\t", lista[i]);
    }
    printf("\n");
}

unsigned long long *create_array(int count) {
    unsigned long long *lista = (unsigned long long *)malloc(count * sizeof(unsigned long long));
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
