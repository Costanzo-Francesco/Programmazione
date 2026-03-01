/*
ESERCIZIO 2
Modificare una variabile tramite puntatore
*/

#include <stdio.h>

int main () {

    int variabile = 10;
    int *p = &variabile;

    printf("\nIl valore è %d.", *p);
    *p = 5;
    printf("\nIl valore cambiato è %d.", *p);

    return 0;
}