//leggi una serie di numeri al primo 0 incontrato determina quanti numeri sono stati letti e la loro somma
#include <stdio.h>

void controllo ();

int main () {

    printf("\nInserisci una sequenza di numeri per conoscere il numero di quanti sono stati letti e la loro somma\n");
    controllo ();
    return 0;
}

void controllo () {

    int cont, n;
    do{
    printf("scrivi un numero\n");
    scanf("%d", &n);
    cont += 1;
    somma += n;

    }
}