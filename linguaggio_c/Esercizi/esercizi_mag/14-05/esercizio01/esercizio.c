#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXCHAR 20

typedef struct {

    char nome[MAXCHAR];
    char cognome[MAXCHAR];
    int anni;
    float mediaVoti;
} Studente;

int numeroStudenti () {

    int nStudenti;
    printf("\nInserisci il numero di studenti: ");
    scanf("%d", &nStudenti);
    while (nStudenti < 0){
        printf("\nInserisci un numero adatto: ");
        scanf("%d", &nStudenti);
    }
    return nStudenti;
}

void inserisciDati(Studente *arr, int n){

    printf("\n---\tINSERIRE DATI\t---\n");

    for (int i = 0; i < n; i++){
        printf("\n--STUDENTE NUMERO %d", i + 1);
        printf("\nInserisci nome: ");
        scanf(" %s", arr[i].nome);
        arr[i].nome[0] = toupper(arr[i].nome[0]);
        printf("\nInserisci cognome: ");
        scanf(" %s", arr[i].cognome);
        arr[i].cognome[0] = toupper(arr[i].cognome[0]);
        printf("\nInserisci età: ");
        scanf("%d", &arr[i].anni);
        while(arr[i].anni < 0){
            printf("\nInserisci un'età adatta: ");
            scanf("%d", &arr[i].anni);
        }
        printf("\nInserisci la media:");
        scanf("%f", &arr[i].mediaVoti);
        while(arr[i].mediaVoti < 0 && arr[i].mediaVoti > 10){
            printf("\nInserisci una media adatta: ");
            scanf("%f", &arr[i].mediaVoti);
        }
        
        
    }
}

void stampaDati(Studente *arr, int n) {

    printf("\n---\tSTAMPA DATI\t---\n");

    for (int i = 0; i < n; i++) {
        
        printf("\nStudente: %s %s", arr[i].nome, arr[i].cognome);
        printf("\nAnni: %d\n", arr[i].anni);
        printf("\nMedia: %.2f\n---\t---\t---\t---\n",arr[i].mediaVoti);
    }
}

int mediaMigliore (Studente *arr, int n) {

    float migliorMedia;
    int numeroMigliore = 0;
    for(int i = 0; i < n; i++) {
        if (i == 0) {
            migliorMedia = arr[0].mediaVoti;
        }
        if (migliorMedia < arr[i].mediaVoti) {
            migliorMedia = arr[i].mediaVoti;
            numeroMigliore = i;
        }
        
    }

    return numeroMigliore;
}
int main () {

    printf("\n---\tAVVIO\t---\n");
    int nStudenti = numeroStudenti();

    Studente *arrStudenti = (Studente *) malloc(nStudenti * sizeof(Studente));
    if (arrStudenti == NULL) {
        printf("\n--\tMEMORIA INSUFFICIENTE\t---\n");
        return 1;
    }

    inserisciDati(arrStudenti, nStudenti);
    stampaDati(arrStudenti, nStudenti);

    int numeroMigliore = mediaMigliore(arrStudenti, nStudenti);

    printf("\nLo studente con la media migliore è %s %s con %.2f di media.\n", arrStudenti[numeroMigliore].nome, arrStudenti[numeroMigliore].cognome, arrStudenti[numeroMigliore].mediaVoti);

    free(arrStudenti);
    arrStudenti = NULL;
    printf("\n---\tCHIUSURA PROGRAMMA\t---\n");
    return 0;
}