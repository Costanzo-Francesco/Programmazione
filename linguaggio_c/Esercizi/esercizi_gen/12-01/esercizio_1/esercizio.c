#include <stdio.h>

const int tot = 10;

int fmassimo (int numeri[]);
float fmedia (int numeri[]);


int main() {

  int numeri[tot];
  int massimo;
  float media;

   printf("\nInserisci 10 numeri.");
  for (int i = 0; i <tot; i++){
    printf("Inserisci il %d° numero", i+1);
    scanf("%d", &numeri);

  }
  
  massimo = fmassimo(numeri);
  media = fmedia(numeri);

  printf("\nIl numero più alto è %d",massimo);
  printf("\nLa media è è %d", media);

}



int fmassimo (int numeri[]){
  
  int massimo;

  for (int i = 0; i < tot; i++){
    if(i==0){
      massimo = numeri[i];
    }
    if (numeri[i]>massimo){
      massimo=numeri[i];
    }
  }
  return massimo;
}



float fmedia (int numeri[]){

  float somma = 0;
  float media;

    for (int i = 0; i < tot; i++){
    somma += numeri[i];
  }
  media = somma/tot;
  
  return media;
}



