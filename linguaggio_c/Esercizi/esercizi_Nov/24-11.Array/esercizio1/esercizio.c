// crea un array di 6 numeri e scrivili al rovescio

#include <stdio.h>
const int numeri = 5;
int main() {

  int numeri_registrati[5];

  printf("\nInserisci numeri per visualizzarli al contrario\n");

  for (int i = 0; i <= numeri; i++) {

    printf("Inserisci un numero:\n");
    scanf("%d", &numeri_registrati[i]);
  }
  printf ("\n L'ordine dei numeri al contrario è: \n");
  for (int i = numeri; i >= 0; i--) {

    printf("%d\t", numeri_registrati[i]);
  }
  printf ("\n");
  return 0;
}