#include <stdio.h>

#define N 5
#define MAXCHAR 20

struct studente {
    char cognome[MAXCHAR];
    char nome[MAXCHAR];
    float media;
};

void main (){
    
    int nStudenteMigliore = 0;
    struct studente arr[N];
    float max = 0;
    for (int i = 0; i < N; i++){
        printf("\nInserisci il nome dello studente numero %d:", i + 1);
        scanf("%s", arr[i].nome);
        printf("\nInserisci il cognome dello studente numero %d:", i + 1);
        scanf("%s", arr[i].cognome);
        printf("\nInserisci il media dello studente numero %d:", i + 1);
        scanf("%f", &arr[i].media);
    }

    for (int i = 0; i < N; i++){
        printf("\nStudente %d:\nNome:%s\nCognome:%s\nMedia:%0.2f.\n\n", i + 1, arr[i].nome, arr[i].cognome, arr[i].media);

        if (arr[i].media > arr[nStudenteMigliore].media){
            nStudenteMigliore = i;
            max = arr[nStudenteMigliore].media;
        }
    }

    printf("\n---\tStudenti migliori\t---\n");
    for (int i = 0; i < N; i++){
        if(arr[i].media == max){
            printf("\nStudente %d:\nNome:%s\nCognome:%s\nMedia:%0.2f.\n\n", i + 1, arr[i].nome, arr[i].cognome, arr[i].media);
        }
    }
}