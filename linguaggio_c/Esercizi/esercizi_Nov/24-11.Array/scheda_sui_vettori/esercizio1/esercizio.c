/*
1) Scrivi un programma che:
• Dichiara un vettore di 10 numeri interi.
• Chiede all’utente di inserire i valori.
• Stampa tutti gli elementi del vettore.
*/

#include <stdio.h>
const int max=10;
int main () {

    int vettore[9];
    printf ("\nInserisci 10 numeri.\n");

    for (int i = 0; i <= max-1; i++){

        scanf("%d", &vettore[i]);
    }

printf ("\nI tuoi numeri sono:\n");
for (int i = 0; i <=max-1; i++){

    printf ("%d \t", vettore[i]);
}
printf("\n");
return 0;
}