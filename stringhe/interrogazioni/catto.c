//srivere un programma che legge un vettore di lunghezza arbitraria e stampa 1 se tutti i valori sono diversi 0 altrimenti
#include <stdio.h>

#define ARRAY_SIZE 3

void readArray(char *name, int *array, int size){
    printf("\nInserire valori per la lista %s: ", name);

    for(int i = 0; i<size; i++) {
        printf("\n%d valore ? ", i+1);
        scanf("%d", &array[i]);
    }
}

void printArray(char *name, int *array, int size){
    printf("\n\nLista %s: ", name);

    for(int i = 0; i<size; i++) {
        printf("%d ", array[i]);
    }
}

int findDoppioni(int *array, int size) {
    int result;

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(array[i] == array[j]) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int v[ARRAY_SIZE];

    readArray("valori", v, ARRAY_SIZE);

    printArray("valori letti", v, ARRAY_SIZE);

    int doppioni = findDoppioni(v, ARRAY_SIZE);
    printf("\n\nVerra stampanto 1 se tutti i valori sono diversi fra loro, altrimenti uno. Risultato : %d", doppioni);
}