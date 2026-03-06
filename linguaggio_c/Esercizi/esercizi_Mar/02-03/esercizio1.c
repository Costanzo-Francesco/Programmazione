#include <stdio.h>
#include <math.h>

void inserisci(double *ptrToValue){

    printf("Inserisci il valore\n:");
    scanf("%lf", &*ptrToValue);
}
void risoluzione(double a, double b, double c, double *x1, double *x2){

    

    *x1 = (-*ptrToB + sqrt(pow(*ptrToB, 2)-4* *ptrToA * *ptrToC))/ (2 * *ptrToA);
    *x1 = (-*ptrToB - sqrt(pow(*ptrToB, 2)-4* *ptrToA * *ptrToC))/ (2 * *ptrToA);  
}
int main (){

    double a, b, c, x1, x2;
    
    printf("\nInserisci i coefficienti di a, b e c:\n");
    inserisci(&a);
    inserisci(&b);
    inserisci(&c);  

    risoluzione(&a, &b, &c, &x1, &x2);

    printf("\nX1 è uguale a %0.2lf\nInvece X2 è uguale a %0.2lf", x1, x2);
    return 0;
}