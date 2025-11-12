// somma di n numeri

#include <stdio.h>

int main () {

    int ntotali, i, numero, somma = 0;

    printf ("\n Quanti numeri vuoi sommare=? \n");
    scanf ("%d", & ntotali);
    printf("\n Ora inserisci i numeri da sommare \n");

    for (i = 1; i <= ntotali; i++){

        scanf ("%d", &numero);
        
        somma = somma + numero;

    }

    printf ("\n La somma dei numeri è %d \n", somma);

    return 0;
}