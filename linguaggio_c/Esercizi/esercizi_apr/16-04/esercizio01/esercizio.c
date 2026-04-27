//inserisci dati in struttura nome eta voto, inserisci dati e stampa

#include <stdio.h>

#define MAXCHAR 20

struct StrutturaStudente {

    char nome[MAXCHAR];
    int anni;
    float media;
};

void main (){
    int nStudenti;
    printf("\nQuanti studenti vuoi inserire?");
    scanf("%d", &nStudenti);
    struct StrutturaStudente arr[nStudenti];
    
    for (int i = 0; i < nStudenti; i++){
        printf("\nInserisci il nome:");
        scanf("%s", arr[i].nome );
        printf("\nInserisci gli anni:");
        scanf("%d", &arr[i].anni);
        printf("\nInserisci la media:");
        scanf("%f", &arr[i].media);
    }
    
    for (int i = 0; i < nStudenti; i++){
        printf("nome: %s, anni: %d, media: %0.2f\n", arr[i].nome, arr[i].anni, arr[i].media);
    }
    
}