// Inserire num postivi. calcola il fattoriale 0 termina il programma
#include <stdio.h>

int main (){

    int n = 1;
    int i;
    int ris = 1;

    printf("\n Inserisci numeri per ottenerne il fattoriale. 0 termina il programma\n");

  

    while (n!=0) {

    scanf ("%d", &n);
    ris=1;
    if (n>0) {    
        for (i = 1; i <= n; i++ ){

            ris = ris * i;
        }
        printf ("\n Il risultato è %d \n", ris);

    } else {
        printf("\n Serve un numero maggiore di 0. \n");
    }
    
    }

    return 0;
}