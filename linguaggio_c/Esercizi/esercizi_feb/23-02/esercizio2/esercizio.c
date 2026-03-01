#include <stdio.h>


/*Funzione leggi Array per leggere e stampare array*/
void leggiArray(int arrayDati[], int totDati){  /*Passaggio dati (uguale per tutte le funzioni tranne che media)*/

    /*Raccolta dati*/
    for (int i = 0; i < totDati; i++){
        printf("\nInserisci il dato:");
        scanf("%d", &arrayDati[i]);
    }
    
    /*Stampa dati raccolti*/
    printf("\nEcco il tuo sondaggio con tutti i dati!\n");
    for (int i = 0; i < totDati; i++){
        printf("%d\t", arrayDati[i]);
    }
}

/*Funzione per il massimo*/
int massimo (int arrayDati[], int totDati){

        int max = arrayDati[0];

        /*Ciclo for e condizione per massimo*/
        for (int i = 0; i < totDati; i++){
            if ( max < arrayDati[i]){
                max = arrayDati[i];
            }
        }

        return max;
}

/*Funzione per il minimo*/
int minimo (int arrayDati[], int totDati){

        int min = arrayDati[0];
        /*Esattamente come per il massimo, ciclo for e poi condizioni*/
        for (int i = 0; i < totDati; i++){
            if ( min > arrayDati[i]){
                min = arrayDati[i];
            }
        }

        return min;
}

/*Funzione per conteggio numeri pari*/
int contaPari (int arrayDati[], int totDati){

    int pari = 0;

    /*Ciclo for per leggere array e incremento contatore*/

    for (int i = 0; i < totDati; i++){
            if (arrayDati[i] % 2 == 0){
                pari++;
            }
        }

        return pari;
}

/*Funzione per la somma dell'array*/
int sommaRicorsiva (int arrayDati[], int totDati){

    int somma = 0;
    /*Ciclo for per somma*/
    for (int i = 0; i < totDati; i++){

            somma += arrayDati[i];
        }

        return somma;
}

/*Funzione per media*/
float media (int somma, int totDati){   /*Passo direttamente somma al posto di rifare calcoli*/

    float sommaFloat;
    float totDatiFloat;

    sommaFloat = (float)somma;          /*Casting da int a float*/
    totDatiFloat = (float)totDati;      /*Casting da int a float*/
    
    return  sommaFloat/totDatiFloat;
    
}

/*Funzione Main*/

int main (){

    int totDati, max, min, pari, somma;
    float mediaValore;

    printf("\nQuanti dati vuoi inserire per il singolo sondaggio?");
    scanf("%d", &totDati);

    int arrayDati[totDati]; /*Dichiarazione array*/

    /*Assegnazione dei valori alle variabili*/

    leggiArray(arrayDati, totDati);
    max = massimo(arrayDati, totDati);
    min = minimo(arrayDati, totDati);
    pari = contaPari(arrayDati, totDati);
    somma = sommaRicorsiva(arrayDati, totDati);
    mediaValore = media(somma, totDati);

    /*Printf finale*/
    printf("\nIl valore massimo è: %d.\nIl valore minimo è: %d.\nIl numero di elementi pari è:%d.\nLa somma totale è %d.\nLa media è %0.2f.\n", max, min, pari, somma, mediaValore);

    return 0;
}