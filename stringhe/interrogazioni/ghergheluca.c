//leggere n numeri interi e separi due numeri element in posizione pari e gli altri in posizioni disspari

//DAFIXARE

#include <stdio.h>

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

reorderArray(int *original, int *pari, int *dispari, int size) {
    int i=0,j=0;

    for(i,j;i<size-1;i+=2,j++) {
        pari[j] = original[i];
        dispari[j] = original[i+1];
    }

    if(size%2!=0) {
        dispari[j+1] = original[i];
    }
}

int main() {
    int size;
    printf("Dimensione array ? ");
    scanf("%d", &size);

    int vector[size];
    int pari[size];
    int dispari[size];

    readArray("valori inseriti", vector, size);

    reorderArray(vector,pari,dispari,size);

    printArray("valori inseriti", vector, size);
    printArray("valori i pari", pari, size/2);

    size = ((size%2 != 0) ? size/2+1 : size/2);

    printArray("valori i dispari", dispari, size);
}