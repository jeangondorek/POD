#include <stdio.h>

int printarray(int lista[], int count){
    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");
}
