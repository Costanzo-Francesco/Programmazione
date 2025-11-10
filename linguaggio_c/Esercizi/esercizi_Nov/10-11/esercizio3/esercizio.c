/* Inserire un numero >=0, di tale numero calcolarne il fattoriale.
Ricorda: 0! =1 1! = 1....5! = 1*2*3*4*5
*/

#include <stdio.h>

int main (){

    int f = 1, n, i;


    printf("\n Inserisci un numero per calcolarne il fattoriale \n ");
    scanf ("%d", &n);

while (n<0){

    printf ("Non esiste il fattoriale di %d (numero negativo) \n", n);
    scanf ("%d", &n);
}
    for (i = 1; i <= n; i++) {

        f = f * i;

    }
    printf ("\n Il fattoriale di %d è %d \n",n, f);

    return 0;

}