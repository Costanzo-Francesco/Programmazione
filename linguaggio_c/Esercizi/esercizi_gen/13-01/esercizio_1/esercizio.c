#include <stdio.h>


int main () {
  
  int n,m,r,c,temp;

  printf("\nInserisci le righe della matrice:");
  scanf("%d", &r);
  printf("\nInserisci le colonne della matrice:");
  scanf("%d", &c);

  int mat[r][c];

  for (int i = 0; i < r; i++){

    for (int j = 0; j < c; j++){
      printf("\nInserisci il numero alla posizione: \nriga:%d \ncolonna:%d \n", i, j );
      scanf("%d", &mat[i][j]);
    }
  }
  printf("\n----Ora la matrice è riempita----\nOra scambio le righe pari con quelle dispari");
  
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){

      printf("%d\t", mat[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < r-1; i += 2){
    

        for (int j = 0; j < c; j++){
        temp = mat [i][j];
        mat[i][j] = mat [i+1][j];
        mat[i+1][j] = temp;
      }
     
    
  }

  printf("\n");

  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){

      printf("%d\t", mat[i][j]);
    }
    printf("\n");
  }

  return 0;
}
