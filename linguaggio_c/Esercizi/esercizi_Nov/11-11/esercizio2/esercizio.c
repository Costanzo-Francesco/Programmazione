//2 Leggi tre numeri e individua il minore e il maggiore. 

#include <stdio.h>

int main () {

    int num, max, min, cont = 0, i;
    printf ("\n Inserire 3 valori interi \n");

    scanf ("%d", & num);
    max = num;
    min = num;

    for (i = 0; i <=1; i++){

        scanf ("%d", & num);
        if ( max<num) {

            max = num;

        } else if (min>num) {

            min = num;
        } else if (max == num && min == max) {

            cont = cont + 1;
        }


    }


    if (cont == 2){

        printf (" \n Sono tutti uguali \n");

    } else if (cont<3){
        printf ("\n Il maggiore è %d. E il minore è %d ", max, min); 
    }

    return 0;
}