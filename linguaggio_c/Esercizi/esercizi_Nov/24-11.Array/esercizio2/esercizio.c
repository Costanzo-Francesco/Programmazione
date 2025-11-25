#include <stdio.h>
int main() {
  int n, i;
  float media = 0;
  float somma = 0;

  printf("Quanti voti vuoi inserire? ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Errore: inserire un numero positivo.\n");
    return 1;
  }

  float voti[n];

  for (i = 0; i < n; i++) {
    do {
      printf("Inserisci il voto %d (0-10): ", i + 1);
      scanf("%f", &voti[i]);
    } while (voti[i] < 0 || voti[i] > 10);
  }

  printf("\nVoti inseriti:\n");
  for (i = 0; i < n; i++) {
    printf("Voto %d: %.2f\n", i + 1, voti[i]);
  }

  for (i = 0; i < n; i++) {
    somma = somma + voti[i];
  }

  media = somma / n;

  printf("\nLa media dei voti è: %.2f\n", media);

  return 0;
}