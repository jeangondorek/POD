## Funcionalidades

- Metodos de ordenação em C
    - Merge Sort
    - Heap Sort
    - Insertion Sort
    - Quick Sort
    - Bubble Sort
    - Selection Sort

## Needed GCC to run this files

- How to run the Merge Sort, Heap Sort, Insertion Sort and Quick Sort.
```bash
gcc -o maincase src/main_case.c src/utils/selection_sort.c src/utils/bubble_sort.c src/utils/print_array.c src/utils/create_array.c src/utils/create_quick.c src/utils/create_merge.c src/utils/create_heap.c src/utils/merge_sort.c src/utils/heap_sort.c src/utils/insertion_sort.c src/utils/quick_sort.c src/utils/bubble_sort_wtf.c -Isrc/include
```

- How to run Selection Sort
```bash
gcc -o selectionsort src/selectionsort.c
```

- How to run Bubble Sort with flags
```bash
gcc -o bubblesortwtf src/utils/selection_sort.c
```

- How to run Bubble Sort
```bash
gcc -o bubblesort src/bubblesort.c
```
