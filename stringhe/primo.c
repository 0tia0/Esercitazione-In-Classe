#include    <stdio.h>
#include    <stdbool.h>
#include    <Windows.h>
#include    <string.h>

#define     RED                                     "\e[0;31m"
#define     CYAN                                    "\e[0;36m"

#define     BOLD_RED                                "\e[1;31m"
#define     BOLD_GREEN                              "\e[1;32m"

#define     COLOR_RESET                             "\e[0m"

int arraySize() {
    int ret = 0;

    system("CLS");
    printf(CYAN "\nInserire la grandezza dell'array : " BOLD_GREEN);
    scanf("%d", &ret);

    return ret;
}

void readArray(char *array, int size) {
    system("CLS");
    printf(CYAN "\nInserire i %d caratteri dell'array (premevere INVIO alla fine) : " BOLD_GREEN, size);

    fflush(stdin);

    for(int i=0; i<size; i++) {   
        scanf("%c", &array[i]);
    }
}

bool isVocale(char x) {
    int c = (int) x;

    if(
        c == 97 || c == 101 || c == 105 || c == 111 || c == 117 ||
        c == 65 || c == 69 || c == 73 || c == 79 || c == 85
    ) {
        return true;
    }

    return false;
}

void findVocali(char *array, char *vocali, int size, int *size2) {
    for(int i=0, j=0; i<size; i++) {   
        if(isVocale(array[i])) {
            vocali[j] = array[i];
            j++;
            *size2 = j;
        }
    }
}

int main() {

    SetConsoleOutputCP(CP_UTF8);

    int size = arraySize();
    int size2 = 0;

    char *array = (char*) malloc(sizeof(char) * size);
    char *vocali = (char*) malloc(sizeof(char) * size);

    if(array == NULL || vocali ==  NULL) {
        return -1;
    }

    readArray(array, size);

    printf(CYAN "\n\nLa lista inserita è:");
    for(int i = 0; i < size; i++) {
        printf(RED "\n  - " BOLD_GREEN "%c", array[i]);
    }

    findVocali(array, vocali, size, &size2);

    printf(CYAN "\n\nLa lista contiene le seguenti vocali:");
    for(int i = 0; i < size2; i++) {
        printf(RED "\n  - " BOLD_GREEN "%c", vocali[i]);
    }

    printf(COLOR_RESET "\n\n\n");
    system("pause");

    return 0;

}