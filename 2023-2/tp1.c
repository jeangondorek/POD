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
 */

// https://docs.google.com/spreadsheets/d/18EfC-9DBctZAxrB3jfeXbegzUGeH3m_pfbL-Z6ANA-E/edit?usp=sharing

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
int *create_array(int size);

int main(){

	int i;
    // váriavel que defini tamanho do vetor
    int count = 100000; 
    
    // em cerca de 2horas o programa não terminou UMA execução com 1 milhão. Não tenho como aguardar mais tempo
    
    // variavel que recebe o vetor criado pela função create_array
    int *lista = create_array(count);


	printf("\nVetor original: ");
    printarray(lista, count);
	printf("Vetor tamanho = %d\n", count);

	// bubble sort
	int bubbleVec[count];
	copia(lista, bubbleVec, count);

    clock_t begin = clock();
	bubbleSort(bubbleVec, count);
    clock_t end = clock();
    double time_spent_bubble = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nBubble sort: ");
	printarray(bubbleVec, count);

    // selection sort
    int selection_sortVec[count];
	copia(lista, selection_sortVec, count);

    begin = clock();
	selection_sort(selection_sortVec, count);
    end = clock();
    double time_spent_selection = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nSelection sort: ");
	printarray(selection_sortVec, count);

	// insertion sort
    int insertion_sortVec[count];
	copia(lista, insertion_sortVec, count);

    begin = clock();
	insertion_sort(insertion_sortVec, count);
    end = clock();
    double time_spent_insertion = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nInsertion sort: ");
	printarray(insertion_sortVec, count);

	// quick sort
    int quick_sortVec[count];
	copia(lista, quick_sortVec, count);

    begin = clock();
	quick_sort(quick_sortVec, 0, count - 1);
    end = clock();
    double time_spent_quick = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nQuick sort: ");
	//printarray(quick_sortVec, count);
	printf("\n");

    free(lista);

    printf("\n end time bubble: %f", time_spent_bubble);
    printf("\n end selection: %f", time_spent_selection);
    printf("\n end time insertion: %f", time_spent_insertion);
    printf("\n end time quick: %f", time_spent_quick);

    printf("\n");

	return 0;
}

void copia(int *A, int *V, int size){
	int i;
	for (i = 0 ; i < size ; i++)
    	     V[i] = A[i];
}

int bubbleSort(int *lista, int count){
    // utilizado bubble sort feito na vez que fiz essa matéria pela primeira vez
    // inclusive utilizando flags para otimizar o algoritmo
    int swapped, aux;
    for (int i = 0; i < count - 1; i++){
        swapped = 0;
        for (int j = 0; j < count - i - 1; j++){
            if (lista[j] > lista[j+1]){
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
                swapped = 1;
            }
        }
        if (swapped == 0) 
            break;
    }
}

int selection_sort(int lista[], int count){
    // utilizado selection sort feito na vez que fiz essa matéria pela primeira vez
    int aux;
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count - 1; j++){
            if (lista [i] < lista[j]){
                aux = lista[j];
                lista[j] = lista[i];
                lista[i] = aux;
            }
        }
    }
}

int insertion_sort(int * lista, int count){
    // utilizado selection sort feito na vez que fiz essa matéria pela primeira vez
    int aux, j, i;
    for (i = 0; i < count; i++){
        aux = lista[i];
        j = i-1;
        while (j >= 0 && lista[j]>aux){
            lista[j+1] = lista[j];
            j = j-1;
        }
        lista[j+1] = aux;
    }
}

int create_quick(int lista[], int inicio, int fim){
    int aux;
    int pivo=fim, k=inicio;
    
    // a função create_quick é responsável por criar o pivo que será utilizado para dividir o array
    for (int i=inicio; i < fim; i++){
        // se o valor do array for menor ou igual ao pivo, ele é trocado de lugar com o valor da posição k
        if (lista[i] <= lista[pivo]){
            aux = lista[i];
            lista[i]= lista[k];
            lista[k]= aux;
            k++;
        }
    }
    // se o valor do array for maior que o pivo, ele é trocado de lugar com o valor da posição pivo
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
    // o quick sort faz a ordenação do array de forma recursiva
    if (inicio < fim){
        // a função create_quick retorna o pivo que será utilizado para dividir o array
        pivo = create_quick(lista, inicio, fim);
        // a função quick_sort é chamada novamente para ordenar os arrays menores que o pivo e maiores que o pivo
        quick_sort(lista, inicio, pivo-1);
        quick_sort(lista, pivo, fim);
    }
}

// FUNÇÃO PARA PRINTAR O ARRAY
void printarray(int lista[], int count){
    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");
}

int *create_array(int count) {
    // função criada para gerar um array de inteiros aleatórios dentro do tamanho pré definido
    int *lista = (int *)malloc(count * sizeof(int));
    if (lista == NULL) {
        perror("Falha na alocação de memória");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL)); 

    for (int i = 0; i < count; i++) {
        lista[i] = rand() % 1000;
    }
    return lista;
}
