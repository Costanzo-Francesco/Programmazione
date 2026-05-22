#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char ultimaCifra(){
    char cifra;
    printf("\nInserisci ultima cifra per controlla: ");
    scanf(" %c", &cifra);
    return cifra;
}

void stampaDati(partitaIva *s, int n, int scelta) {

    printf("\n---\tSTAMPA DATI\t---\n");
        char cifra;
        char stringa[BUFFER];
        for(int i = 0; i < n; i++){
            if (scelta == 1){
                cifra = ultimaCifra();
            }
            unisci(s, stringa,i);
            printf("\nNome azienda: %s\nCodice Iva: %s%c\n---\t---\t---\t---\n",s[i].nomeAzienda, stringa, s[i].ultimaCifra);
            if (scelta == 1){
                if ( cifra == s[i].ultimaCifra){
                printf("Cifra corretta: %c\n", cifra);

                }   else {
                    printf("Cifra errata: %c\n", cifra);
                }
            }
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
    int nInteri[MAXCIFRE - 1];
    int variabiliIntermedie[4];

    for(int i = 0; i < n; i++) {

        variabiliIntermedie[0] = 0;
        variabiliIntermedie[1] = 0;
        variabiliIntermedie[2] = 0;
        variabiliIntermedie[3] = 0;
        unisci(s, stringa,i);

        for(int j = 0; j < MAXCIFRE - 1; j++) {
            nInteri[j] = stringa[j] - 48;
        }
           
        for(int j = 0; j < MAXCIFRE - 1; j++) {
            if ((j + 1) % 2 == 1) {
                variabiliIntermedie[0] +=  nInteri[j]; //dispari
            } else {

                variabiliIntermedie[1] += nInteri[j] * 2;
                if ((nInteri[j]*2) >= 10 ){
                    variabiliIntermedie[1] -= 9;
                }
                if (nInteri[j] * 2 >= 5) {
                    variabiliIntermedie[2]++;
                }
            }
            
        }

        variabiliIntermedie[3] = (variabiliIntermedie[0] + variabiliIntermedie[1] + variabiliIntermedie[2]) % 10;
        s[i].ultimaCifra = ((10 - variabiliIntermedie[3]) % 10) + 48;
    }

}

int sceltaOperazione(){
    int operazione;
    printf("\nScegli operazione:\n1.\tControllo codice\n2.\tCalcolo ultima cifra\n3.\tEsci\nScelta: ");
    scanf("%d", &operazione);
    while(operazione > 3 || operazione < 1){
        printf("\nReinserisci: ");
        scanf("%d", &operazione);
    }
    return operazione;
}

void salvaFile(partitaIva *s, int n, int scelta) {

    FILE *fp = fopen("dati.txt", "a");
    fprintf(fp, "\n---\tDATI\t---\n");
    char cifra;
    char stringa[BUFFER];
        for(int i = 0; i < n; i++){
            if (scelta == 1){
                cifra = ultimaCifra();
            }
            unisci(s, stringa,i);
            fprintf(fp,"\nNome azienda: %s\nCodice Iva: %s%c\n---\t---\t---\t---\n",s[i].nomeAzienda, stringa, s[i].ultimaCifra);
            if (scelta == 1){
                if ( cifra == s[i].ultimaCifra){
                fprintf(fp,"Cifra corretta: %c\n", cifra);

                }   else {
                    fprintf(fp,"Cifra errata: %c\n", cifra);
                }
            }
        }
    fclose(fp);
    
}

int main() {

    printf("\n---\tAVVIO\t---\n");
    int nPartite = numeroPartiteIva();
    partitaIva *codiciIva = (partitaIva*) malloc(nPartite * sizeof(partitaIva));
    leggiDati(codiciIva, nPartite);

    int scelta = sceltaOperazione();
    if (scelta == 1) {
        calcolaControllo(codiciIva, nPartite);
        stampaDati(codiciIva, nPartite, scelta);
    } else if (scelta == 2) {
        calcolaControllo(codiciIva, nPartite);
        stampaDati(codiciIva, nPartite, scelta);
    } else if (scelta == 3) {
        printf("\n---\tUSCITA\t---\n");
    } else {
        printf("\n---\tERRORE USCITA FORZATA\t---\n");
        free(codiciIva);
        codiciIva = NULL;
        return 1;
    }
    
    salvaFile(codiciIva, nPartite, scelta);
    
    free(codiciIva);
    codiciIva = NULL;
    return 0;
    
}
