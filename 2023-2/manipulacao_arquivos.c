#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // 1 Faça uma função capaz de salvar um vetor de inteiros de 1 até 10 em um arquivo.
    FILE *file = fopen("arquivo.txt", "w");
    for (int i = 1; i <= 10; i++) {
        fprintf(file, "%d\n", i);
    }
    fclose(file);

    // 2 Faça um código em C para armazenar um vetor randômico com 500 valores inteiros.
    FILE *file2 = fopen("arquivo2.txt", "w");
    fprintf(file2, "Vetor:[");
    for (int i = 0; i < 500; i++) {
        int numero = rand() % 501;
        fprintf(file2, "%d, ", numero);
    }
    fprintf(file2, "]");
    fclose(file2);

    // 3 No arquivo da questão 4, faça uma função capaz de remover os números maiores que a média, e refazer o salvamento no arquivo.
    FILE *file3 = fopen("arquivo2.txt", "r");
    char c;
    while ((c = fgetc(file3)) != '[' && c != EOF) {}

    int numeros[500];
    int contador = 0;

    while (contador < 500 && fscanf(file3, "%d, ", &numeros[contador]) == 1) {
        contador++;
    }

    double soma = 0;
    for (int i = 0; i < contador; i++) {
        soma += numeros[i];
    }
    double media = soma / contador;

    fclose(file3);

    file3 = fopen("arquivo2.txt", "w");

    fprintf(file3, "Vetor:[");
    for (int i = 0; i < contador; i++) {
        if (numeros[i] <= media) {
            fprintf(file3, "%d, ", numeros[i]);
        }
    }
    fprintf(file3, "]");
    fclose(file3);
    
    // 4. Crie um código em C para armazenar o seguinte texto em C:
    FILE *file4 = fopen("texto.txt", "w");

    fprintf(file4, "Eu sei trabalhar com arquivos em C");

    fclose(file4);

    // 5. Abra o arquivo anterior, apague a string “em C” e adiciona e string “em todas as linguagens de programação” usando o Fseek;
    file4 = fopen("texto.txt", "r+");
    char buffer[1024];
    size_t tamanho_buffer = sizeof(buffer);
    char *substring_procurada = "em C";
    char *substituicao = "em todas as linguagens de programação";
    size_t tamanho_substring_procurada = strlen(substring_procurada);
    size_t tamanho_substituicao = strlen(substituicao);
    int achou2 = 0; // Indicador se a substring foi encontrada

    while (fgets(buffer, tamanho_buffer, file4) != NULL) {
        char *posicao = strstr(buffer, substring_procurada);
        if (posicao != NULL) {
            achou2 = 1;
            size_t posicao_inicio = posicao - buffer;
            size_t posicao_fim = posicao_inicio + tamanho_substring_procurada;
            
            strncpy(buffer + posicao_inicio, substituicao, tamanho_substituicao);
            buffer[posicao_inicio + tamanho_substituicao] = '\0';

            fseek(file4, -ftell(file4), SEEK_CUR);
            fprintf(file4, "%s", buffer);
            fflush(file4);
        }
    }
    fclose(file4);

    //6 Altere  o arquivo para adicionar a string  “quase”
    file4 = fopen("texto.txt", "r+");
    char buffer2[1024];
    size_t tamanho_buffer2 = sizeof(buffer2);
    char *substring_procurada2 = "em todas";
    char *substituicao2 = "em quase todas";
    size_t tamanho_substring_procurada2 = strlen(substring_procurada2);
    size_t tamanho_substituicao2 = strlen(substituicao2);
    int achou = 0;

    while (fgets(buffer2, tamanho_buffer2, file4) != NULL) {
        char *posicao = strstr(buffer2, substring_procurada2);
        if (posicao != NULL) {
            achou2 = 1;
            size_t posicao_inicio = posicao - buffer2;
            size_t posicao_fim = posicao_inicio + tamanho_substring_procurada2;
            char buffer2_temp[1024];
            snprintf(buffer2_temp, sizeof(buffer2_temp), "%.*s%s%.*s",
                     (int)posicao_inicio, buffer2, substituicao2, (int)(strlen(buffer2) - posicao_fim), posicao + tamanho_substring_procurada2);

            // Escrever o buffer2 temporário de volta para o arquivo
            fseek(file4, -ftell(file4), SEEK_CUR);
            fprintf(file4, "%s", buffer2_temp);
            fflush(file4);
        }
    }

    fclose(file4);
    
    return 0;
}
