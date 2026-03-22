#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int MAXCARATTERI = 30;    
const int LUNGHEZZACODICEFISCALE = 17;
const int ANNOATTUALE = 2026;
const int TOTGIORNIPERMESI[] = {31, 28, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int DIVISORECARATTERECONTROLLO = 26;
const int NUMEROPERASCII = 65;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void funzioneCognome (char *ptrToCodiceFiscale){
    
    int cont = 0;
    
    char cognome[MAXCARATTERI];
    printf("\nInserisci il cognome:\t\t\t\t\t");
    scanf("%s", cognome);
    
    int nLettere = strlen(cognome);

    for (int i = 0; i < nLettere; i++){

        cognome[i] = tolower(cognome[i]);
    }

    if (nLettere <= 3){ // meno di 3

        strcpy(ptrToCodiceFiscale, cognome);
        
        if (cognome[1] == '\0'){
            *(ptrToCodiceFiscale + 1) = 'X';
        }
        if (cognome[2]  == '\0'){
            *(ptrToCodiceFiscale + 2) = 'X';
        }   
    }
    
    if (nLettere > 3){ // più di 3

        
        for (int i = 0; i < nLettere; i++){
            
            if (cognome[i] != 'a' && cognome[i] != 'e' && cognome[i] != 'i' && cognome[i] != 'o' && cognome[i] != 'u'){
                
                ptrToCodiceFiscale[cont] = cognome[i];
                cont += 1;

            }

            if (cont == 3){
                break;
            }

        }

    }

    
    
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void funzioneNome (char *ptrToCodiceFiscale){

    int cont = 0;
    int flag = 0;
    int consonanti = 0;

    char nome[MAXCARATTERI];
    printf("\nInserisci il nome:\t\t\t\t\t");   //prendi nome
    scanf("%s", nome);

    int nLettere = strlen(nome);

    for (int i = 0; i < nLettere; i++){

        nome[i] = tolower(nome[i]);
    }
    //calcolo consonanti
    for (int i = 0; i < nLettere; i++){
        if (nome[i] != 'a' && nome[i] != 'e' && nome[i] != 'i' && nome[i] != 'o' && nome[i] != 'u'){
            consonanti++;
        }
    }

    if (consonanti > 3){

   
        for (int i = 0; i < nLettere; i++){
                

                if (nome[i] != 'a' && nome[i] != 'e' && nome[i] != 'i' && nome[i] != 'o' && nome[i] != 'u'){

                    ptrToCodiceFiscale[cont + 3 - flag] = nome[i];

                    if (cont == 1){
                        flag = 1;
                    }
                    cont += 1;
                }

                if (cont == 4){
                    break;
                }
        }
    }

    if (consonanti == 3){

        for (int i = 0; i < nLettere; i++){

            if (nome[i] != 'a' && nome[i] != 'e' && nome[i] != 'i' && nome[i] != 'o' && nome[i] != 'u'){

                ptrToCodiceFiscale[cont + 3] = nome[i];
                cont += 1;
                

            }

            if (cont == 3){
                break;
            }

        }
    }

    if (consonanti < 3) {

        // Inserisci prima le consonanti
        for (int i = 0; i < nLettere; i++){
            if (nome[i] != 'a' && nome[i] != 'e' && nome[i] != 'i' && nome[i] != 'o' && nome[i] != 'u'){
                ptrToCodiceFiscale[cont + 3] = nome[i];
                cont++;
            }
        }

        // Poi aggiungi le vocali se servono
        for (int i = 0; i < nLettere && cont < 3; i++){
            if (nome[i] == 'a' || nome[i] == 'e' || nome[i] == 'i' || nome[i] == 'o' || nome[i] == 'u'){
                ptrToCodiceFiscale[cont + 3] = nome[i];
                cont++;
            }
        }

        // Se ancora non hai 3 caratteri, riempi con 'X'
        while (cont < 3){
            ptrToCodiceFiscale[cont + 3] = 'X';
            cont++;
        }
    }

}   

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void funzioneAnnoGenere(char *ptrToCodiceFiscale){

    int anno;
    char sAnno[MAXCARATTERI];
    int mese;
    int giorno;
    char sesso;
    char sGiorno[2];
    
    printf("\nInserisci il tuo anno di nascita:\t\t\t");
    scanf("%s", sAnno);
    //"trasformazione" da string in int per controlli
    anno = atoi(sAnno);

    while(anno > ANNOATTUALE || anno < 1800){
        printf("\nInserisci nuovamente il tuo anno di nascita\n(Anni maggiore di %d e minori di 0 non validi):\t", ANNOATTUALE);
        scanf("%s", sAnno);
        anno = atoi(sAnno);
    }
    ptrToCodiceFiscale[6] = sAnno[2];
    ptrToCodiceFiscale[7] = sAnno[3];
    


    printf("\nInserisci il mese di nascita (numero):\t\t\t");
    scanf("%d", &mese);
    while (mese > 12 || mese < 1){
        printf("\nReinserisci il mese di nascita, deve essere un numero compreso da 1 (Gennaio) a 12 (Dicembre):\t");
        scanf("%d", &mese);
    }
    printf("\nInserisci il giorno di nascita (numero):\t\t");
    scanf("%s", sGiorno);
    giorno = atoi(sGiorno);

    //giorni divisi per mesi
    //Gennaio
    if (mese == 1){
        while(giorno > TOTGIORNIPERMESI[0] || giorno < 1){
            printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[0]);
            scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
        }
        ptrToCodiceFiscale[8] = 'A';

    //Febbraio
    } else if (mese == 2){

        if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)){
            
            while (giorno > TOTGIORNIPERMESI[2] || giorno < 1){
                printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[2]);
                scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
            }
        } else {
            
            while (giorno > TOTGIORNIPERMESI[1] || giorno < 1){
                printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[1]);
                scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
            }
        }
        ptrToCodiceFiscale[8] = 'B';
    }
    //Marzo
    else if (mese == 3){
        while(giorno > TOTGIORNIPERMESI[3] || giorno < 1){
            printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[3]);
            scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
        }
        ptrToCodiceFiscale[8] = 'C';
    }
    //Aprile
    else if (mese == 4){
        while(giorno > TOTGIORNIPERMESI[4] || giorno < 1){
            printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[4]);
            scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
        }
        ptrToCodiceFiscale[8] = 'D';
    }
    //Maggio
    else if (mese == 5){
        while(giorno > TOTGIORNIPERMESI[5] || giorno < 1){
            printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[5]);
            scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
        }
        ptrToCodiceFiscale[8] = 'E';
    }
    //Giugno
    else if (mese == 6){
        while(giorno > TOTGIORNIPERMESI[6] || giorno < 1){
            printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[6]);
            scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
        }
        ptrToCodiceFiscale[8] = 'H';
    }
    //Luglio
    else if (mese == 7){
        while(giorno > TOTGIORNIPERMESI[7] || giorno < 1){
            printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[7]);
            scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
        }
        ptrToCodiceFiscale[8] = 'L';
    }
    //Agosto
    else if (mese == 8){
        while(giorno > TOTGIORNIPERMESI[8] || giorno < 1){
            printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[8]);
            scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
        }
        ptrToCodiceFiscale[8] = 'M';
    }
    //Settembre
    else if (mese == 9){
        while(giorno > TOTGIORNIPERMESI[9] || giorno < 1){
            printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[9]);
            scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
        }
        ptrToCodiceFiscale[8] = 'P';
    }
    //Ottobre
    else if (mese == 10){
        while(giorno > TOTGIORNIPERMESI[10] || giorno < 1){
            printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[10]);
            scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
        }
        ptrToCodiceFiscale[8] = 'R';
    }
    //Novembre
    else if (mese == 11){
        while(giorno > TOTGIORNIPERMESI[11] || giorno < 1){
            printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[11]);
            scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
        }
        ptrToCodiceFiscale[8] = 'S';
    }
    //Dicembre
    else if (mese == 12 || giorno < 1){
        while(giorno > TOTGIORNIPERMESI[12]){
            printf("Reinserisci il giorno di nascita, deve essere minore di %d:\t", TOTGIORNIPERMESI[12]);
            scanf("%s", sGiorno);
            giorno = atoi(sGiorno);
        }
        ptrToCodiceFiscale[8] = 'T';
    }

    if (giorno < 10){
        
        ptrToCodiceFiscale[9] = '0';
        ptrToCodiceFiscale[10] = sGiorno[0];
    }

    //controllo per il Sesso

    printf("\nInserisci il sesso: M per maschio o F per femmina:\t");
    scanf(" %c", &sesso);
    sesso = tolower(sesso);
    while (sesso != 'm' && sesso != 'f'){
        printf("\nReinserisci il sesso: M per maschio o F per femmina:\t");
        scanf("%c", &sesso);
    }

    if (sesso == 'f'){
        giorno += 40;
    }

    // sprintf(stringa, tipo variabile da trasformare, intero)
    sprintf(sGiorno, "%d", giorno);
    
    if (giorno < 10){
        
        ptrToCodiceFiscale[9] = '0';
        ptrToCodiceFiscale[10] = sGiorno[0];
    } else {
        strcpy(&ptrToCodiceFiscale[9],sGiorno);
    }

}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void funzioneCodiceCatastale ( char *ptrToCodiceFiscale) {

    char stringa[MAXCARATTERI];
    char comune[MAXCARATTERI];
    char provincia[MAXCARATTERI];
    
    //apro file in lettura
    FILE *fp = fopen("CodiciCatastali.txt", "r");

    //controllo per esistenza file
    if (fp == NULL){
        printf("\nIl file non esiste o non è presente.\n");
        return;

    } else {
        
        //raccolta dati e tutti in maiuscolo
        printf("\nComune di nascita:\t\t\t\t\t");
        scanf("%s", comune);
        
        for(int i = 0; comune[i] != '\0'; i++){comune[i] = toupper(comune[i]);}
        
        printf("\nSigla provincia:\t\t\t\t\t");
        scanf("%s", provincia);
        
        for(int i = 0; provincia[i] != '\0'; i++){provincia[i] = toupper(provincia[i]);}

        //Effettiva lettura file e controllo riga per riga
        while(fgets(stringa, MAXCARATTERI, fp)) {

            //spezzettatura riga con strtok
            char *codice = strtok(stringa, ",");
            char *prov = strtok(NULL, ","); //riprende da \0 fino a ",""
            char *com = strtok(NULL, ",");

            // se uno dei tre è NULL, salta la riga
            if (codice == NULL || prov == NULL || com == NULL) continue;

            //controllo e copia
            if (strcmp(prov, provincia) == 0 && strcmp(com, comune) == 0){
                
                strcpy(&ptrToCodiceFiscale[11], codice);

            } 
            
        }
        
    }
    //chiudo file
    fclose(fp);
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void funzioneMaiuscolo ( char *ptrToCodiceFiscale) {

    for (int i = 0; i < LUNGHEZZACODICEFISCALE; i++){
        if (*(ptrToCodiceFiscale + i) != '0' && *(ptrToCodiceFiscale + i) != '1' && *(ptrToCodiceFiscale + i) != '2' && *(ptrToCodiceFiscale + i) != '3' && *(ptrToCodiceFiscale + i) != '4' && *(ptrToCodiceFiscale + i) != '5' && *(ptrToCodiceFiscale + i) != '6' && *(ptrToCodiceFiscale + i) != '7' && *(ptrToCodiceFiscale + i) != '8' && *(ptrToCodiceFiscale + i) != '9')
        *(ptrToCodiceFiscale + i) = toupper(*(ptrToCodiceFiscale + i));
    }
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void funzioneCarattereControllo ( char *ptrToCodiceFiscale){

    char stringaValori[MAXCARATTERI];
    int cont = 0;
    int ris1, ris2, risFinale,numeroAscii;

    //apro file in lettura
    FILE *fp = fopen("CarattereControllo.txt", "r");

    //controllo esistenza
    if (fp == NULL){
        printf("File non trovato o inesistente.\n");
        return;
    } else {

        //lettura e controllo, e incremento contatore
        while(fgets(stringaValori, MAXCARATTERI, fp)){

            char *carattere = strtok(stringaValori, ",");
            char *dispari   = strtok(NULL, ",");
            char *pari      = strtok(NULL, ",");

            for (int i = 0; ptrToCodiceFiscale[i] != '\0'; i++){
                
                if (i == 0){
                    if (ptrToCodiceFiscale[i] == *carattere){
                        cont += atoi(dispari);
                    }

                } else if (i % 2 == 1){
                    if (ptrToCodiceFiscale[i] == *carattere){
                        cont += atoi(pari);
                    }

                } else if (i % 2 == 0){
                    if (ptrToCodiceFiscale[i] == *carattere){
                        cont += atoi(dispari);
                    }
                }

            }

        }

        //calcoli per il numero da ottenere
        ris1      = cont / DIVISORECARATTERECONTROLLO;
        ris2      = DIVISORECARATTERECONTROLLO * ris1;
        risFinale = cont - ris2;

        //trasformazione da intero in valore ascii (cominciano da 65 e finiscono a 90)
        numeroAscii = NUMEROPERASCII + risFinale;
        ptrToCodiceFiscale[15] = (char)numeroAscii;
    }
    fclose(fp);
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main () {

    char codiceFiscale[LUNGHEZZACODICEFISCALE];
    int scelta;

    printf("\n\n---\tCalcolatore Di Codice Fiscale\t---\n\n");
    printf("Seleziona un operazione da svolgere:\n1. Calcolare Codice Fiscale.\n2. Esci.\n\nScelta:\t");
    scanf("%d", &scelta);
    while (scelta < 1 || scelta > 2){
        printf("\n\nSeleziona un operazione VALIDA da svolgere:\n1. Calcolare Codice Fiscale.\n2. Esci.\n\nScelta:\t");
        scanf("%d", &scelta);
    }
    
    switch (scelta) {
        case 1:
            printf("\n\n---\tIniziamo\t---\n\n");
            funzioneCognome(codiceFiscale);
            funzioneNome(codiceFiscale);
            funzioneAnnoGenere(codiceFiscale);
            funzioneCodiceCatastale(codiceFiscale);
            funzioneMaiuscolo(codiceFiscale);
            funzioneCarattereControllo(codiceFiscale);
            printf("\n\n---\tEcco il tuo codice fiscale!\t---\n\n########################\n### %s ###\n########################\n", codiceFiscale); 
            break;
        case 2:

            printf("\n\n---\tUscita dal programma\t---\n\n");

            break;
        
        }

    return 0;    
}
