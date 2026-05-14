#include <stdio.h>
#include <stdlib.h>

int main () {

    int nStudenti;
    printf("\nInserisci numero di studenti: ");
    scanf("%d", &nStudenti);

    int *voti = malloc(nStudenti * sizeof(int));
    for (int i = 0; i < nStudenti; i++){
        voti[i] = 10;
    }

    for (int i = 0; i < nStudenti; i++){
        printf("\nVoto studente %d: %d", i + 1, voti[i]);
    }
    printf("\n");
    free(voti);
    return 0;
    
}