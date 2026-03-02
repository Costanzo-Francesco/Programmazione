/*
ESERCIZIO 4
Scambiare due numeri
*/

#include <stdio.h>


void scambio (int *x, int *y){

    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main (){

    int n1 = 5;
    int n2 = 10;
    
    printf("\nIl primo valore è %d e il secondo è %d", n1, n2);

    scambio(&n1, &n2);
    
    printf("\nIl primo valore è %d e il secondo è %d", n1, n2);

    return 0;
}