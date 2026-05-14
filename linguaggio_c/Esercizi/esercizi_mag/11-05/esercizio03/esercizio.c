/*
Si scriva un programma C che legga due serie di dati e li memorizzi in due vettori di strutture.
Nel primo vettore M (di dimensione 3) vengono memorizzati dati del tipo: <matricola, nome, cognome>.
Si noti che la matricola identifica univocamente uno studente e che non ci sono due strutture che contengono lo stesso numero di matricola.
Nel secondo vettore V (di dimensione 7) vengono memorizzati dati del tipo: <matricola, esame, voto>.
Possono esserci più record con lo stesso numero di matricola che denotano diversi esami fatti dallo stesso studente.
Si scriva un programma che tramite opportune procedure legga i dati in ingresso e li inserisca nei due vettori.
Successivamente per ogni studente con matricola X contenuto nel vettore M sommi tutti i suoi voti ottenuti negli esami contenuti nel vettore V.
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 20
const int numeroStudenti = 3;

typedef struct {
    int matricola;
    char nome[BUFFER];
    char cognome[BUFFER];
} studente;

typedef struct {
    int matricola;
    char esame[BUFFER];
    float voto;
} esame;

int main () {

    studente M[numeroStudenti];
    esame V[numeroStudenti][7];
    printf("\n---\tInserimento dati studenti\t---\n");
    for (int i = 0; i < numeroStudenti; i++){

        printf("\nSTUDENTE NUMERO %d", i + 1);
        M->matricola = i;
        printf("\nInserisci il nome dello studente: ");
        scanf(" %s", M->nome);
        printf("\nInserisci il cognome dello studente: ");
        scanf(" %s", M->cognome);
    }



    return 0;
}