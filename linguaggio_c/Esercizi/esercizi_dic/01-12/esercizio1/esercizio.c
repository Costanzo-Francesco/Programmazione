/*
Media casuale (riempire un array e calcolare una media)
1. dichiara un array di 10 numeri interi.
2. riempilo con numeri casuali compresi tra 1 e 100
3. stampa tutti i numeri generati
4. calcola e stampa la media dei valori contenuti nell'array.
*/

#include <stdio.h>
#include <stdlib.h> // per rand() e srand()
#include <time.h>

const int N = 10;

int main() {

  srand(time(NULL));

  int numeri[N];
  int somma = 0;
  float media;

  for (int i = 0; i < N; i++) {
    numeri[i] = rand() % 100 + 1;
    printf("%d", numeri[i]);
    somma += numeri[i];
  }
  printf("\n");
  media = somma / N;
  printf("I numeri sono: ");
  for (int i = 0; i < N; i++) {
    printf("%d\t", numeri[i]);
  }
  printf("\nLa media è %0.2f \n", media);
  return 0;
}