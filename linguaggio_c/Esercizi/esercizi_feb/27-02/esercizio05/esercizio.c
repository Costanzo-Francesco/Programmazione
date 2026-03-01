/*
ESERCIZIO 5
Stampare un array con i puntatori
*/

#include <stdio.h>

const int DIMARRAY = 4;

int main (){

    int arr[] = {10, 20, 30, 40};
    int *p = arr;

    printf("\n");
    for (int i = 0; i < DIMARRAY; i++){

        printf("Numero nell'array: %d\n", *(p + i));
    }
    return 0;
}