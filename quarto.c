#include    <stdio.h>
#include    <time.h>
#include    <stdlib.h>
#include    <Windows.h>

#define     MAX_VALUE                               100
#define     MIN_VALUE                               0

#define     N                                       9

#define     RED                                     "\e[0;31m"
#define     CYAN                                    "\e[0;36m"
#define     YELLOW                                  "\e[0;33m"

#define     BOLD_RED                                "\e[1;31m"
#define     BOLD_GREEN                              "\e[1;32m"
#define     BOLD_MAGENTA                            "\e[1;35m"

#define     COLOR_RESET                             "\e[0m"

#define     debugGenDelay                           1
#define     debugGenDelayMs                         debugGenDelay * 1000

int getRandInt() {
    return rand() % (MAX_VALUE + 1 - MIN_VALUE) + MIN_VALUE;
}

void fillArray(int *array) {
    // Riempe partendo dal fondo e dall'inizio di numeri
    // Se pari si riempe completamente senza problemi
    // Se dispari il codice provvederà all'aggiunta di un valore centrale
    for(int i=0, j=N-1; i<N/2; i++, j--) {
        array[i] = getRandInt();
        array[j] = getRandInt();
    }
    
    // Gestisco l'aggiunta manuale di un valore centrale nel caso N sia dispari
    if(N%2 != 0) {
        array[N/2] = getRandInt();
    }
}

void sortArray(int *array, int *dest) {
    // Ad ogni iterazione imposto il valore corrente a k e il valore succesivo a j, cio significa assegnare il corrente(i) al corrente(k) dall'array disordinato
    // e il corrente(i)+1 al corrente (j) [j scorre l'array al contrario]
    for(int i = 0, j = N-1, k=0; i < N-1; i+=2, j--, k++) {
        dest[i] = array[k];
        dest[i+1] = array[j];
    }
    
    // In caso N sia dispari il codice si occupa di spostare il valore centrale della prima lista nella lista ordinata
    if(N%2 != 0) {
        dest[N-1] = array[N/2];
    }
}

int main() {
    
    srand(time(NULL));

    int array[N];
    fillArray(array);

    int sortedArray[N];
    sortArray(array, sortedArray);

    system("cls");

    printf(CYAN "\nIl vettore contiene i seguenti valori:");
    for(int i = 0; i < N; i++) {
        if(N%2 != 0 && i==N/2) {  
            printf(RED "\n  - " YELLOW "%d", array[i]);
            continue;
        }

        if(i < N/2) {
             printf(RED "\n  - " BOLD_GREEN "%d", array[i]);
        } else {
             printf(RED "\n  - " BOLD_MAGENTA "%d", array[i]);
        }
    }

    printf(CYAN "\n\nIl vettore ordinato:");
    for(int i = 0; i < N; i++) {
        if(N%2 != 0 && i==N-1) {  
            printf(RED "\n  - " YELLOW "%d", sortedArray[i]);
            continue;
        }

        if(i%2 == 0) {
            printf(RED "\n  - " BOLD_GREEN "%d", sortedArray[i]);
        } else {
            printf(RED "\n  - " BOLD_MAGENTA "%d", sortedArray[i]);
        }        
    }

    printf(COLOR_RESET "\n\n\n");
    system("pause");

    return 0;

}