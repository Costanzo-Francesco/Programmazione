//9 Leggi un numero e, dove è possibile, calcola la radice quadrata visualizzando il risultato, altrimenti comunica un
//  messaggio d’errore.

#include <stdio.h>
#include <math.h>

int main () {

    float r, n;

    printf ("\n Inserisci un numero per calcolarne la radice \n");
    scanf ("%f", & n);
    if (n<0) {

        printf("\n Non esistono numeri irrazionali minori di 0 \n");

    } else {

        r = sqrt (n);
        

        printf("La radice quadrata di %0.2f è %0.2f", n, r);
    }

    return 0;
}