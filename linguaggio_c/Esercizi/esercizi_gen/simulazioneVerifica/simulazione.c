/*

*/

#include <stdio.h>
#include <string.h>

const int R = 3;
const int C = 5;

const char GIORNO[5][12] = {"Lunedì", "Martedì", "Mercoledì", "Giovedì", "Venerdì"};

const char PRODOTTO[3][12] = {"Prodotto 1", "Prodotto 2", "Prodotto 3"};

void fStampa(int tabVendite[R][C]){

    printf("\n\t\t");
    for (int j = 0; j < C; j++){

            printf("%s\t", GIORNO[j]);

        }


    for (int i = 0; i < C; i++){
        
        printf("\n%s\t", PRODOTTO[i]);

            for (int j = 0; j < R; j++){
                printf("%d\t", &tabVendite[i][j]);
            }
    }
}
int main(){

    int tabVendite[R][C];
    for (int i = 0; i < C; i++){
        for (int j = 0; j < R; j++){
            printf("\nQuante volte hai venduto il %s? Il %s", PRODOTTO[j], GIORNO[i]);
            scanf("%d", &tabVendite[j][i]);
        }
    }

    fStampa(tabVendite);
    

}