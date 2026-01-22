#include <stdio.h>
#include <string.h>

const int max = 21;

int fVocali (char frase[]){

    int cont = 0;

    //meglio usare frase[i]=tolower(frase[i]) con libreria #include <ctype.h>
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < max; j++){
            if (i==0){
                if (frase[j] == 'a' || frase[j] == 'A' ){
                    cont += 1;
                }
            }
            if (i==1){
                if (frase[j] == 'e' || frase[j] == 'E'){
                    cont += 1;
                }
            }
            if (i==2){
                if (frase[j] == 'i' || frase[j] == 'I'){
                    cont += 1;
                }
            }
            if (i==3){
                if (frase[j] == 'o' || frase[j] == 'O'){
                    cont += 1;
                }
            }
            if (i==4){
                if (frase[j] == 'u' || frase[j] == 'U'){
                    cont += 1;
                }
            }
                
        }
        }
        return cont;
}
    

int main () {

    char frase[max];
    int totV;
    printf("\nInserisci una frase (max 20 caratteri)");
    scanf("%s", frase);
    
    totV = fVocali(frase);

    printf("\nLe vocali totali sono %d", totV);

    return 0;
}