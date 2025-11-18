#include <stdio.h>
#include <math.h>

int main () {

    int figura, l, b, h;
    double a, p, r;

    printf ("\n Inserisci un numero per indicare:\n1\tquadrato\n2\trettangolo\n3\trombo\n4\tcerchio \n");
    scanf("%d", &figura);
    while (figura<1 || figura>4) {

        printf ("Inserire un numero corretto:\n1\tquadrato\n2\trettangolo\n3\trombo\n4\tcerchio");
        scanf("%d", &figura);

    }

    if (figura == 1) {      //quadrato

        printf("Inserisci valore del lato del quadrato:\n");
        scanf("%d", &l);
        while (l<0) {

            printf ("Non esistono lati minori di 0");
            scanf("%d", &l);

        }

        a = pow(l,2);
        p = l * 4;
        printf ("Il valore del perimetro è %0.1f, il valore dell'area è %0.1f \n", p, a);

    } else if (figura == 2) {       //rettangolo

        printf("Inserisci la base del rettangolo:\n");
        scanf ("%d", &b);
        while (b<0) {

            printf ("Un rettangolo non può avere la base minore di 0 \n");
            scanf ("%d", &b);
        }
        printf ("Ora inserisci la sua altezza \n");
        scanf ("%d", &h);
        while (h<0) {

            printf ("L'altezza di un rettangolo non può essere minore di 0\n");
            scanf ("%d", &h);
        }

        a = b * h;
        p = 2 * (b+h);
        printf ("Il perimetro del rettangolo è %0.1f, l'area è %0.1f\n", p, a);

    } else if (figura == 3) {       //rombo

        
        printf("Inserisci valore del lato del rombo:\n");
        scanf("%d", &l);
        while (l<0) {

            printf ("Non esistono lati minori di 0");
            scanf("%d", &l);

        }

        a = pow(l,2);
        p = l * 4;
        printf ("Il valore del perimetro è %0.1f, il valore dell'area è %0.1f \n", p, a);
        
    } else if (figura == 4) {       //cerchio

        printf("Inserisci il valore del raggio del cerchio:\n");
        scanf ("%lf", & r);
        while (r<0) {

            printf ("Non esistono raggi minori di 0\n");
            scanf ("%f", & r);
        }
        a = M_PI * pow(r, 2.0);
        p = 2 * M_PI * r;

        printf ("La circonferenza del cerchio è %0.2lf, l'area è %0.2lf\n", p, a);
    } else {}

    return 0;
}