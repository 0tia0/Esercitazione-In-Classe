#include <stdio.h>

int isValid(char c){
    if(c>='a' && c<='z' || c>='A' && c<='Z') {
        return 1;
    }

    return 0;
}

void printArray(char *name, char *array, int size){
    printf("\nLista %s: ", name);

    for(int i = 0; i<size; i++) {
        printf("%c ", array[i]);
    }
}

void readArray(char *name, char *array, int size){
    printf("\nInserire valori per la lista %s: ", name);

    for(int i = 0; i<size; i++) {
        printf("\n%d valore ? ", i+1);
        fflush(stdin);
        scanf("%c", &array[i]);
    }
}

void sostituzione(char c, char* vector, int size) {
    for(int i = 0; i<size; i++) {
        if(vector[i] == c) {
            vector[i] = '#';
        }
    }
}

int main() {
    int size;
    scanf("%d", &size);

    char read = '\0';
    //char *vector = malloc(sizeof(char) * size);

    char vector[size];

    readArray("caratteri", vector, size);

    fflush(stdin);

    char c;
    scanf("%c", &c);

    sostituzione(c, vector, size);

    printArray("valori", vector, size);
}