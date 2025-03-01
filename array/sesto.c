#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define     N                                       10

#define     RED                                     "\e[0;31m"
#define     CYAN                                    "\e[0;36m"
#define     YELLOW                                  "\e[0;33m"

#define     BOLD_RED                                "\e[1;31m"
#define     BOLD_GREEN                              "\e[1;32m"
#define     BOLD_MAGENTA                            "\e[1;35m"

#define     COLOR_RESET                             "\e[0m"

void clearScreen() {
    system("cls");
}

void bubbleSort(int *array, int size) {
    // Bubble Sort algorithm
    int i, j, temp;
    bool modifications = false;

    for(int i = 0; i < size-1; i++) {
        modifications = false;
        for(int j = 0; j < size-1-i; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                modifications = true;
            }
        } 

        if(modifications == false) {
            break;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int v1[N] = {-1};
    int v2[N] = {-1};

    int common[N] = {0};

    clearScreen();

    //Legge valori delle liste
    for(int i = 0; i<N; i++) {
        clearScreen();
        printf(CYAN "\n\nInserire il %d° valore della prima lista: " BOLD_RED, i+1); 
        scanf("%d", &v1[i]);
    }

    for(int i = 0; i<N; i++) {
        clearScreen();
        printf(CYAN "\n\nInserire il %d° valore della seconda lista: " BOLD_RED, i+1); 
        scanf("%d", &v2[i]);
    }

    clearScreen(); 
    printf(YELLOW "\nHai inserito i seguenti valori:");
    
    //Stampa le liste
    printf(BOLD_RED "\n\nPrima lista: ");
    for(int i = 0; i<N; i++) {
        if (i != N-1) {
            printf(CYAN "%d - ", v1[i]);
        } else {
            printf(CYAN "%d", v1[i]);
        }
    }

    printf(BOLD_RED "\nSeconda lista: ");
    for(int i = 0; i<N; i++) {
        if (i != N-1) {
            printf(CYAN "%d - ", v2[i]);
        } else {
            printf(CYAN "%d", v2[i]);
        }
    }

    printf(YELLOW "\n\nLe due liste unite ed ordinate: ");

    //Unisce le liste
    for(int i = 0; i<N; i+=2) {
        common[i] = v2[i];
        common[i+1] = v1[i];
    }  
    
    //La ordina
    bubbleSort(common, N*2);

    //Stampa la lista ordinata
    for(int i = 0; i<N*2; i++) {
        if (i != (N*2)-1) {
            printf(CYAN "%d - ", common[i]);
        } else {
            printf(CYAN "%d", common[i]);
        }
    }

    printf(COLOR_RESET);
    printf("\n\n");
    system("pause");
}