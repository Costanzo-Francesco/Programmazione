//3 Leggi tre numeri e visualizzali in ordine crescente oppure decrescente in base alla richiesta di un utente. 

#include <stdio.h>

int main (){

int n1, n2, n3;

    printf("\n Inserisci 3 numeri e visualizzali in che ordine vuoi \n");

    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

    if (n1==n2 || n2==n3 || n1==n3); {

        printf("due numeri sono uguali \n");
    }

    if (n1>n2 && n2>n3) {

        printf ("\n %d %d %d \n", n1, n2, n3);
        
    } else if  (n1>n3 && n3>n2){

        printf ("\n %d %d %d \n", n1, n3, n2);

    } else if (n2>n1 && n1>n3){

        printf ("\n %d %d %d \n", n2, n1, n3);

    } else if (n2>n3 && n3>n2){

        printf ("\n %d %d %d \n", n2, n3, n2);

    }  else if (n3>n2 && n2>n1){

        printf ("\n %d %d %d \n", n3, n2, n1);
    
    } else if (n3>n1 && n3>n2){

        printf ("\n %d %d %d \n", n3, n1, n2);
        
    }

    return 0;
}