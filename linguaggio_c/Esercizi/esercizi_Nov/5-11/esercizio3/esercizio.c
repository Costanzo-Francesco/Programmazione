//inserisci 3 valori da tastiera ed indica il maggiore e il minore

#include <stdio.h>

int main(){

    int i, n, mag, min;

    printf("\nInserisci 3 numeri per saperne il maggiore e il minore\n");

    scanf("%d", &n);
    mag=n;
    min=n;
    for (i = 0; i < 2; i++) {


        scanf("%d", &n);
     if (n>mag) {

        mag=n; 
        
      } else if (n<min) {

            min=n;

        } else {}


    }
        printf("Il maggiore è %d il minore è %d", mag, min);

        return 0;
}
