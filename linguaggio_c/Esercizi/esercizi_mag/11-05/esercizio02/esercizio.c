#include <stdio.h>
#include <stdlib.h>

int main () {

    int nPrezzi;
    float somma = 0.0;
    printf("\nInserisci i prezzi: ");
    scanf("%d", &nPrezzi);

    float *prezzi = (float*)calloc(nPrezzi, sizeof(float));
    if (prezzi == NULL) {
        printf("\nMemoria insufficiente.");
        return 1;
    }

    for(int i = 0; i < nPrezzi; i++){

        printf("\nInserire prezzo prodotto %d: ", i + 1);
        scanf("%f", &prezzi[i]);
        somma += prezzi[i];
    }

    printf("\nLa somma è: %.2f", somma);
    for (int i = 0; i < nPrezzi; i++){

    }
    free(prezzi);
    prezzi = NULL;
    return 0;
}