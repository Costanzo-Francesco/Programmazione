#include <stdio.h>

int main () {

    int n;
    
    printf("inserisci un numero intero positivo da tastiera \n");
    scanf("%d", & n); //quello che scrivi da tastiera finisce in n
    

    if (n%2==0){

    printf ("%d è pari", n);
    
    } else {

        printf ("%d è dispari", n);

    }
    
    return 0;
}