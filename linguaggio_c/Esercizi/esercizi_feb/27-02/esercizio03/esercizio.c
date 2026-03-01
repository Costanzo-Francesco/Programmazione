/*
ESERCIZIO 3
Stampare due numeri usando i puntatori
*/

#include <stdio.h>

int main () {

    int numeri[] = {10, 20};
    int *ptr = numeri;

    printf("\nNumero 1: %d", *(ptr));
    printf("\nNumero 1: %d\n", *(ptr + 1));
    return 0;
}