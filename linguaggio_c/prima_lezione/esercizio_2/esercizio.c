
//dichiara 2 variabili dagli un valore e scambia i valori

#include <stdio.h>


int main (){    

    int a = 10;
    int b = 20;
    int temp;

    temp =a;
    a = b;
    b = temp;

    printf ("a è uguale a %d, invece b è uguale a %d", a, b);
    return 0;

}