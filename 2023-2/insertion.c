#include <stdio.h> 
#include <stdlib.h>
#include <time.h>


//Questões para serem entregues. 

//1- Rode o código e verifique se está funcionando corretamente a partir do debug. 
// está funcionando corretamente
// feito ajustes no contatdor 

//2- Crie uma variável para indicar quantas operações de comparação foram executadas pelo algortimo de bublle e pelo Insertion. Para a mesma entrada de 10000 elementos quantas comparações foram realizadas? 
//bubble sort: 49995000, insertion sort: 24467707

//3- Quais são as diferenças entre os métodos bubble e insertion sort? 
// o insertion seleciona o valor e leva onde ele acha ser o local correto, ordenando parte dos valores e levando a um local "ordenano" e organizando nele. 
//Já o bubble pega o valor e vai tricando, caso ocorra que um valor seja maior ele fara 2 trocas de posição, trocando o valor que ele estava "levando" e trocando o valor que ele encontrou que era maior que o valor que ele estava levando. OU seja, ele pega o maior valor "incial" e vai levando até o final do vetor, mas podem ocorrer trocas de posição no meio do caminho.

//4- Existe algum caso em que o buble é melhor que o sort em número de comparações?
//quando o vetor já está ordenado, tendo flags  o bubble sort faz menos comparações que o insertion sort.

//5 - Compute o tempo para fazer o ordenamento de um mesmo vetor randômico com 100000 valores usando o bubble e o insertion. +
// ~22.476668 contra ~6.332370 respectivamente

void sort(int n, int* ptr){

    int i,j, min, t;
    int contador=0;
    for (i = 1; i < n; i++) {   
        
        min=ptr[i];
        for (j=i; j>=1 && min< ptr[j-1];j--){
            ptr[j]=ptr[j-1];
            contador++;
           
        }   
        ptr[j]=min;
    }
    printf("sort vector\n");
    for (int i=0;i<n;i++){
        printf("%d ", ptr[i]);
    }
    printf("contador %i", contador);
}


int main() 
{ 
    // vector size
    long int n = 100; 
    // memory allocation

    int *vet = (int*)malloc(n * sizeof(int));
    srand(time(NULL));

   
    for (int i=0; i< n; i++){
        vet[i]=(rand()%100);
    }    
    
    clock_t begin = clock();    
    sort(n, vet); 
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n end time: %f\n", time_spent);
    return 0; 
} 



