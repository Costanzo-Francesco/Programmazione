/*
ESERCIZIO 8
Stampare un numero usando puntatore a puntatore
*/

#include <stdio.h>

int main () {
    
    int n1 = 10;
    int *ptr1 = &n1;
    int **ptr2 = &ptr1;

    printf("\nIl numero è %d", **ptr2);
    return 0;
}