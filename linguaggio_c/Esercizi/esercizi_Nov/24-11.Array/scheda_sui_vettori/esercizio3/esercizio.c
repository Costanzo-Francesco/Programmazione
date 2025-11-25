/*
3) Dato un vettore di 6 numeri:
    • Trova il valore massimo.
    • Trova il valore minimo.
    • Stampa anche la posizione (indice) di massimo e minimo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int volte=6;
int main () {

    int numeri[5], max, min;
    int indice_max, indice_min;
    for (int i = 1; i <= volte - 1; i++){

    double r_min = 1;
    double r_max = 6;
    // Inizializzazione del generatore
    srand(time(NULL));

    numeri[i] = min + ((double)rand() / RAND_MAX) * (r_max - r_min);
    
    if (i == 1) {

        max = numeri[i];
        min = numeri[i];    
    }
    if (numeri[i] >= max){

        max = numeri[i];
        indice_max = i;
    }
    if (numeri[i] < min){

        min = numeri[i];
        indice_min = i;
    }
    }
    printf ("Il numero più alto è %d alla posizione %d. Il numero più piccolo è %d alla posizione %d", max, indice_max, min, indice_min);

    return 0;

}