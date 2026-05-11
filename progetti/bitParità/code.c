//data una stringa di bit e un flag verificare errori

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool controllo(int nCaratteri, char codice[]) {

    int temp, somma = 0, cifraControllo;
    cifraControllo = (int)codice[nCaratteri - 1] - 48;

    for (int i = 0; i < nCaratteri; i++) {
        if (i != nCaratteri) {
            temp = (int)(codice[i] - 48);
            somma += temp;
        } 
    }

    return (somma % 2) == cifraControllo;
}

bool main (int argc, char *argv[]) {
    
    int nCaratteri = strlen(argv[1]);
    char codice[nCaratteri + 1];
    bool flag;

    strcpy(codice, argv[1]);

    if (*argv[2] == '0') {
        flag = controllo(nCaratteri, codice);
    } else if(*argv[2] == '1') {
        flag = !controllo(nCaratteri, codice);
    }

    printf("\nIl flag è: %d", flag);

    return flag;
}