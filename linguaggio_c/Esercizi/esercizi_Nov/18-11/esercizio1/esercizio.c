//Inserisci una serie di numeri tastiera fino a quando inserisco un numero negativo 
// dimmi se il numero è pari o dispari e calcolane il fattoriale

#include <stdio.h>

int main (){
    int n, ris = 1;

    printf ("\nInserisci dei numeri per sapere se sono pari o dispari e il suo fattoriale.\nInserisci un numero negativo per fermare il programma \n");
    scanf ("%d", &n);
    while (n <= 0){

        printf("Il primo numero deve essere un numero positivo\n");
        scanf ("%d", &n);
    }
    while (n > 0) {
        if (n==0){

            printf ("0 è un numero neutro\n");
        } else if (n%2==0) {

            printf ("%d è un numero pari\n", n);

        } else if (n%2==1) {

            printf("%d è un numero dispari\n", n);
        }

        for (int i = 1; i<=n; i++) {

            ris = ris * i;
        }
        
        printf("Il fattoriale di %d è %d \n", n, ris);
        ris = 1;
        printf ("Inserisci un nuovo numero\n");
        scanf ("%d", &n);

    }
    
    return 0;
}