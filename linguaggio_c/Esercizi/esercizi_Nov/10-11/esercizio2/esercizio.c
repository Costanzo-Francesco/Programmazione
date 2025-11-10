/* Inserire un numero compreso tra 1 - 12.
Di tale numero vializzare la tabellina sulla stessa riga
\t 1    2    3
*/


#include <stdio.h>

const int MIN = 1;
const int MAX = 12;
const int MAX_TAB = 10;

int main (){

    int n, i , ris;
    printf("\n Inserisci un numero compreso da %d a %d per visualizzarne la tabellina \n", MIN, MAX);
    scanf ("%d", &n);

    if (n < MAX && n > MIN) {

        for (i = 1; i <= MAX_TAB; i++) {

        ris = n * i;
        printf (" %d \t", ris );

        }
        
    } else {

    printf ("\n Serve un numero maggiore di %d e minore di %d \n", MIN, MAX);

    }   
    return 0;
}