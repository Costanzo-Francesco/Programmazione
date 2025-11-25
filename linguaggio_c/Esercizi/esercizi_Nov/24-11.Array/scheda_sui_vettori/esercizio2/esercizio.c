/*
2) Usando un vettore di 8 numeri interi:
1. Chiedi in input i valori.
2. Calcola e stampa:
    - La somma
    - La media aritmetica
*/

#include <stdio.h>

const int n_tot = 8;
int main() {

  int numeri[7], somma;
  float media;
  printf("\nPer il calcolo della somma e della media inserisci 8 numeri\n");

  for (int i = 0; i <= n_tot - 1; i++) {

    scanf("%d", &numeri[i]);
  }
  for (int i = 0; i <= n_tot - 1; i++) {
    somma += numeri[i];
  }
  media = somma / n_tot;
  printf("Somma = %d \n Media = %0.2f", somma, media);

  return 0;
}