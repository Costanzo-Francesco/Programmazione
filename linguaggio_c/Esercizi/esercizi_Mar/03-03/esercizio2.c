#include <stdio.h>

int main () {

    int nArray;
    printf("\nQuanti numeri vuoi inserire?");
    scanf("%d", &nArray);
    printf("\nOra inserisci i %d numeri che desideri verificare:\n", nArray);
    
    int arr[nArray];
    int *ptrToArr = arr;

    for (int i = 0; i < nArray; i++){
        scanf("%d", &*ptrToArr + i);
    }
    int cont = 0;

    for (int i = 0; i < nArray; i++){
    
        if (*(ptrToArr + i) > 0){
            cont += 1;
        }
    }

    printf("\nI numeri positivi sono %d.", cont);
    return 0;
}