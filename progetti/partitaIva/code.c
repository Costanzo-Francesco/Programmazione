#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreriaPartitaIva.h"

#define BUFFER 32
const int MAXCIFRE = 11;
typedef struct {

    char nomeAzienda[BUFFER];
    char numeroMatricola[BUFFER];
    char numeroUfficio[BUFFER];
    char ultimaCifra;

} partitaIva;


void unisci (partitaIva *s, char *stringa, int n) {

    
    strcpy(stringa, s[n].numeroMatricola);
    strcat(stringa, s[n].numeroUfficio);
    
}

int numeroPartiteIva() {

    int n;
    printf("Inserisci il numero di partite Iva che desideri inserire: ");
    scanf("%d", &n);
    return n;

}

void stampaDati(partitaIva *s, int n) {

    printf("\n---\tSTAMPA DATI\t---\n");
    char stringa[BUFFER];
    for(int i = 0; i < n; i++){
        unisci(s, stringa,i);
        printf("\nNome azienda: %s\nCodice Iva: %s%c\n---\t---\t---\t---\n",s[i].nomeAzienda, stringa, s[i].ultimaCifra);
    }
}

void leggiDati(partitaIva *s, int n) {

    printf("\n---\tINSERIMENTO DATI\t---\n");

    for(int i = 0; i < n; i++) {

        printf("\n--\tInserimento dati di azienda numero %d\nInserisci nome dell'azienda: ", i + 1);
        scanf(" %s", s[i].nomeAzienda);
        printf("\nOra inserisci il numero di matricola: ");
        scanf(" %s", s[i].numeroMatricola);

        while (strlen(s[i].numeroMatricola) != 7) {
            printf("\nIl numero di matricola deve essere di 7 caratteri esatti, reinserisci: ");
            scanf(" %s", s[i].numeroMatricola);
        }

        printf("\nOra inserisci il codice dell'ufficio provinciale: ");
        scanf(" %s", s[i].numeroUfficio);

        while (strlen(s[i].numeroUfficio) != 3) {
            printf("\nIl codice dell'ufficio provinciale deve essere di 3 caratteri esatti, reinserisci: ");
            scanf(" %s", s[i].numeroUfficio);
        }
        
    }

}

void calcolaControllo(partitaIva *s, int n) {

    char stringa[BUFFER];
    int nInteri[MAXCIFRE];
    int variabiliIntermedie[4];

    for(int i = 0; i < n; i++) {

        variabiliIntermedie[0] = 0;
        variabiliIntermedie[1] = 0;
        variabiliIntermedie[2] = 0;
        variabiliIntermedie[3] = 0;
        unisci(s, stringa,i);

        for(int j = 0; j < MAXCIFRE; j++) {
            nInteri[j] = stringa[j] - '0';
        }
           
        for(int j = 0; j < MAXCIFRE; j++) {
            if (j % 2 == 1) {
                variabiliIntermedie[0] +=  nInteri[j];
                if (nInteri[j] >= 3){
                    variabiliIntermedie[3]++;
                }
            } else {
                if(nInteri[j] * 2 >= 10){
                    variabiliIntermedie[1] += nInteri[j] - 9;
                } else {
                    variabiliIntermedie[1] +=  nInteri[j] * 2;
                }
            }
            
        }
        
        variabiliIntermedie[3] = (variabiliIntermedie[0] + variabiliIntermedie[1] + variabiliIntermedie[2]) % 10;
        s[i].ultimaCifra = ((10 - variabiliIntermedie[3]) % 10) + '0';
    }

}

int main() {

    printf("\n---\tAVVIO\t---\n");
    int nPartite = numeroPartiteIva();
    partitaIva *codiciIva = (partitaIva*) malloc(nPartite * sizeof(partitaIva));
    leggiDati(codiciIva, nPartite);
    calcolaControllo(codiciIva, nPartite);
    stampaDati(codiciIva, nPartite);
    free(codiciIva);
    codiciIva = NULL;
    printf("\n---\tUSCITA\t---\n");
    
    return 0;
}