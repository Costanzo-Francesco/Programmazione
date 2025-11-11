//calcola la media dei numeri

#include <stdio.h>

int main () {

float n, ris, tot = 0, m, i, cont = 0;

    printf ("\n quanti numeri vuoi inserire per la media? \n");
    scanf("%f", & m);
    printf ("\n Ora inserisci i numeri \n");

    for (i = 1; i <= m; i++) {

        scanf("%f", & n);
        
        tot = tot + n;
        cont = cont + 1;


    }

    ris = tot/cont;

    printf("\n Ecco la media totale: %.2f \n", ris);
    return 0;
}