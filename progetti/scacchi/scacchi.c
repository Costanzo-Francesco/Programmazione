#include <stdio.h>

const int MISURA = 17;
const char MURI = '|';
const char PAVIMENTI = '-';

//scrivi la scacchiera
void fScriviSchacchiera(char scacchiera[][MISURA]){
 
       for (int i = 0; i < MISURA; i++){
        for (int j = 0; j < MISURA; j ++){
            printf("%c ", scacchiera[i][j]);
        }
        printf("\n");
       }
}

//posizionamento pedine
void fPedine (char scacchiera[][MISURA]){
    
    char wPawn = 'P';
    char wTower = 'T';
    char wBishop = 'B';
    char wHorse = 'H';
    char wQueen = 'Q';
    char wKing = 'K';
    

   
    char bPawn = 'p';
    char bTower = 't';
    char bBishop = 'b';
    char bHorse = 'h';
    char bQueen = 'q';
    char bKing = 'k';
        
    

    //Pedoni
    for (int i = 0; i < MISURA; i++){
        for (int j = 0; j < MISURA; j ++){
            if (scacchiera[i][j] != MURI && scacchiera[i][j] != PAVIMENTI){
            scacchiera[3][j] = bPawn;
            scacchiera[13][j] = wPawn;
            }
        }
    }

    //Torri
    scacchiera[1][1] = bTower;
    scacchiera[1][15] = bTower;
    scacchiera[15][1] = wTower;
    scacchiera[15][15] = wTower;

    //Cavalli
    scacchiera[1][3] = bHorse;
    scacchiera[1][13] = bHorse;
    scacchiera[15][3] = wHorse;
    scacchiera[15][13] = wHorse;

    //Alfieri
    scacchiera[1][5] = bBishop;
    scacchiera[1][11] = bBishop;
    scacchiera[15][5] = wBishop;
    scacchiera[15][11] = wBishop;

    //Re e Regina
    scacchiera[1][7] = bKing;
    scacchiera[1][9] = bQueen;
    scacchiera[15][7] = wQueen;
    scacchiera[15][9] = wKing;

}

void fMossaBianchi(char scacchiera[][MISURA]){
    
    int r;
    int c;

    printf("\nMossa ai bianchi:\nInserisci la riga della pedina:");
    scanf("%d", &r);
        while (r<1 || r>8){
            printf("\nInserisci una riga opportuna: (1-8)");
            scanf("%d", &r);
        }
    printf("\nOra inserisci la colonna:");
    scanf("%d", &c);
        while (c<1 || c>8){
                printf("\nInserisci una colonna opportuna: (1-8)");
                scanf("%d", &c);
            }
    printf("La tua pedina è quella situata sulla casella:\nRiga:%d.\nColonna:%d.\n", r, c);

    r *= 2;
    c *= 2;
            

}

int main (){
    printf("\n");
    char scacchiera[MISURA][MISURA];

    //creazione scacchiera
    char bianco = ' ';
    for (int i = 0; i < MISURA; i++){
        for (int j = 0; j < MISURA; j++){

            if (j%2==0){
                scacchiera[i][j] = MURI;
            }
            if (scacchiera[i][j] != MURI && i%2==0){
                scacchiera[i][j] = PAVIMENTI;
            }
            if (scacchiera[i][j] != MURI && scacchiera[i][j] != PAVIMENTI){
                scacchiera[i][j] = bianco;
            }  
        }  
    }
    

    fPedine(scacchiera);
    fScriviSchacchiera(scacchiera);
    fMossaBianchi(scacchiera);

}
