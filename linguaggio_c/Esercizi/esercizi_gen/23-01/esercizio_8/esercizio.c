/*
Scrivere un programma che:
1. Legga una matrice di dimensioni N x M.
2. Generi una seconda matrice di dimensioni M x N che sia la trasposta della prima (scambiando
righe con colonne).
3. Stampi la matrice trasposta risultante.
*/

#include <stdio.h>

int main () {

    int r, c;

    printf("\nInserisci valori matrice (righe e colonne).\nPrima le righe:");
    scanf("%d", &r);
    printf("\nOra le colonne:");
    scanf("%d", &c);

    int mat1[r][c];
    int mat2[c][r];

    //riempimento matrice

    printf("\nOra inserisci gli elementi della tua matrice");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("\nInserisci il valore alla riga %d e colonna %d:\n", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    //trasposizione

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
           mat2[j][i] = mat1[i][j];
        }
    }

    //scrittura matrici

    printf("\nMatrice originale\n");
    for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                printf("%d\t", mat1[i][j]);
            }
            printf("\n");
        }

    printf("\nMatrice trasposta\n");
    for (int i = 0; i < c; i++){
            for (int j = 0; j < r; j++){
                printf("%d\t", mat2[i][j]);
            }
            printf("\n");
        }

        return 0;
}