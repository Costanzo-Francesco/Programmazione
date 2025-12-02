/* Inserire una serie di temperature, l'inserimento terminerà con l'inserimento
del carattere '100'. Calcolare la media delle temperature inserite (formato
%0.2f) utente guitato passo passo. Calcolare quante temperature pari e quante
dispari. Calcolare temperatura più alta e quella più bassa.*/

//

#include <stdio.h>

int main() {

  float somma_temperature, temperatura_maggiore,
      temperatura_minore, media;
  int temperature_pari = 0, temperature_dispari = 0, cont = 0, temperatura;

    printf("\nInserisci valori delle temperature per calcolarne la media e sapere quali sono dispari e quali pari.\n Il programma terminerà scrivendo il valore '100'");
        do {
    scanf("%f", &temperatura);
    if (temperatura % 2 == 0) {

      temperature_pari = temperature_pari + 1;
    } else {

      temperature_dispari = temperature_dispari + 1;
    }
    cont = cont + 1;
    somma_temperature = somma_temperature + temperatura;

    if (temperatura > temperatura_maggiore) {
      temperatura_maggiore = temperatura;
    } else if (temperatura < temperatura_minore) {
      temperatura_minore = temperatura;
    }
    }   while (temperatura != 100);

    media = somma_temperature / cont;

    printf ("\nLa media è %.2f. \nLa temperatura maggiore è %.2f.\nLa temperatura minore è %0.2f.\nIl numero delle temperature dispari è %d e pari è %d ", media, temperatura_maggiore, temperatura_minore, temperature_dispari, temperature_pari);
    return 0;
}