#include <stdio.h>

#define NLETTERE 20

typedef struct  {
    char titolo[NLETTERE];
    char autore[NLETTERE];
    int anno;
} Libro;

void stampaLibro (Libro l){

    printf("\nTITOLO:%s\nAUTORE:%s\nANNO:%d\n", l.titolo, l.autore, l.anno);
}

void main (){

    Libro l;

    printf("\nInserisci il titolo: ");
    scanf(" %s", l.titolo);
    printf("\nInserisci l'autore: ");
    scanf(" %s", l.autore);
    printf("\nInserisci l'anno: ");
    scanf("%d", &l.anno);
    stampaLibro(l);
}