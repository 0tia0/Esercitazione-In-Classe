#include <stdio.h>

int lettura() {
    int x;
    scanf("%d", &x);
    return x;
}

void riempimento(int *lista, int size) {
    for(int i=0; i<size; i++) {
        lista[i] = lettura();        
    }
}

void scrittura(char *name, int *lista, int size) {
    printf("\n\nLista %s: ", name);
    for(int i=0; i<size; i++) {
        printf("%d ", lista[i]);       
    }
}

void ricerca(int *lista, int size, int *out, int *count) {
    for(int i=0; i<size; i++) {
        if(lista[ i ] %2 == 0) {
            out[*count] = lista[i];
            (*count)++;
        }
    }
}

int main() {
    int v1[10];
    int v2[10];

    int count = 0;

    riempimento(v1, 10);

    ricerca(v1, 10, v2, &count);

    scrittura("valori",v1, 10);

    scrittura("pari",v2, count);
}

/*
Scrivi un codice che legga 15 valori dal terminale, una volta letti identifica e salva in liste separate i numeri pari, dispari. infine in una quarta lista salva l'array ordinato. termina
l'esecuzione stampando tutte le 4 liste.
*/

void bubbleSort(int *array, int size) {
    int temp;

    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {  
            if(array[j] > array[j + 1]) {      
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
