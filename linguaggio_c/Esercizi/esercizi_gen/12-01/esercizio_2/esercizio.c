#include <stdio.h>
const int elementi = 5;

int main (){

  int v1[elementi];
  int v2[elementi];
  int v3[elementi];


  printf("\nInserisci i 5 numeri del primo insieme\n");

  for (int i = 0; i < elementi; i++){
    
    printf("Inserisci il numero allo spazio %d\n", i+1);
    scanf("%d", &v1[i]);
  }

  printf("\nInserisci i 5 numeri del secondo insieme\n");

  for (int i = 0; i < elementi; i++){
    
    printf("Inserisci il numero allo spazio %d\n", i+1);
    scanf("%d", &v2[i]);
    }


  printf("\nI numeri del terzo insieme sono:\n");

  for (int i = 0; i < elementi; i++){

    v3[i] = v1[i] + v2[i];

    printf("%d\t", v3[i]);
  }

  printf("\n");

  return 0;
}
