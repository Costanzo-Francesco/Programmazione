//inserire 10 numeri interi positivi e segnala se sono numeri primi dimmi il totale di essi.


#include <stdio.h>

int main (){
int n, cont, primi_totali;
    printf ("\nInserisci 10 numeri positivi per sapere se sono primi e il loro totale. \n");

    for (int i = 1; i<= 10; i ++) {

        cont = 0;
        
        scanf ("%d", &n);
        for (int j = 1; j <= n; j++) {

                if (n%j==0){
                cont = cont + 1;

                }   else {}
            }
        if ( cont <= 2) {

            printf ("è un numero primo\n");

            primi_totali = primi_totali + 1;
        } else {

            printf("Non è un numero primo\n");
        }
        
    }
    printf ("Il totale dei numeri primi è %d \n", primi_totali);
    return 0;
}