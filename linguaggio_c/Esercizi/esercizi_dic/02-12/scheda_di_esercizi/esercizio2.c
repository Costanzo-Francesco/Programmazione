/*
Massimo, minimo e media (numeri random)
Genera un array di 30 numeri casuali tra 0 e 500.
Calcola e stampa:
• il massimo
• il minimo
• la media
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define min 0
#define max 501
#define numeriCasuali 30

int main() {

  int massimo, minimo;
  int numeri[numeriCasuali];
  float media, somma=0;

  srand(time(NULL));
  for (int i = 0; i < numeriCasuali; i++) {
  
    numeri[i] = rand() % max + min;

    if (i == 0) {
      massimo = numeri[i];
      minimo = numeri[i];
    }

    if (massimo < numeri[i]) {

      massimo = numeri[i];
    }
    if (minimo > numeri[i]) {

      minimo = numeri[i];
    }
    somma += numeri[i];
  }

  media = somma / numeriCasuali;

  printf("\n Il numero più alto è %d, il numero più basso è %d. La media è %f",
         massimo, minimo, media);

  return 0;
}