//data una stringa di bit e un flag verificare errori

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pari(int nCaratteri, char codice[]){

    int temp, somma = 0, cifraControllo;
    cifraControllo = (int)codice[nCaratteri - 1] - 48;
    for (int i = 0; i < nCaratteri; i++){
        if (i != nCaratteri){
            temp = (int)(codice[i] - 48);
            
            somma += temp;
        } 
    }
    
    if (somma%2!=cifraControllo){
        printf("\nCORRETTO\n---\t---\nsomma: %d\nbit:%d\n", somma, cifraControllo);

    } else {
        printf("\nERRATO\n---\t---\nsomma: %d\nbit:%d\n", somma, cifraControllo);
    }

}

void dispari (int nCaratteri, char codice[]){

    int temp, somma = 0, cifraControllo;
    cifraControllo = (int)codice[nCaratteri - 1] - 48;

    for (int i = 0; i < nCaratteri; i++){
        if (i != nCaratteri){
            temp = (int)(codice[i] - 48);
            
            somma += temp;
        } 
    }
    
    if (somma%2!=cifraControllo){
        printf("\nCORRETTO\n---\t---\nsomma: %d\nbit:%d\n", somma, cifraControllo);

    } else {
        printf("\nERRATO\n---\t---\nsomma: %d\nbit:%d\n", somma, cifraControllo);
    }
}

int main (int argc, char *argv[]){
    
    int nCaratteri = strlen(argv[1]);
    int scelta;
    char codice[nCaratteri + 1];
    strcpy(codice, argv[1]);
    
    printf("\nCome desideri procedere:\n1. Controllo parità\n2. Controllo disparità\n");
    scanf("%d", &scelta);
    while(scelta != 2 && scelta != 1){
        printf("\nReinserisci scelta (numeri):\n1. Controllo parità\n2. Controllo disparità\n");
        scanf("%d", &scelta);
    }
    
    if (scelta == 1){
        pari(nCaratteri, codice);
    } else if(scelta == 2){
        dispari(nCaratteri, codice);
    }
}