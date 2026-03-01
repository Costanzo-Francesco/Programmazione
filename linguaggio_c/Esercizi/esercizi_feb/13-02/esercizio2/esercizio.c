#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int MAX = 50;
const int MIN = 1;
const int N = 10;


void stampaArray (int numeri[]){
    printf("\nI numeri sono %d e sono:\n", N);
    for (int i = 0; i < N; i++){

        printf("%d\t", numeri[i]);
    }
}


float fmedia (int numeri[]){
    float fNumeri[N];
    float somma = 0;
    float totNumeri;
    float media;

    totNumeri = (float)N;
    printf("\nI numeri sono %d e sono:\n", N);
    for (int i = 0; i < N; i++){
        fNumeri[i] = (float) numeri[i];
        somma += fNumeri[i];
    }
    
    media = somma/totNumeri;
    return media;
}


int minimo (int numeri[]){
    int min;
    min = numeri[0];
    for (int i = 0; i < N; i++){
        if (numeri[i] < min){
            min = numeri[i];
        }
    }
    return min;
}


void ricerca (int numeri[], int lunghezza, int rNumero){

    int verdetto = -1;
    int posizione;

        for (int i = 0; i < lunghezza; i++){
            if (rNumero == numeri[i]){
                verdetto = i + 1;
            }
        }
    if (verdetto != -1){
        printf("\nIl numero %d è presente alla cella numero:%d", rNumero, verdetto);
    }   else {
        printf("\nIl numero %d non è presente : %d", rNumero, verdetto);
    }
    
}


int main () {

    int numeri[N];
    float media;
    int min;
    int lunghezza;
    int rNumero;
    srand(time(NULL));
    
    for (int i = 0; i < N; i++){
        numeri[i] = (rand() % (MAX - MIN + 1)) + MIN;
    }

    lunghezza = sizeof(numeri) / sizeof(numeri[0]);

    stampaArray(numeri);
    media = fmedia(numeri);
    min = minimo(numeri);

    printf("La media è: %0.2f.\nIl minimo è %d.\n",media, min);
    printf("\nInserisci un numero da ricercare:  ");
    scanf("%d", &rNumero);
    ricerca(numeri, lunghezza, rNumero);
    printf("\n");

    return 0;
}