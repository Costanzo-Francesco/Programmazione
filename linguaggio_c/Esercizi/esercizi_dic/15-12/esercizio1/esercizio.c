// 15/12/25 - F. Costanzo
//esercizio 1
// Due funzioni max e min di un numero scritto dall'utente:

#include <stdio.h>
void max(int n1, int n2);
void min(int n1, int n2);

int main(void) {

  int n1, n2;

  printf(
      "\nScrivi due numeri per sapere qual'è il più grande e il più piccolo\n");
  scanf("%d", &n1);
  scanf("%d", &n2);
  max(n1, n2);
  min(n1, n2);
  return 0;
}

void max(int n1, int n2) {

  if (n1 > n2) {
    printf("Il numero più alto è %d\n", n1);

  } else {
    printf("Il numero più alto è %d\n", n2);
  }
}

void min(int n1, int n2) {
  if (n1 < n2) {
    printf("Il numero più basso è %d\n", n1);
  } else {
    printf("Il numero più basso è %d\n", n2);
  }
}
