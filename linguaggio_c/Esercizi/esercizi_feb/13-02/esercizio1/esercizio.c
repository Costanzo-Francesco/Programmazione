#include <stdio.h>  //libreria standard
#include <time.h>   //libreria per time(NULL) 
#include <stdlib.h> //libreria per random

//costanti
const int N = 5;        //per misura array
const int MAX = 100;    //per MAX random
const int MIN = 1;      //per MIN random



/*---------------------------------------------------funzione array---------------------------------------------------------*/

int sommaArray (int valori[], int lunghezzaArray){

    int somma = 0;

    for (int i = 0; i < lunghezzaArray; i++){
        somma += valori[i];
    }
    
    return somma;
}
 
/*-------------------------------------------------funzione massimo----------------------------------------------------------*/

int numeroMassimo(int valori[], int lunghezzaArray){

    int max = valori[0];

    for (int i = 0; i < lunghezzaArray; i++){
        if (valori[i] > max){
            max = valori[i];
        }
    }
    
    return max;
}

/*------------------------------------------funzione conteggio numeri positivi-----------------------------------------------*/

int conteggioPositivi (int valori[], int lunghezzaArray){

    int nPositivi = 0;

    for (int i = 0; i < lunghezzaArray; i++){
        if (valori[i] > 0){
            nPositivi ++;
        }
    }
    
    return nPositivi;
}

/*------------------------------------------funzione per stampa array--------------------------------------------------------*/

void stampaNumeri(int valori[], int lunghezzaArray){

    printf("\nI numeri generati casualmente sono %d. E sono:\n", lunghezzaArray);
    for (int i = 0; i < lunghezzaArray; i++){
        printf("%d\t", valori[i]);

    }
}


/*----------------------------------------------------main------------------------------------------------------------------*/

int main (){

    int valori[N];
    int somma;
    int max;
    int nPositivi;
    int risposta;

    srand(time(NULL)); //avvio seed del generatore in base al tempo

    do{

        for (int i = 0; i < N; i++){
        valori[i] = (rand() % (MAX - MIN + 1)) + MIN;
        }

        int lunghezzaArray = sizeof(valori) / sizeof(valori[0]);

        //chiamo le funzioni    
        somma = sommaArray(valori, lunghezzaArray);             //assegno a somma
        max = numeroMassimo(valori, lunghezzaArray);            //assegno a max
        nPositivi = conteggioPositivi(valori, lunghezzaArray);  //assegno a nPositivi
        stampaNumeri(valori, lunghezzaArray);                   //stampa


        //scrittura risposte
        printf("\nLa somma è: %d.\nIl numero massimo è: %d.\nI numeri positivi sono: %d.", somma, max, nPositivi);
        printf("\nInserisci qualsiasi valore per ripetere l'operazione con valori diversi. Inserisci 0 per terminare\n");
        scanf("%d", &risposta);

    } while (risposta != 0);



    return 0;
}