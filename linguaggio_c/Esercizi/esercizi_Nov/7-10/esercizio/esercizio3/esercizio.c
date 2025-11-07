//tavola pittagorica

#include <stdio.h>

int main () {

int i, j, ris;

    printf("\n Ecco a te la tavola pittagorica! \n");

    for (i = 1; i <= 10; i++){

        for (j = 1; j <= 10; j++){

            ris = i*j;
            printf("%d\t", ris);
        }
        printf("\n");

    }

    return 0;
}