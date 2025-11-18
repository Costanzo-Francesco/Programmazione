//programma chre fa equazione tramite la somma successiva

#include <stdio.h>

int main () {

    int ris = 0, n1, n2, i;

    printf ("\n Inserisci due numeri per calcolarne la moltiplicazioni \n");

    scanf ("%d", & n1);
    scanf ("%d", & n2);

    for (i = 1; i <= n2; i++) {


        ris = ris + n1;
    }
printf ("Il risultato è %d \n", ris);
    
    return 0;
}