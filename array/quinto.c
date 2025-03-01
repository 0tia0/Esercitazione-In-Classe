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

bool search(int *array, int size, int element) {
    // Cerca se c'è già un elemento uguale nell array
    for(int i = 0; i<size; i++) {
        if(array[i] == element) {
            return true;
            break;
        }
    }

    return false;
}

void clearScreen() {
    system("cls");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int v1[N] = {-1};
    int v2[N] = {-1};

    int common[N] = {-1};
    int found = 0;

    clearScreen();

    printf(CYAN "\nDi seguito verrà chiesto di inserire %d valori in due liste differenti", N*2);
    printf(CYAN "\nIn una lista non ci possono essere due elementi identici, ma in due liste distinte si");
    printf(CYAN "\nI valori inseriti dovranno essere maggiori o uguali a 0, in caso una delle due condizioni");
    printf(CYAN "\nnon verrà rispetta sarà richiesto di digitare nuovamente il valore");

    printf(CYAN "\n\nAl termine del programma veranno mostrati gli elementi comuni alle due liste.");

    printf(COLOR_RESET "\n\nPremere un tasto per proseguire...");
    getch();

    int temp;
    int error = 0;

    // Per ogni lista chiede di inserire i valori e se alcuni sono doppi li richiede

    for(int i = 0; i<N; i++) {
        do {
            error++;

            clearScreen(); 

            if(error > 1) {
                printf(BOLD_RED "\nIl valore inserito non è valido, riprova!"); 
            }

            printf(CYAN "\n\nInserire il %d° valore della prima lista: " BOLD_RED, i+1); 
            scanf("%d", &temp);
        } while (search(v1, N, temp) || temp < 0);

        v1[i] = temp;
        error = 0;
    }

    for(int i = 0; i<N; i++) {
        do {
            error++;

            clearScreen(); 

            if(error > 1) {
                printf(BOLD_RED "\nIl valore inserito non è valido, riprova!"); 
            } 

            printf(CYAN "\n\nInserire il %d° valore della seconda lista: " BOLD_RED, i+1); 
            scanf("%d", &temp);
        } while (search(v2, N, temp) || temp < 0);

        v2[i] = temp;
        error = 0;
    }

    clearScreen(); 
    printf(YELLOW "\nHai inserito i seguenti valori:");

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

    printf(YELLOW "\n\nGli elementi comuni fra le due liste sono i seguenti: ");

    for(int i = 0; i<N; i++) {
        if(search(v2, N, v1[i])) {
            common[found] = v1[i];
            found++;
        }
    }

    for(int i = 0; i<found; i++) {
        if (i != found-1) {
            printf(CYAN "%d - ", common[i]);
        } else {
            printf(CYAN "%d", common[i]);
        }
    }

    printf(COLOR_RESET);
    printf("\n\n");
    system("pause");
}