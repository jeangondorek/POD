#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "print_array.h"
#include "create_array.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "bubble_sort.h"
#include "bubble_sort_wtf.h"
#include "selection_sort.h"
#include "create_heap.h"
#include "create_merge.h"
#include "create_quick.h"
#include "external_sort.h"

int main(){
    int count;

    printf("Digite a quantidade de números da lista: ");
    scanf("%d", &count);

    int * lista = create_array(count);

    printf("Escolha o algoritmo de ordenação:\n");
    printf("1. Insertion Sort\n");
    printf("2. Heap Sort\n");

    printf("3. Quick Sort\n");
    printf("4. Merge Sort\n");

    printf("5. Selection Sort\n");
    printf("6. Bubble Sort With Flags\n");

    printf("7. Bubble Sort\n");
    printf("8. Ordenação Externa\n");
    printf("9. Terminar\n");

    int opcao;
    scanf("%d", &opcao);

    printf("Lista não ordenada:\t");
    switch(opcao) {
        case 1:
            printarray(lista, count);
            insertion_sort(lista, count);
            break;
        case 2:
            printarray(lista, count);
            heap_sort(lista, count);
            break;
        case 3:
            printarray(lista, count);
            quick_sort(lista, 0, count - 1);
            break;
        case 4:
            printarray(lista, count);
            merge_sort(lista, 0, count - 1);
            break;
        case 5:
            printarray(lista, count);
            selection_sort(lista, count);
            break;
        case 6:
            printarray(lista, count);
            bubble_sort_wtf(lista,count);
            break;
        case 7:
            printarray(lista, count);
            bubble_sort(lista, count);
            break;
        case 8:
            printarray(lista, count);
            external_sort(lista, count);
            break;
        case 9:
            printf("Encerrando programa.\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
    printf("Lista ordenada:\t");
    printarray(lista, count);

    return 0;
}
