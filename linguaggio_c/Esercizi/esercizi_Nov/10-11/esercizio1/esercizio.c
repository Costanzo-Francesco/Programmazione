// le variabili si indicano con const int "nome variabile" = n;
// oppure #define "nome variabile" n.
//COSTANTI IN MAIUSCOLO PRIMA DI MAIN 


//somma numeri positivi inseriti fino a 5. se negativo stop. somma maggiore uguale o minore di 100?

#include <stdio.h>

const int SOGLIA = 100;

int main (){

    int cont = 0;
    int n, som = 0;

    printf("\n Inserisci 5 numeri per ottenere la loro somma. Se inserisci un numero negativo allora calcolo prima della fine \n");

        while (cont<5) {

//manca if (n < 0) non calcolare nella somma
            
            scanf ("%d", &n);

        if (n >= 0) {

            som = som + n;
            cont = cont + 1;
            
        } else {

            cont = 100;

            }
        }

    printf("\n La somma è %d", som);
    
    if (som>SOGLIA)  {

        printf ("\n %d è maggiore di %d \n", som, SOGLIA);

    } else if (som < SOGLIA) {

        printf ( "\n %d è minore di %d \n", som, SOGLIA);
    }
    
    return 0;
}