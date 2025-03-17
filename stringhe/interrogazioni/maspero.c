#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void printArray(char *name, int *array, int size){
    printf("\nLista %s: ", name);

    for(int i = 0; i<size; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    srand(time(NULL));

    int vector[ARRAY_SIZE] = {0};
    int vector_traslated[ARRAY_SIZE] = {0};

    int temp = 0;

    for(int i = 0; i<ARRAY_SIZE; i++) {
        vector[i] = ( rand() % 100 ) + 1;
    }

    
    printArray("generata", vector, ARRAY_SIZE);

    temp = vector[ARRAY_SIZE - 1];

    for(int i = 1; i<ARRAY_SIZE; i++) {
        vector_traslated[i] = vector[i-1];
    }

    vector_traslated[0] = temp;

    printArray("modificata", vector_traslated, ARRAY_SIZE);
}