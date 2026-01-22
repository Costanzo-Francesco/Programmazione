#include <stdio.h>

//funzione di riempimento
void fRiempimento(int numeri[], int n){
    for (int i = 0; i < n; i++){
        printf("\nInserisci il %d° numero:", i + 1);
        scanf("%d", &numeri[i]);

    }
}

//funzione di somma
int fSomma (int numeri[], int n){
    int somma;
    for (int i = 0; i < n; i++){
        somma += numeri[i];
    }

    return somma;
}

//funzione per individuare il massimo
int fMassimo (int numeri[], int n){
    int max = numeri[0];

    for (int i = 0; i < n; i++){
        if (max < numeri[i]){
            max = numeri[i];
        }
    }
    return max;
}


//Main
int main (){

    int n;
    int somma;
    int max;

    printf("\nQuanti numeri vuoi inserire?");
    scanf("%d", &n);

    int numeri[n];

    //riempimento array:
    fRiempimento(numeri, n);

    somma = fSomma(numeri, n);

    max = fMassimo(numeri, n);
    
    printf("\nIl massimo è %d.\nInvece la somma è %d.", max, somma);
    return 0;
}
