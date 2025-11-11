//1 Leggi due numeri e visualizzali in ordine crescente oppure decrescente in base alla richiesta di un utente. 

#include <stdio.h>


int main () {

    char scelta;
    int num1, num2;

    printf("\n Inserire ordinamento desiderato: c per ordine crescente d per decrescente \n");
    scanf("%c", & scelta);
    // mi raccomando usa '' nell'if per char e string

    printf("\n Inserire il primo numero \n");
    scanf ("%d", &num1);
    printf("\n Inserire secondo numero \n");
    scanf ("%d", &num2);

    if (scelta == 'c' || scelta == 'C'){
        if (num1<num2){
        printf(" %d - %d ", num1, num2);
        } else if (num1=num2){

            printf(" I due numeri sono uguali \n");
        } 
        {

            printf(" %d - %d ", num2, num1);
        }
    }

    else if (scelta == 'd' || scelta == 'D'){

        if (num1>num2){
        printf(" %d - %d ", num1, num2);
        } else if (num1=num2){

            printf(" I due numeri sono uguali \n");
        } else {

            printf(" %d - %d ", num2, num1);
        }

    }
    else {

        printf("\n Scelta non corretta, devi scegliere c per ordine crescentde o d per ordine decrescente");
    }
    return 0;
}