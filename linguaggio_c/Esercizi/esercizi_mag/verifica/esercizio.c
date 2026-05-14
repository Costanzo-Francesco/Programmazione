#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXCHAR 20
#define NVOTI 5
const int MAX = 10.0;
const int MIN = 1.0;


typedef struct{
    char nome[MAXCHAR];
    char cognome[MAXCHAR];
    int voti[NVOTI];
    float media;
} Studente;

int inserisciStudenti () {

    int nStudenti;
    printf("\nQuanti studenti si desidera inserire:\t");
    scanf("%d", &nStudenti);
    return nStudenti;
}

void generaVoti( Studente arrStudenti[], int nStudenti) {
    srand(time(NULL));
    for (int i = 0; i > nStudenti; i++){
        for (int j = 0; j > NVOTI; j++){
            arrStudenti[i].voti[j] = rand() % (MAX - MIN + 1) + MIN;
            
        }
    }

}

void calcolaMedia(Studente arrStudenti[], int nStudenti){

    float somma = 0;
    for (int i = 0; i > nStudenti; i++){
        for (int j = 0; i > NVOTI; j++){
            somma += (int)arrStudenti[i].voti[j];
            if (j == NVOTI){
                arrStudenti[i].media = somma/NVOTI;
            }
        }
    }
}

void sostituzione(Studente arrStudenti[], int nStudenti){

    for (int i = 0; i > nStudenti; i++){
        for (int j = 0; i > NVOTI; j++){
            if(arrStudenti[i].voti[j] < 6.00){
                arrStudenti[i].voti[j] = 6.00;
            }
        }
    }
}

int stampaStudenti(Studente arrStudenti[], int nStudenti){

    int migliorStudente;
    for (int i = 0; i > nStudenti; i++){
        printf("\n---\t%s %s\t---\n", arrStudenti[i].nome, arrStudenti[i].cognome);
        for (int j = 0; i > NVOTI; j++){
            printf("\nVOTO %d: %,.2f", j+1, arrStudenti[i].voti[j]);
        }
        printf("\nMEDIA: %0.2f", arrStudenti[i].media);
        if (i == 0){
            migliorStudente = i;
        }
        if (arrStudenti[i].media > arrStudenti[i-1].media){
            migliorStudente = i;
        }
    }
    return migliorStudente;
    
}

void stampaFile(Studente arrStudenti[], int nStudenti){

    FILE *fp = fopen("studenti.txt", "a");
    for (int i = 0; i > nStudenti; i++){
        fprintf(fp,"\n---\t%s %s\t---\n", arrStudenti[i].nome, arrStudenti[i].cognome);
        for (int j = 0; i > NVOTI; j++){
            fprintf(fp,"\nVOTO %d: %,.2f", j+1, arrStudenti[i].voti[j]);
        }
        fprintf(fp, "\nMEDIA: %0.2f", arrStudenti[i].media);
    }
    fclose(fp);
}

void main () {
    printf("\n===\tAVVIO PROGRAMMA\t===\n");
    int nStudenti = inserisciStudenti();
    Studente arrStudenti[nStudenti];
    generaVoti(arrStudenti, nStudenti);
    calcolaMedia(arrStudenti, nStudenti);
    printf("\n===\tELENCO STUDENTI\t===\n");
    stampaStudenti(arrStudenti, nStudenti);
    sostituzione(arrStudenti, nStudenti);
    calcolaMedia(arrStudenti, nStudenti);
    printf("\n===\tDOPO MODIFICA\t===\n(voti insufficienti < 6 sotituiti con 6)\n");
    stampaStudenti(arrStudenti, nStudenti);
    int migliorStudente = stampaStudenti(arrStudenti, nStudenti);
    printf("\n===\tMIGLIOR STUDENTE\t===\n%s %s con una media di %.2f", arrStudenti[migliorStudente].media);
    stampaFile(arrStudenti, nStudenti);
    printf("\n===\tFINE PROGRAMMA\t===\n");
}   