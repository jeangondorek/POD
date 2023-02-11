// bubble sort
// without flags, with flags more optimized
#include <stdio.h>
#include <stdlib.h>

int main(){
    int count;

    printf("Digite a quantidade de números da lista: ");
    scanf("%d", &count);

    int aux, lista[count];

    // o valor dentro da lista será gerado aleatóriamente no range de (count + 10) que foi digitado pelo usuário
    for (int i = 0; i <= count; i++){
        lista[i] = rand() % count+10;
    }

    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }

    printf("\n");


    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (lista [j] > lista[j+1])
            {
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
        }
    }



    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");

}