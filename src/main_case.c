#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

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
            long insertion_count;
            clock_t begin_insertion = clock();
            insertion_count = insertion_sort(lista, count);
            clock_t end_insertion = clock();
            double time_spent_insertion = (double)(end_insertion - begin_insertion) / CLOCKS_PER_SEC;
            break;
        case 2:
            printarray(lista, count);
            long heap_count;
            clock_t begin_heap = clock();
            heap_count = heap_sort(lista, count);
            clock_t end_heap = clock();
            double time_spent_heap = (double)(end_heap - begin_heap) / CLOCKS_PER_SEC;
            break;
        case 3:
            printarray(lista, count);
            long quick_count;
            clock_t begin_quick = clock();
            quick_count = quick_sort(lista, 0, count - 1);
            clock_t end_quick = clock();
            double time_spent_quick = (double)(end_quick - begin_quick) / CLOCKS_PER_SEC;
            break;
        case 4:
            printarray(lista, count);
            long merge_count;
            clock_t begin_merge = clock();
            merge_count = merge_sort(lista, 0, count - 1);
            clock_t end_merge = clock();
            double time_spent_merge = (double)(end_merge - begin_merge) / CLOCKS_PER_SEC;
            break;
        case 5:
            printarray(lista, count);
            long selection_count;
            clock_t begin_selection = clock();
            selection_count = selection_sort(lista, count);
            clock_t end_selection = clock();
            double time_spent_selection = (double)(end_selection - begin_selection) / CLOCKS_PER_SEC;
            printf("Selection count: %ld\n", selection_count);
            break;
        case 6:
            printarray(lista, count);
            long bubble_wtfcount;
            clock_t begin_bubble_wtf = clock();
            bubble_wtfcount = bubble_sort_wtf(lista,count);
            clock_t end_bubble_wtf = clock();
            double time_spent_bubble_wtf = (double)(end_bubble_wtf - begin_bubble_wtf) / CLOCKS_PER_SEC;
            break;
        case 7:
            printarray(lista, count);
            clock_t begin_bubble = clock();
            bubble_sort(lista, count);
            clock_t end_bubble = clock();
            double time_spent_bubble = (double)(end_bubble - begin_bubble) / CLOCKS_PER_SEC;
            break;
        case 8:
            printarray(lista, count);
            clock_t begin_external = clock();
            external_sort(lista, count);
            clock_t end_external = clock();
            double time_spent_external = (double)(end_external - begin_external) / CLOCKS_PER_SEC;
            break;
        case 9:
            printf("Encerrando programa.\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
    printf("Lista ordenada:\t");
    //printarray(lista, count);

    return 0;
}
