#include <stdio.h>
 
int main() {
    
//Per le matrici servono 2 cicli  il primo per le righe. Il secondo per le colonne);
  
  int mat[3][4]; // il primo per le righe. Il secondo per le colonne);
  for (int r=0; r<3; r++)
  {
    for (int c=0; c<4; c++){
      printf("\nInserisci l'elemento riga %d e colonna %d", r, c);
      scanf("%d", & mat[r][c]);

    }
  }
  for (int r=0; r<3; r++){
    for (int c=0; c<4; c++){
      printf("\t %d", mat[r][c]);
    }
 printf("\n");
  }
  return 0;
}
