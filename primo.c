#include    <stdio.h>
#include    <time.h>
#include    <stdlib.h>
#include    <Windows.h>

#define     MAX_VALUE                               100
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

int findPari(int *array, int *dest) {
    // Trova i pari e li mette nell'array fornito come dest
    int j = 0;

    for(int i=0; i<N; i++) {
        if(array[i] % 2 == 0) {
            //pari
            dest[j] = array[i];
            j++;
        }
    }

    return j; //amount
}

int findPariIndex(int *array, int *dest) {
    // Trova gli elementi ad indice pari e li mette nell'array fornito come dest
    int j = 0;

    for(int i=0; i<N; i++) {
        if(i % 2 == 0) {
            //pari
            dest[j] = array[i];
            j++;
        }
    }

    return j; //amount
}

int main() {
    
    srand(time(NULL));

    int array[N];
    fillArray(array);

    int arrayPari[N]; 
    int totalPari = findPari(array, arrayPari);

    int arrayIndexPari[N];
    int indexPari = findPariIndex(array, arrayIndexPari);

    system("cls");

    printf(CYAN "\nIl vettore contiene i seguenti valori:");
    for(int i = 0; i < N; i++) {
        printf(RED "\n  - " BOLD_GREEN "%d", array[i]);
    }

    printf(CYAN "\n\nIl vettore contiene i seguenti valori pari:");
    for(int i = 0; i < totalPari; i++) {
        printf(RED "\n  - " BOLD_GREEN "%d", arrayPari[i]);
    }

    printf(CYAN "\n\nI valori posizionati in posizione pari sono:");
    for(int i = 0; i < indexPari; i++) {
        printf(RED "\n  - " BOLD_GREEN "%d", arrayIndexPari[i]);
    }

    printf(COLOR_RESET "\n\n\n");
    system("pause");

    return 0;

}