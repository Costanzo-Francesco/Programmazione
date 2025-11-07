// età peso altezza e iniziale del nomme


#include <stdio.h>

int main () {

    int età;
    float peso, altezza;
    char nome;


    printf("\nInserisci i dati richiesti su di te:\n la tua età\n");
    scanf ("%d", & età);
    printf ("Ora inserisci il tuo peso\n");
    scanf ("%f", & peso);
    printf("Ora la tua altezza\n");
    scanf("%f", & altezza);
    printf ("Qual'è l'iniziale del tuo nome?\n");
    scanf(" %c", & nome);
    printf ("Hai %d anni, pesi %f, sei alto %f e la tua iniziale è %c", età, peso, altezza, nome);

    return 0;
}