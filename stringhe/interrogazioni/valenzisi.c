#include <stdio.h>

#define ARRAY_SIZE 10

int isValid(int x) {
    if(x>=0 && x<=1023) {
        return 1;
    }

    return 0;
}

void printArray(char *name, int *array, int size){
    printf("\nLista %s: ", name);

    for(int i = 0; i<size; i++) {
        printf("%d ", array[i]);
    }
}

int readNumber() {
    int readed = 0;
    printf("\nDigitare una valore ? ");
    scanf("%d", &readed);
    return readed;
}

int main() {
    int read = 0;
    int vector[ARRAY_SIZE];
    int count = 0;

    while(count<ARRAY_SIZE) {
        read = readNumber();

        if(isValid(read)) {
            vector[count] = read;
            count++;
        }
    }

    printArray("valori", vector, ARRAY_SIZE);
}