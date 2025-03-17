#include <stdio.h>

#define ARRAY_SIZE 3

void readArray(char *name, int *array, int size){
    printf("\nInserire valori per la lista %s: ", name);

    for(int i = 0; i<size; i++) {
        printf("\n%d valore ? ", i+1);
        scanf("%d", &array[i]);
    }
}

int* invertiArray(int *array, int *flippedArray, int size) {
    for(int i=size,j=0; j<ARRAY_SIZE; i--,j++) {
        flippedArray[j] = array[i-1];
    }

    return flippedArray;
}

void printArray(char *name, int *array, int size){
    printf("\n\nLista %s: ", name);

    for(int i = 0; i<size; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    int v[ARRAY_SIZE];
    int fv[ARRAY_SIZE];

    readArray("valori", v, ARRAY_SIZE);

    invertiArray(v,fv,ARRAY_SIZE);

    printArray("originale", v, ARRAY_SIZE);
    printArray("invertita", fv, ARRAY_SIZE);
}