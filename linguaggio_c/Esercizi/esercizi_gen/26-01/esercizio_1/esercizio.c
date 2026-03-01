//crea matrice di dimensioni costanti e riempila con numeri random da 0 o 1;

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int R = 5;
const int C = 5;
const int MAX = 1;
const int MIN = 0;
const int MAXNAVI = 5;
const int TENTATIVI = 10;

void fStampa(int mat[R][C]){
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

int fBattaglie(){

    int r, c;
    int cont;
    for (int i = 0; i < TENTATIVI; i++){

        printf ("\n Inserisci la cordinata righe del tentativo %d", i + 1);
        scanf("%d", r);
        printf ("\n Inserisci la cordinata colonne del tentativo %d", i + 1);
        scanf("%d", c);

        if (mat[r][c] == 1){
            printf("\nColpito! ancora %d tentativi", 10 - i - 1);
            cont++;
        } else {
            printf("\nAcqua! ancora %d tentativi", 10 -i -1);
        }
    }

    


}


int main () {

    int mat[R][C];
    int cont = 0;
    srand(time(NULL));

    do{
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                mat[i][j] = MIN + rand() % (MAX - MIN + 1);
                if (mat[i][j] == 1){
                    cont += 1;
                    
                }
            }
        }
    }while(cont <= MAXNAVI);

    
    
    fStampa(mat);
    
    return 0;
}