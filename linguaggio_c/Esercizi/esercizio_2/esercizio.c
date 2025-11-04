#include <stdio.h>

int main (){

    float c, f;    

    printf ("\nScrivi i gradi in fahrenheit\n");
    scanf("%f", &f);
    c= 5*(f-32)/9;
    printf("\n I gradi in celsius sono %.2f \n", c);

    return 0;
}   