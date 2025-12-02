/*
Pari o dispari?
analizza il contenuto di un array
1. genera un array di 20 numeri casuali  tra 1 e 50
2. Scorri l'array e conta quanti sono i numeri pari e quanti i dispari
3. stampa il risultato (ci sono 12 numeri pari e 8 dispari)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 20;
const int min = 1;
const int max = 50;

int main() {

    int numeriCasuali[N];

    srand (time (NULL));

    for (int i = 0; i < 10; i++){

        numeriCasuali[i] = rand () max + min;
    }

    return 0;
} 