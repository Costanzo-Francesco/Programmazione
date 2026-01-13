#include <stdio.h>

int main (){

  int rig, col;
  
  printf("\nInserisci il numero di righe\n");
  scanf("%d", &rig);
  printf("\nInserisci il numero di colonne\n");
  scanf("%d", &col);


  while (rig!=col){
    printf("\nReinserisci i valori, deve essere un quadrato.");
    printf("\nInserisci il numero di righe\n");
    scanf("%d", &rig);
    printf("\nInserisci il numero di colonne\n");
    scanf("%d", &col);
  }
  int mat[rig][col];
  for (int r=0; r<rig; r++){
    for (int c=0; c<col; c++){
      if (r==c){
        mat[r][c]=1;
      } else {
        mat[r][c]=0;
      }
    }
  }
  for (int r=0; r<rig; r++){
    for (int c=0; c<col; c++){
      printf("%d\t", mat[r][c]);
    }
    printf("\n");
  }
  return 0;
}
