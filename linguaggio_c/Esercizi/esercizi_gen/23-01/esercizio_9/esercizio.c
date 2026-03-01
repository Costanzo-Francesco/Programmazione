/*
Esercizio 9 – "Cancellazione" di una stringa
Scrivere un programma che:
1. Legga N stringhe.
2. Chieda un indice all'utente e sovrascriva la stringa a quell'indice rendendola vuota (carattere \0 in
prima posizione).
3. Stampi tutte le stringhe dell'elenco, saltando quelle che risultano vuote.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int lunghezza = 10;
int main () {

    int numeroParole; // Numero Parole
    char scelta;
    int cont = 0;
    printf("\nQuante parole vuoi scrivere:\n");
    scanf("%d", &numeroParole);

    char parole[numeroParole][lunghezza];

    printf("\nInserisci le %d parole", numeroParole);

    for (int i = 0; i < numeroParole; i++){

        printf("\nInserisci la parola numero %d:", i + 1);
        scanf("%s", parole[i]);
    }

    //elenco

    printf("\nEcco il tuo elenco, con un indice a fianco");

    for (int i = 0; i < numeroParole; i++){

        printf("\n%d. %s", i + 1, parole[i]);
    }

    printf("\nVorresti eliminarne qualcuna? (s/n)");
    scanf(" %c", &scelta);

    while (scelta != 's' && scelta != 'S' && scelta != 'n' && scelta != 'N'){

        printf("\nPuoi solo rispondere con s per si oppure n per no.");
        scanf("%c", &scelta);
        
    }
    scelta = tolower(scelta);

    if (scelta == 's'){

        int numeroEliminazioni;
        int numeroEliminato;

        printf("\nQuante ne desideri eliminare?");
        scanf("%d", &numeroEliminazioni);
        printf("\nScrivi il numero di indice");
        for (int i = 0; i < numeroEliminazioni; i++){
            printf("\nInserisci l'indice:");
            scanf("%d", &numeroEliminato);
            numeroEliminato -= 1;
            parole[numeroEliminato][0] = '\0';
        }
    }

    
       printf("\nEcco il tuo elenco, con un indice a fianco");

    for (int i = 0; i < numeroParole; i++){
        if (parole[i][0] == '\0'){
            cont += 1;
        } else {

        printf("\n%d. %s", i + 1 - cont, parole[i]);

        }
    }
    printf("\n");

    

    return 0;
}