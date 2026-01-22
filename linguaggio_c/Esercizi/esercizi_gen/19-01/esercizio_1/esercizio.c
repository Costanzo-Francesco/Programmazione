#include <stdio.h>
#include <string.h>

#define N 10 // numero massimo di auto
#define LUNG 11 // lunghezza massima targa (10+1 per '\0')


//targhe = ARRAY DI N STRINGHE
//targhe[i] = 1 stringa
//targhe[i][j] = 1 carattere

//char targhe[][LUNG] → passo un array di stringhe
//la dimensione delle colonne va sempre indicata


/* Funzione per inserire le targhe */
void inserisciTarghe(char targhe[][LUNG], int n) {
int i;
for (i = 0; i < n; i++) {
printf("Inserisci targa %d: ", i + 1);
scanf("%s", targhe[i]);//AB123CD %s per le stringhe
//stringa = array di char
}
}

/* Funzione per stampare solo le targhe NON vuote */
void stampaTarghe(char targhe[][LUNG], int n) {
int i;
printf("\nAuto ancora rubate:\n");
for (i = 0; i < n; i++) {
// controllo se la stringa NON è vuota
if (strcmp(targhe[i], "") != 0) {
printf("%s\n", targhe[i]);
}
}
}

/* Cerca una targa nel vettore
restituisce l'indice se trovata, -1 altrimenti */
int cercaTarga(char targhe[][LUNG], int n, char targa[]) {
int i;
for (i = 0; i < n; i++) {
if (strcmp(targhe[i], targa) == 0) {
return i; // targa trovata
}
}
return -1; // targa non trovata
}

/* Rimuove la targa mettendo una stringa vuota */
void rimuoviTarga(char targhe[][LUNG], int indice) {
strcpy(targhe[indice], "");
}

int main() {
char targhe[N][LUNG];
int num;
char targaRitrovata[LUNG];
int pos;

printf("Quante auto rubate vuoi inserire? ");
scanf("%d", &num);

inserisciTarghe(targhe, num);

printf("\nInserisci la targa dell'auto ritrovata: ");
scanf("%s", targaRitrovata);

pos = cercaTarga(targhe, num, targaRitrovata);

if (pos != -1) {
rimuoviTarga(targhe, pos);
printf("Auto ritrovata e rimossa dal vettore.\n");
} else {
printf("Targa non trovata.\n");
}

stampaTarghe(targhe, num);

return 0;
}
