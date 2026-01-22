/*
Esercizio 6 – Conteggio stringhe con lunghezza > k
Scrivere un programma che:
1. Legga N stringhe e un valore intero k.
2. Conti quante, tra le stringhe inserite, hanno una lunghezza strettamente superiore a k.
3. Stampi il conteggio finale.
*/

#include <stdio.h>
#include <string.h>
const int massimoCaratteri = 30;

int main () {

    int k, n;
    int cont = 0;

    printf("\nPiù di quanto devono essere lunghe le scritte? (max 30 caratteri)\n");
    scanf("%d", &k);
    while (k > massimoCaratteri){
        printf("\nMassimo 30 caratteri, reinserire lunghezza:\n");
        scanf("%d", &k);
    }

    printf("\nQuante parole vuoi inserire?\n");
    scanf("%d", &n);

    char parole[n][massimoCaratteri];   //matrice contenente stringhe
    int  lunghezzaStringa[n];           //matrice con lunghezza stringhe

    printf("\nOra inserisci le parole:");
    for (int i = 0; i < n; i++){
        printf("\nInserisci la parola della riga %d:\n", i + 1);
        scanf("%s", parole[i]);
        lunghezzaStringa[i] = strlen(parole[i]);
    }
    

    for (int i = 0; i < n; i++){
        if (lunghezzaStringa[i] > k) {
            cont += 1;
        }

    }
    printf("\nLe stringhe strettamente maggiori di %d caratteri sono: %d \n", k, cont);
    
    return 0;
}