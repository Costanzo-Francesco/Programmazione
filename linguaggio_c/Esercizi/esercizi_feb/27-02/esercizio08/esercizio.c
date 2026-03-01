/*
ESERCIZIO 8
Stampare un numero usando puntatore a puntatore
*/

#include <stdio.h>

int main () {
    
    int n1 = 10;
    int *ptr = &n1;
    int **ptr = &ptr;

    printf("\nIl numero è %d", **ptr);
    return 0;
}