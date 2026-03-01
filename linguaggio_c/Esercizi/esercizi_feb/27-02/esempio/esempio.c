// Puntatori

#include <stdio.h>

int main() {
int a = 10;
int *p = &a;

printf("Valore di a: %d\n", a);
printf("Indirizzo di a: %p\n", &a);
printf("Indirizzo memorizzato in p: %p\n", p);
printf("Valore puntato da p: %d\n", *p);

//cambiare variabili. Variabile puntata da p.
*p = 20;
printf("Nuovo valore di a: %d\n", a);

return 0;
}
