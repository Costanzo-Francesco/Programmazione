/*
Genera un array di numeri casuali scelti dall'utente da 1 a 100
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int max = 100;
const int min = 1;

int main () {
    
    int totn;

    printf("\nScegli il numero dei valori casuali da generare: \n");
    scanf("%d", &totn);
    int  numeri[totn];
    srand(time(NULL));
    for (int i = 0; i < totn; i++) {

        numeri[i] = rand() % max + min;
    }
    printf ("I numeri sono:\n");
    for (int i = 0; i < totn; i++){

        printf("%d \t", numeri[i]);
    }
    printf("\n");
    
    return 0;
}