#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define LETTEREMAX 20
#define MAXASCII 90
#define MINASCII 65

typedef struct {
    
    char nome[LETTEREMAX];
    char cognome[LETTEREMAX];
    int  numero;
    char email[LETTEREMAX];
    char dataDiNascita[LETTEREMAX];

} rubrica;


void main () {

    int nPersone;

    printf("\n---\tAVVIO...\t---\n\nInserisci il numero di persone che si desidera aggiungere:");
    scanf("%d", &nPersone);
    printf("\n---\tINIZIALIZZAZIONE...\t---\n");

    rubrica arrPersone[nPersone];

    for (int i = 0; i < nPersone; i++){
        printf("\n---\tPERSONA %d\t---\n", i + 1);
        printf("\nNOME: ");
        scanf("%s", arrPersone[i].nome);
        printf("\nCOGNOME: ");
        scanf("%s", arrPersone[i].cognome);
        printf("\nNUMERO DI TELEFONO: ");
        scanf("%d", &arrPersone[i].numero);
        printf("\nEMAIL: ");
        scanf("%s", arrPersone[i].email);
        printf("\nDATA DI NASCITA: ");
        scanf("%s", arrPersone[i].dataDiNascita);

        for(int j = 0; j < strlen(arrPersone[i].nome); j++){arrPersone[i].nome[j] = toupper(arrPersone[i].nome[j]);}
        for(int j = 0; j < strlen(arrPersone[i].cognome); j++){arrPersone[i].cognome[j] = toupper(arrPersone[i].cognome[j]);}
        if (i + 1!= nPersone){
            printf("\n---\tPROSSIMA PERSONA\t---\n");
        }
        
    }
    printf("\n---\tSTAMPA...\t---\n\n");
    //da 65 a 90

    for (char c = 'A'; c <= 'Z'; c++){
        for (int j = 0; j < nPersone; j++){
            if (arrPersone[j].cognome[0] == c){
                printf("\n---\t%s %s\t---\nNUMERO: %d\nEMAIL: %s\nDATA DI NASCITA: %s\n", arrPersone[j].nome, arrPersone[j].cognome, arrPersone[j].numero, arrPersone[j].email, arrPersone[j].dataDiNascita);
            
            }
        
        }
            
            
    }

}
