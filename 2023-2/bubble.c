#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//   print array elements
void printArray(int n, int *ptr) {
  for (int i = 0; i < n; ++i) {
    printf("%d  ", ptr[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *(b);
  *b = *a;
  *a = temp;
};

void bubblesort2(int n, int *ptr) {
  int i, j, t;
  int contador2 = 0;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (*(ptr + j) < *(ptr + i)) {
        swap((ptr + j), (ptr + i));
        contador2++;
        // Questão 5 - O parâmetro desta função são valores ou ponteiros?Explique. 
        // Da função SWAP? são ponteiros, a função swap recebe os valores desses ponteiros e faz a troca
        // nesse caso, ele passa o endereço de onde está o valor a ser trocado e a função swap
        // pega o valor do endereço e faz a troca
        // na funcao bubblesort2 somente *ptr é ponteiro, é realmente o enderço da memória
      }
    }
  }
  printf("contador2: %d\n", contador2);
  printf("bubblesort2 sort vector:");
  //printArray(n, ptr);
  printf("\n");
}

void bubblesort(long int n, int **ptr) {
  int *arr = *ptr;
  int contador=0;
  for (long int i = 0; i < n - 1; i++) {
    for (long int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        contador++;
        // Questão 6- Está sendo realizada a troca de um valor ou um ponteiro?
        // de um valor, ele faz a troca de posição dos valores
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

      }
    }
  }
  printf("contador: %d\n", contador);
  printf("BUBLE Sorted vector: ");
  //printArray(n, *ptr);
  printf("\n");
}

int main()
// Questão 0- Verifique se as funções estão funcionando corretamente.
// feita alguma correções para funcionamento desse código
// Se não, faça a correção.
//       - Estude o código.
//       - Altere o valor de n para 1000000. O que pode estar
//       acontecendo com o código?
// -----------------------------------------------------------------------------------
// Não irei desenvolver exemplos onde eu tenha que ficar muitas horas para
// terminar a execução. Portando o valor utilizado NUNCA SERÁ O SUGERIDO, sempre
// inferior, nesse caso de 100000(o que já é suficiente para dar segmentation
// fault caso não use malloc ou calloc)
{
  // vector size
  int n = 10000;
  // memory allocation
  // int vet[n]; // desabilitado essa forma de criação de array
  int *vet = (int *)malloc(n * sizeof(int));

  if (vet == NULL) {
    printf("Erro na alocação de memória\n");
    return 1;
  }

  // Questão 1 - Pq se deve alocar dinamicamente o vetor quando o n>>100
  // (grande)?
  // -------------------------------------------------------------------------------------------
  // Pelo que entendi é algo relacionado ao tamanho da memória que pode ser
  // usada dos 2 modos com alocação dinamica é possível armazenar mais dados sem
  // estourar o tamanho da pilha por isso é recomendada esse tipo de alocação
  // tanto que a função bubblesort precisa disso para nao estourar a memoria
  srand(time(NULL));

  for (int i = 0; i < n; i++) {
    vet[i] = (n - i);
  }

  // printArray(n,vet); // alterado para exibir vetor não ordenado.

  clock_t begin = clock();
  bubblesort2(n, vet); // essa função é o bubble sort?
  // Questão 2 - Qual a diferença entre &vet e vet?
  // &vet é um endereço da memória(nesse caso endereço do vetor vet) e vet um
  // valor(que seria o proprio vetor)
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  double time_spent2 = time_spent;
  printf("\n SELECTION end time: %f \n", time_spent);
  printf("\n");

  // Questão 3 - O que teremos que mudar para que função magina2 passe por
  // parametro um ponteiro duplo nada, já está feito 'bubblesort(n, &vet);' e
  // 'void bubblesort(long int n, int **ptr) '

  begin = clock();
  bubblesort(n, &vet);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\n BUBLE end time2: %f", time_spent);
  printf("\n buble2 end time1: %f", time_spent2);
  // Questão 4: Pq o tempo de execução é bem menor na função ?
  // não notei tanta diferença, no geral ela é menor que 1 segundo
  // apesar de não serem o mesmo metodo, mas são 2 metodos lentos
  // em uma quantidade baixa de dados a execução 1 é mais rápida mas começa a
  // ser mais lenta de acordo com o tamanho do vetor
  // utilizado até a execução com 200mil de registros e não houve diferença
  // significativa. a pouca diferença pode ser atribuida a forma como os metodos
  // atuam um forma de tornar a 'bubblesort' mais eficiente seria usar flags o
  // que mudaria significativamente esse tempo
  free(vet); // liberar memória da alocação dinamica
  return 0;
}
