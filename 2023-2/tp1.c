/**
 * @file tp2.c
 * @author Jean Carlos Canova Gondorek
 * @version 2.0
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

/* Variaveis globais para contar as trocas*/
unsigned long long selectionSwaps;
unsigned long long bubbleSwaps;
unsigned long long quickSwaps = 0;
unsigned long long insertionSwaps;
unsigned long long heapSwaps = 0;
unsigned long long radixSwaps = 0;

/* Declaração das funções utilizadas ao longo do código*/

/*Funções para clonagem de arrays, criação do array e print do array*/
void copia(unsigned long long *A, unsigned long long *V, int size);
unsigned long long *create_array(int size);
void printarray(unsigned long long *A, int size);

/* Funções de ordenamento */
unsigned long long heap_sort(unsigned long long *A, unsigned long long inicio);
void countSort(unsigned long long *A, int size, unsigned long long exp);
void radixSort(unsigned long long *A, int size);
unsigned long long selection_sort(unsigned long long *A, int size);
unsigned long long bubbleSort(unsigned long long *A, int size);
unsigned long long insertion_sort(unsigned long long *A, int size);
unsigned long long quick_sort(unsigned long long *A, unsigned long long inicio, unsigned long long fim);

/* Funções auxiliares ao ordenamento*/
unsigned long long create_heap(unsigned long long *A, unsigned long long inicio, unsigned long long fim);
unsigned long long getMax(unsigned long long *A, int size);
unsigned long long create_quick(unsigned long long *A, unsigned long long inicio, unsigned long long fim);

int main() {
    /* quantidade de valores no array*/
    int count = 10000;
    /* criação do array com os valores definidos acima*/
    unsigned long long *lista = create_array(count);

    unsigned long long bubbleVec[count];
    copia(lista, bubbleVec, count);
    clock_t begin_bubble = clock();
    bubbleSwaps = bubbleSort(bubbleVec, count);
    clock_t end_bubble = clock();
    double time_spent_bubble = (double)(end_bubble - begin_bubble) / CLOCKS_PER_SEC;

    unsigned long long selection_sortVec[count];
    copia(lista, selection_sortVec, count);
    clock_t begin_selection = clock();
    selectionSwaps = selection_sort(selection_sortVec, count);
    clock_t end_selection = clock();
    double time_spent_selection = (double)(end_selection - begin_selection) / CLOCKS_PER_SEC;

    unsigned long long insertion_sortVec[count];
    copia(lista, insertion_sortVec, count);
    clock_t begin_insertion = clock();
    insertionSwaps = insertion_sort(insertion_sortVec, count);
    clock_t end_insertion = clock();
    double time_spent_insertion = (double)(end_insertion - begin_insertion) / CLOCKS_PER_SEC;

    unsigned long long quick_sortVec[count];
    copia(lista, quick_sortVec, count);
    clock_t begin_quick = clock();
    quickSwaps = quick_sort(quick_sortVec, 0, count - 1);
    clock_t end_quick = clock();
    double time_spent_quick = (double)(end_quick - begin_quick) / CLOCKS_PER_SEC;

    unsigned long long heap_sortVec[count];
    copia(lista, heap_sortVec, count);
    clock_t begin_heap = clock();
    heap_sort(heap_sortVec, count);
    clock_t end_heap = clock();
    double time_spent_heap = (double)(end_heap - begin_heap) / CLOCKS_PER_SEC;

    unsigned long long radix_sortVec[count];
    copia(lista, radix_sortVec, count);
    clock_t begin_radix = clock();
    radixSort(radix_sortVec, count);
    clock_t end_radix = clock();
    double time_spent_radix = (double)(end_radix - begin_radix) / CLOCKS_PER_SEC;

    printf("\nend time bubble: %f", time_spent_bubble);
    printf("\nend time insertion: %f", time_spent_insertion);
    printf("\nend selection: %f", time_spent_selection);
    printf("\nend time quick: %f", time_spent_quick);
    printf("\nend time heap: %f", time_spent_heap);
    printf("\nend time radix: %f \n", time_spent_radix);
    
    printf("\nTrocas bubble: %lld\n", bubbleSwaps);
    printf("Trocas insertion: %lld\n", insertionSwaps);
    printf("Trocas selection: %lld\n", selectionSwaps);
    printf("Trocas quick: %lld\n", quickSwaps);
    printf("Trocas heap: %lld\n", heapSwaps);
    printf("Trocas radix: %lld\n", radixSwaps);

    printf("\n");

    free(lista);
    return 0;
}

void copia(unsigned long long *A, unsigned long long *V, int size) {
    int i;
    for (i = 0; i < size; i++)
        V[i] = A[i];
}

unsigned long long create_heap(unsigned long long lista[], unsigned long long count, unsigned long long i) {
    unsigned long long maior = i;
    unsigned long long left = 2 * i + 1;
    unsigned long long right = 2 * i + 2;

    if (left < count && lista[left] > lista[maior]) {
        maior = left;
    }

    if (right < count && lista[right] > lista[maior]) {
        maior = right;
    }

    if (maior != i) {
        int aux = lista[i];
        lista[i] = lista[maior];
        lista[maior] = aux;
        heapSwaps++;
        create_heap(lista, count, maior);
    }
}

unsigned long long heap_sort(unsigned long long lista[], unsigned long long count) {
    for (int i = count / 2 - 1; i >= 0; i--) {
        create_heap(lista, count, i);
    }

    for (int i = count - 1; i >= 0; i--) {
        int aux = lista[0];
        lista[0] = lista[i];
        lista[i] = aux;
        heapSwaps++;
        create_heap(lista, i, 0);
    }
}

unsigned long long getMax(unsigned long long *A, int size) {
    unsigned long long max = A[0];
    for (int i = 1; i < size; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

void countSort(unsigned long long *A, int size, unsigned long long exp) {
    const int RANGE = 10;
    unsigned long long *output = (unsigned long long *)malloc(size * sizeof(unsigned long long));

    int *count = (int *)malloc(RANGE * sizeof(int));

    for (int i = 0; i < RANGE; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[(A[i] / exp) % RANGE]++;
    }

    for (int i = 1; i < RANGE; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % RANGE] - 1] = A[i];
        count[(A[i] / exp) % RANGE]--;
        radixSwaps++;
    }

    for (int i = 0; i < size; i++) {
        A[i] = output[i];
    }

    free(output);
    free(count);
}

void radixSort(unsigned long long *A, int size) {
    unsigned long long max = getMax(A, size);

    for (unsigned long long exp = 1; max / exp > 0; exp *= 10) {
        countSort(A, size, exp);
    }
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

unsigned long long create_quick(unsigned long long *lista, unsigned long long inicio, unsigned long long fim) {
    int aux;
    unsigned long long pivo = fim, k = inicio;
    for (int i = inicio; i < fim; i++) {
        if (lista[i] <= lista[pivo]) {
            aux = lista[i];
            lista[i] = lista[k];
            lista[k] = aux;
            k++;
        }
    }
    if (lista[k] > lista[pivo]) {
        aux = lista[pivo];
        lista[pivo] = lista[k];
        lista[k] = aux;
    }
    return k;
}

unsigned long long quick_sort(unsigned long long *lista, unsigned long long inicio, unsigned long long fim) {
    unsigned long long trocas = 0;
    if (inicio < fim) {
        unsigned long long pivo = create_quick(lista, inicio, fim);
        trocas += pivo - inicio;
        trocas += fim - pivo;
        trocas += quick_sort(lista, inicio, pivo - 1);
        trocas += quick_sort(lista, pivo + 1, fim);
    }
    return trocas;
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
