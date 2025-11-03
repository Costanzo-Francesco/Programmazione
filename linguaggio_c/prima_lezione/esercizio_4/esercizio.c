//inserisci un numero, positivo negativo nullo

#include <stdio.h>

int main (){

    int n;

    printf("Inserisci un numero per sapere se è positivo negativo o nullo\n");
    scanf ("%d", & n);
    if (n>0){
        printf("Il numero è positivo \n");
    } else if (n<0) {
        printf("Il numero è negativo \n");
    } else {

    printf("Il numero è nullo \n");
    }

    return 0;

}