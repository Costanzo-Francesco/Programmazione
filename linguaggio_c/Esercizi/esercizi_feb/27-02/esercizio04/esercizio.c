/*
ESERCIZIO 4
Scambiare due numeri
*/

#include <stdio.h>

int main (){

    int n1 = 5;
    int n2 = 10;
    int temp;

    int *ptr1 = &n1;
    int *ptr2 = &n2;

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    
    printf("\nIl primo valore è %d e il secondo è %d", n1, n2);
    return 0;
}