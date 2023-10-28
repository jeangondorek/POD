#include <stdio.h>
#include <stdlib.h>

int main() {
    //1 Faça uma função capaz de salvar um vetor de inteiros de 1 até 10 em um arquivo. 
    FILE *file = fopen("arquivo.txt", "w");

    for (int i = 1; i <= 10; i++) {
        fprintf(file, "%d\n", i);
    }
    //2 Faça um código em C para armazenar um vetor randômico com 500 valores inteiros. 
    FILE *file2 = fopen("arquivo2.txt", "w");
    fprintf(file2, "Vetor:["); // Escreva o número no arquivo
    for (int i = 0; i < 500; i++) {
        int numero = rand(); // Gere um número randômico
        fprintf(file2, "%d, \t", numero); // Escreva o número no arquivo
    }
    fprintf(file2, "]");
    //3 No arquivo da questão 2, faça uma função capaz de remover os números maiores que a média, e refazer o salvamento no arquivo. 
    fscanf(file2)
    while (fscanf(file, "%d,", &numero) != EOF) {
        soma += numero;
        contador++;
    }

    fclose(file);
    fclose(file2);

    return 0;
}
