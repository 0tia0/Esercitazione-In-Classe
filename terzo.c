#include    <stdio.h>
#include    <time.h>
#include    <stdlib.h>
#include    <Windows.h>

#define     MAX_VALUE                               10
#define     MIN_VALUE                               0

#define     N                                       10

#define     RED                                     "\e[0;31m"
#define     CYAN                                    "\e[0;36m"

#define     BOLD_RED                                "\e[1;31m"
#define     BOLD_GREEN                              "\e[1;32m"

#define     COLOR_RESET                             "\e[0m"

void fillArray(int *array) {
    // Riempe in modo casuale l'array con numeri compresi fra MAX_VALUE e MIN_VALUE
    for(int i=0; i<N; i++) {
        array[i] = rand() % (MAX_VALUE + 1 - MIN_VALUE) + MIN_VALUE;
    }
}

int findMax(int *array) {
    // Trova il valore maggiore nell'array
    int max = array[0];

    for(int i=0; i<N; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

int findMaxIndex(int *array) {
    // Trova l'indice a cui si trova il valore maggiore e ritorna l'indice
    int max = array[0];
    int maxIndex = 0;

    for(int i=0; i<N; i++) {
        if (array[i] > max) {
            max = array[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

int findMostCommon(int *array) {
    // Per ogni valore incrementiamo in una seconda lista il num. a lista[valore] e depo cercando il numero maggiore in questa nuovo indice troviamo il numero piu presente
    // Ad esempio se troviamo un 7 incrementiamo il valore in posizione 7 e così via. se troviamo che all'indice 7 c'è il numero più alto della seconda lista sappiamo che
    // il 7 è il numero più presente
    int max = findMax(array);
    int *newArray = malloc(( max + 1 ) * sizeof(int));

    for(int i=0; i<N; i++) {
        newArray[i] = 0;
    }

    for(int i=0; i<N; i++) {
        newArray[array[i]]++;
    }

    int mostCommon = findMaxIndex(newArray);

    free(newArray);
    return mostCommon;
}

int main() {
    
    srand(time(NULL));

    int array[N];
    fillArray(array);

    system("cls");

    printf(CYAN "\nIl vettore contiene i seguenti valori:");
    for(int i = 0; i < N; i++) {
        printf(RED "\n  - " BOLD_GREEN "%d", array[i]);
    }
    
    printf("\n\nIl piu presente e: %d", findMostCommon(array));

    printf(COLOR_RESET "\n\n\n");
    system("pause");

    return 0;

}