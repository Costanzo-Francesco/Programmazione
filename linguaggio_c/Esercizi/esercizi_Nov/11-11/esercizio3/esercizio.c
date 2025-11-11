// L'untente inserisce un anno. verifica se bisestile

#include <stdio.h>

int main () {
    
    int anno;
    
    printf("\n Inserisci un anno per verificare se è bisestile, inserisci 0 per terminare il programma \n");

scanf("%d", & anno);

    if ((anno%4 == 0 && anno%100 != 0) || anno%400 == 0) {

        printf ("\n Anno bisestile \n");

    } else {

        printf ("\n Anno non bisestile \n");

    }
    
    while (anno!= 0) {


    scanf("%d", & anno);

    if ((anno%4 == 0 && anno%100 != 0) || anno%400 == 0) {

        printf ("\n Anno bisestile \n");

    } else {

        printf ("\n Anno non bisestile \n");

    }



    }
}