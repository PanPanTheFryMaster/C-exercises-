#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int calcola_minimo(int array[], int size);
int calcola_massimo(int array[], int size);
float calcola_media(int array[], int size);
void ordina_array(int array[], int size);
int ricerca_ricorsiva(int array[], int start, int finish, int target);
int main() {
    int array[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 10;
    }

    printf("array non ordinato: ");
    for (int i =0 ; i < 10; i++){ printf("%d ", array[i]);}
    ordina_array(array, 10);
    printf("\n\n");
    printf("array ordinato: ");
    for (int i =0 ; i < 10; i++){ printf("%d ", array[i]);}
    printf("\n\n");
    printf("Minimo: %d\n", calcola_minimo(array, 10));
    printf("Massimo: %d\n", calcola_massimo(array, 10));
    printf("Media: %f\n", calcola_media(array, 10));

    printf("Cerco elemento 5, Esiste? %d", ricerca_ricorsiva(array, 0, 10, 5));
    return 0;
}

int calcola_minimo(int array[], int size) {
    int minimo = INT_MAX;
    for (int i = 0; i < size; i++) {
        minimo = (array[i] < minimo) ? array[i] : minimo;
    }

    return minimo;
}

int calcola_massimo(int array[], int size) {
    int massimo = INT_MIN;
    for (int i = 0; i < size; i++) {
        massimo = (array[i] > massimo) ? array[i] : massimo;
    }

    return massimo;
}

float calcola_media(int array[], int size) {
    float media = 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum / size;
}

int ricerca_ricorsiva(int array[], int start, int finish, int target) {
    // Caso base: l'intervallo è vuoto
    if (start > finish) {
        return 0; // Target non trovato
    }

    int mid = start + (finish - start) / 2; // Calcolo il punto medio

    // Caso base: l'elemento è trovato
    if (array[mid] == target) {
        return 1; // Target trovato
    }

    // Ricerca nella metà destra
    if (target > array[mid]) {
        return ricerca_ricorsiva(array, mid + 1, finish, target);
    }

    // Ricerca nella metà sinistra
    return ricerca_ricorsiva(array, start, mid - 1, target);
}


void ordina_array(int array[], int size) {
    int tmp = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size; j++) {
            if (array[i] > array[j]) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}