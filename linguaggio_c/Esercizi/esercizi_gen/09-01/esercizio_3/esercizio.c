#include <stdio.h>


int main () {

  //dichiaro matrice
 
  int mat[10][10];
  
  //riempio la matrice

  for (int r=0; r<10; r++){
    for (int c=0; c<10; c++){
      mat[r][c]= (r+1)*(c+1);
    }

    //scrivo il risultato

  }
  for (int r=0; r<10; r++){
    for (int c=0; c<10; c++){
      printf("%d\t", mat[r][c]);
    }
    printf("\n");
  }
  return 0;
}
