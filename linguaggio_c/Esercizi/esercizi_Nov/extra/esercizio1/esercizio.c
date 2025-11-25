#include <stdio.h>

int main() {

  int numero;

  printf("\n Inserisci un numero, il programma ti dirà se è pari o dispari \n");
  scanf("%d", &numero);

  if (numero == 0) {

    printf("\n 0 è neutro");

  } else if ((numero / 2) * 2 == numero) {

    printf("\n %d è pari", numero);

  } else {

    printf("\n %d è dispari", numero);
  }

  return 0;
}