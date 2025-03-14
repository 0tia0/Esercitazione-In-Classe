#include    <stdio.h>
#include    <stdbool.h>
#include    <Windows.h>
#include    <string.h>

#define     RED                                     "\e[0;31m"
#define     CYAN                                    "\e[0;36m"
#define     BOLD_RED                                "\e[1;31m"
#define     BOLD_GREEN                              "\e[1;32m"
#define     COLOR_RESET                             "\e[0m"
#define     BOLD_MAGENTA                            "\e[1;35m"

int counter;

typedef struct {
    char carattere;
    int frequency;
}caratteriRipetutui;

char CharUpperCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

char CharLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

void StringUpperCase(char *c) {
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] >= 'a' && c[i] <= 'z') {
            c[i] -= 32;
        }
    }
}

void StringLowerCase(char *c) {
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] >= 'A' && c[i] <= 'Z') {
            c[i] += 32;
        }
    }
}

void readArray(char *array, int size, char *name) {
    system("CLS");
    printf(CYAN "\nInserire il proprio %s (premere INVIO alla fine) [MAX %d CHAR]: " BOLD_GREEN, name, size - 1);

    fflush(stdin);
    fgets(array, size, stdin);
    
    size_t len = strlen(array);
    if (len > 0 && array[len - 1] == '\n') {
        array[len - 1] = '\0';
    }
}

void upperCaseAll(char *name, char *surname, char *codice) {
    StringLowerCase(name);
    StringLowerCase(surname);

    name[0] = CharUpperCase(name[0]);
    surname[0] = CharUpperCase(surname[0]);

    StringUpperCase(codice);
}

bool alredyExist(caratteriRipetutui* list, char c) {
    for(int i = 0; i<counter; i++) {
        if(c == list[i].carattere) {
            return true;
        }
    }

    return false;
}

void search(bool *d, char* codice, caratteriRipetutui* list) {
    for (int i = 0; codice[i] != '\0'; i++) {
        if ((codice[i] >= '0' && codice[i] <= '9') || alredyExist(list, codice[i])) {
            continue;
        }

        caratteriRipetutui temp;
        temp.carattere = codice[i];
        temp.frequency = 1;
        list[counter] = temp; 

        for (int j = i + 1; codice[j] != '\0'; j++) {
            if (list[counter].carattere == codice[j]) {
                list[counter].frequency++;
                *d = true;
            }
        }

        counter++;
    }
}


int main() {
    SetConsoleOutputCP(CP_UTF8);

    char name[50 + 1];
    char surname[50 + 1];
     
    
    char codiceFiscale[16 + 1];

    bool doppioni = false;
    caratteriRipetutui doppioniCodiceFiscale[16];

    readArray(name, sizeof(name), "nome");
    readArray(surname, sizeof(surname), "cognome");
    readArray(codiceFiscale, sizeof(codiceFiscale), "codice fiscale");

    upperCaseAll(name, surname, codiceFiscale);

    system("cls");
    printf(CYAN "\n\nBenvenuto " RED "%s %s" CYAN ", codice fiscale inserito " RED "%s", name, surname, codiceFiscale);

    printf(COLOR_RESET "\n\n\n");
    system("pause");
    system("cls");

    search(&doppioni, codiceFiscale, doppioniCodiceFiscale);

    if(doppioni) {
        printf(CYAN "\nEcco una lista dei doppioni trovati:");
        for(int i = 0; i<counter;i++) {
            if(doppioniCodiceFiscale[i].frequency == 1) {
                continue;
            }
            printf(RED "\n  -" BOLD_GREEN "%c " BOLD_MAGENTA ":" CYAN" si ripete %d volte", doppioniCodiceFiscale[i].carattere, doppioniCodiceFiscale[i].frequency);
        }
    }

    printf(COLOR_RESET "\n\n\n");
    system("pause");

    return 0;
}
