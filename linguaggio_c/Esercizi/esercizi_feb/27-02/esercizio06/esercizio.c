/*
ESERCIZIO 6
Somma di due numeri tramite puntatori
*/

#include <stdio.h>

int main () {

    int n1 = 10;
    int n2 = 20;
    int *p1 = &n1;
    int *p2 = &n2;
    int ris = *p1 + *p2;

    printf("\nIl risultato di %d + %d = %d", *p1, *p2, ris);
    return 0;
}
