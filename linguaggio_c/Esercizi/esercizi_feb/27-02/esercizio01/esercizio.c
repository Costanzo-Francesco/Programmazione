/*
ESERCIZIO 1
Stampare valore e indirizzo di una variabile
*/

#include <stdio.h>

int main () {

    int valore = 10;
    int *p = &valore;

    printf("\nIl valore è uguale a %d.", *p);
    printf("\nL'indirizzo è %p. \n", p);

    return 0;
}