#include <stdio.h>
#include <string.h>
#include <ctype.h>


const int BUFFER = 30;

typedef struct {

    char sezioneNazione[3];     //2 + terminatore
    char sezioneDitta[6];       //5 + terminatore
    char sezioneArticolo[6];    //6 + terminatore
    char checkDigit;

} prodotto;

void maiuscole(char stringa[]){

    int nLettere = strlen(stringa);

    for (int i = 0; i < nLettere; i++){
        stringa[i] = toupper(stringa[i]);
    }
}

int numeroProdotti () {

    int nProdotti;
    printf("\nNumero prodotti: ");
    scanf("%d", &nProdotti);
    return nProdotti;
}

void provenienza (prodotto arrProdotti[], int n){

    char paese[BUFFER];
    char *tokenNumero;
    char *tokenPaese;
    char stringa[BUFFER];
    FILE *fp = fopen("nazioni.txt", "r");
    if (fp == NULL){
        printf("\nFile non trovato\n---\tUSCITA\t---\n");
    }

    printf("\nInserisci il paese di provenienza del prodotto: ");
    scanf(" %s", paese);
    
    maiuscole(paese); //riga 17

    while(fgets(stringa, BUFFER, fp) != NULL){

        tokenNumero = strtok(stringa, ",");
        tokenPaese  = strtok(NULL, ",");
        if(strcmp(tokenPaese, paese) == 0){
            strcpy(arrProdotti[n].sezioneNazione, tokenNumero);
            break;
        }
    }
    fclose(fp);
}

void codiceDitta (prodotto arrProdotti[], int n){

    char nomeDitta[BUFFER];
    char *tokenNumero;
    char *tokenDitta;
    char stringa[BUFFER];
    FILE *fp = fopen("codiciDitte.txt", "r");
    if (fp == NULL){
        printf("\nFile non trovato\n---\tUSCITA\t---\n");
    }

    printf("\nInserisci il nome della ditta: ");
    scanf(" %s", nomeDitta);

    maiuscole(nomeDitta);

    while(fgets(stringa, BUFFER, fp) != NULL){

        tokenNumero = strtok(stringa, ",");
        tokenDitta  = strtok(NULL, ",");
        if(strcmp(tokenDitta, nomeDitta) == 0){
            strcpy(arrProdotti[n].sezioneDitta, tokenNumero);
            break;
        }
    }
    fclose(fp);
}

void codiceArticolo(prodotto arrProdotti[], int n){

    char nomeArticolo[BUFFER];
    char *tokenNumero;
    char *tokenArticolo;
    char stringa[BUFFER];
    FILE *fp = fopen("codiciArticoli.txt", "r");
    if (fp == NULL){
        printf("\nFile non trovato\n---\tUSCITA\t---\n");
    }

    printf("\nInserisci il nome dell'articolo: ");
    scanf(" %s", nomeArticolo);

    maiuscole(nomeArticolo);

    while(fgets(stringa, BUFFER, fp) != NULL){

        tokenNumero = strtok(stringa, ",");
        tokenArticolo  = strtok(NULL, ",");
        if(strcmp(tokenArticolo, nomeArticolo) == 0){
            strcpy(arrProdotti[n].sezioneArticolo, tokenNumero);
            break;
        }
    }
    fclose(fp);
}

void carattereControllo(prodotto arrProdotti[], int n){

    char codiceCompleto[13];

    // unisce le 12 cifre
    strcpy(codiceCompleto, arrProdotti[n].sezioneNazione);
    strcat(codiceCompleto, arrProdotti[n].sezioneDitta);
    strcat(codiceCompleto, arrProdotti[n].sezioneArticolo);

    int somma = 0;

    for(int i = 0; i < 12; i++){

        int cifra = codiceCompleto[i] - '0';

        // posizioni pari *3
        if((i + 1) % 2 == 0){
            somma += cifra * 3;
        }
        else{
            somma += cifra;
        }
    }

    int controllo = (10 - (somma % 10)) % 10;

    arrProdotti[n].checkDigit = controllo + '0';

    printf("\nCheck digit: %c\n", arrProdotti[n].checkDigit);

    printf("\nCODICE EAN COMPLETO: %s%s%s%c\n",
           arrProdotti[n].sezioneNazione,
           arrProdotti[n].sezioneDitta,
           arrProdotti[n].sezioneArticolo,
           arrProdotti[n].checkDigit);
}

int main () {

    printf("\n---\tAVVIO\t---\n");
    int nProdotti = numeroProdotti();
    prodotto arrProdotti[nProdotti];

    for (int i = 0; i < nProdotti; i++){
        printf("\n---\tPRODOTTO %d\t---\n", i + 1);
        provenienza(arrProdotti, i);
        codiceDitta(arrProdotti, i);
        codiceArticolo(arrProdotti, i);
        carattereControllo(arrProdotti, i);
    }

    printf("\n---\tUSCITA...\t---\n");
    return 0;
}