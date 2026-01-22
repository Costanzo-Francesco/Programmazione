/*
Esercizio 7 – Diagonale matrice quadrata
Scrivere un programma che:
1. Legga una matrice quadrata di dimensioni N x N.
2. Calcoli la somma degli elementi sulla diagonale principale e sulla diagonale secondaria.
3. Confronti le due somme e stampi quale delle due è maggiore o se sono uguali.
*/

#include <stdio.h>

int main () {

    int n;
    int somma1 = 0;
    int somma2 = 0;

    //creazionematrice

    printf("Inserisci la grandezza della tua matrice (è quadrata N x N)\n");
    scanf("%d", &n);

    int mat[n][n];
    printf("\nTabella creata: %d x %d", n, n);

    //riempimento matrice

    printf("\nOra inserisci gli elementi della tua tabella");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("\nInserisci il valore alla riga %d e colonna %d:\n", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    //printf matrice

    printf("\nMatrice riempita con successo!\n");
    for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                printf("%d\t", mat[i][j]);
            }
            printf("\n");
        }

    printf("\nCalcolo delle diagonali in corso...");

    //calcolo diagonale 1

    for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j) {somma1 += mat[i][j];}
            }

        }

    //calcolo diagonale 2

    for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (j + i == n-1) {somma2 += mat[i][j];}
            }

        }
    
    printf ("\nLa somma della prima diagonale è: %d.\nLa somma della seconda diagonale è: %d.\n", somma1, somma2);

    return 0;
}