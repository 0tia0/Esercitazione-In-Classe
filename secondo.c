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

int randomPari() {
    int random = 0;

    do {
        random = rand() % (MAX_VALUE + 1 - MIN_VALUE) + MIN_VALUE;
    } while (random % 2 != 0);

    return random;
}

int randomDispari() {
    int random = 0;

    do {
        random = rand() % (MAX_VALUE + 1 - MIN_VALUE) + MIN_VALUE;
    } while (random % 2 == 0);

    return random;
}

void fillArray(int *array) {
    // Riempe l'array a posizioni pari con numeri pari e viceversa
    for(int i=0; i<N; i++) {
        if(i % 2 == 0) {
            array[i] = randomPari();
        } else {
            array[i] = randomDispari();
        }
    }
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

    printf(COLOR_RESET "\n\n\n");
    system("pause");

    return 0;

}