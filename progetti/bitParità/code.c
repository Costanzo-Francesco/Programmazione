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

    if ((somma % 2) == cifraControllo) {
        printf("\nCORRETTO\n");
    } else {
        printf("\nERRATO\n");
    }

    printf("---\t---\nsomma: %d\nbit: %d\n", somma, cifraControllo);

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
    // parità dispari
    if ((somma % 2) != cifraControllo) {
        printf("\nCORRETTO\n");
    } else {
        printf("\nERRATO\n");
    }

    printf("---\t---\nsomma: %d\nbit: %d\n", somma, cifraControllo);
}

int main (int argc, char *argv[]){
    
    int nCaratteri = strlen(argv[1]);
    char codice[nCaratteri + 1];
    strcpy(codice, argv[1]);
    if (*argv[2] == '0'){
        pari(nCaratteri, codice);
    } else if(*argv[2] == '1'){
        dispari(nCaratteri, codice);
    }
}