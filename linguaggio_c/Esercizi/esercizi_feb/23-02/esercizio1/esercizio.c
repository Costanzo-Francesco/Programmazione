#include <stdio.h>
#include <string.h>

const int VALORI = 2;
const int MAXCARATTERI = 20;

void stampa(char nomiMacchine[nMacchine][], int macchine[VALORI][], int nMacchine){

    for (int i = 0; i < nMacchine; i++){
        
        for(int y = 0; y < MAXCARATTERI; y++){
            
        }

        for (int j = 0; j < VALORI; j++){
            printf("%d", macchine[i][j]);
        }
        printf("\n");
    }
}

int main () {

    int nMacchine;
    
    printf("\nQuante macchine vuoi inserire?\n");
    scanf("%d", &nMacchine);

    int macchine[VALORI][nMacchine];
    char nomiMacchine[nMacchine][MAXCARATTERI];

    for (int i = 0; i < nMacchine; i++){
        printf("\nInserisci la marca dell'autovettura:");
        scanf("%s", nomiMacchine[nMacchine][];)
            for (int j = 0; j < VALORI; j++){
                if (j == 0){
                    printf("\nInserisci la velocità massima della macchina numero:")
                    scanf("%d", &macchine[i][j]);
                } else if ( j == 1){
                    printf("\nInserisci il consumo della macchina:");
                    scanf("%d", &macchine[i][j]);
                }
                
            }
    }

    
    
    
    return 0;
}