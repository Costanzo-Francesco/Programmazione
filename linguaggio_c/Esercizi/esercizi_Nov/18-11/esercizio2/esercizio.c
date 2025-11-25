//inserisci due cateti di un triangolo rettangolo e calcolane il perimetro e l'area


#include <stdio.h>
#include <math.h>

int main (){

    int cateto1, cateto2;
    double area, perimetro, ipotenusa;
    printf ("\nInserisci i due cateti del triangolo rettangolo per calcolarne area e perimetro\n");
    scanf ("%d", &cateto1);
    scanf ("%d", &cateto2);

    ipotenusa = sqrt(pow (cateto1, 2) + pow (cateto2, 2));
    perimetro = ipotenusa + cateto1 + cateto2;
    area = (cateto1 * cateto2)/2;

    printf ("Il perimetro è %0.2lf, invece l'area è di %0.2lf", perimetro, area);

    return 0;
}