/*dato un vettore di 8 numeri interi stampare in uscita la somma e la media*/

#include <stdio.h>

const int contatore = 8;

int main() {

  int numeri[contatore];
  int somma, media;

  printf("\nScrivi 8 numeri per ottenere somma e media");

  for (int i = 0; i < contatore; i++) {

    printf("\nInserisci il numero %d:\t", i + 1);
    scanf("%d", &numeri[i]);
  }

  for (int i = 0; i < contatore; i++) {

    somma += numeri[i];
  }
  media = somma / contatore;

  printf("\nLa somma dei numeri è %d.\n La media è %d.", somma, media);
  return 0;
}