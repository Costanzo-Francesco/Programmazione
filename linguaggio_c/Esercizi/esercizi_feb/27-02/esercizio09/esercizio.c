/*
ESERCIZIO 9
Contare elementi di un array con puntatore
*/

#include <stdio.h>

int main (){

        int arr[] = {1,2,3,4,5};
        int *ptr = arr;

        printf("\n");

        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
            printf("%d\t", *ptr + i);
        }


    return 0;
}