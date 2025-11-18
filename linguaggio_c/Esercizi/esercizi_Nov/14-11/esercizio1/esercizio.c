//Scrivi un programma che legge una sequenza di numeri interi positivi. si ferma con lo 0. e cerca il valore minimo + stampa.

#include <stdio.h>

int main () {

    int n, min;
    
    printf ("\n Inserisci dei numeri positivi per conoscerne il minimo, se inserisci 0 calcola \n");
    scanf ("%d", & n);
    while (n <= 0){

        printf ("Per inizializzare il programma, inserisci un numero positivo\n");
        scanf ("%d", & n);

    }

    min = n;

    while ( n != 0) {

        scanf ("%d", & n);

        if (n == 0 || n < 0){

    } else if (n < min){

        min = n;
    }
}
printf ("Il numero minore è %d \n", min);
    return 0;
}                