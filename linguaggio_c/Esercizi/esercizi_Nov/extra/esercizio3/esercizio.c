#include <stdio.h>

int main () {

    int a = 0, b = 1, c, i;
    printf ("\n %d \t", a);
    printf ("%d \t", b);
    for (i = 1; i <= 10; i ++){

        c = a + b;
        a = b;
        b = c;
    printf ("%d \t", c);
        

    }

    return 0;
}