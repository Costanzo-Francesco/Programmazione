/*
ESERCIZIO 10
Inserire valore usando puntatore
*/

#include <stdio.h>

int main () {

    int valore;
    int *ptrToValore = &valore;
    printf("\nInserisci un valore numerico.\n");
    scanf("%d", &*ptrToValore);
    printf("\nIl tuo valore è %d.\n", *ptrToValore);
    return 0;
}