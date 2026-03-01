/*
ESERCIZIO 7
Raddoppiare un numero con funzione
*/

#include <stdio.h>

void raddoppio (int *x) {

    *x *=  2;
}

int main () {

    int n1 = 2;
    int *ptr = &n1;
    raddoppio(&*ptr);

    printf("\nIl numero raddoppiato è %d.\n", *ptr);
    return 0;
}