/* Calcolatrice semplice – versione corretta  copiata da AI */
#include <stdio.h>
#include <stdlib.h>     /* per exit() */

float addizione(float a, float b)    { return a + b; }
float sottrazione(float a, float b) { return a - b; }
float moltiplicazione(float a, float b) { return a * b; }
float divisione(float a, float b)
{
    if (b == 0.0f) {
        printf("\nErrore: divisione per zero!\n");
        exit(EXIT_FAILURE);          /* terminazione immediata */
    }
    return a / b;
}

int main(void)
{
    float n1, n2, ris;      /* usa float per ottenere risultati decimali */
    int    operazione;      /* scelta dell’operazione */

    /* Input */
    printf("\nInserisci il primo numero: ");
    if (scanf("%f", &n1) != 1) {
        printf("\nInput non valido!\n");
        return EXIT_FAILURE;
    }

    printf("Inserisci il secondo numero: ");
    if (scanf("%f", &n2) != 1) {
        printf("\nInput non valido!\n");
        return EXIT_FAILURE;
    }

    /* Menu */
    printf("\nScegli l'operazione desiderata:\n");
    printf(" 1 - Addizione\n");
    printf(" 2 - Sottrazione\n");
    printf(" 3 - Moltiplicazione\n");
    printf(" 4 - Divisione\n");
    printf(" 5 - Esci\n");
    printf("Operazione: ");

    if (scanf("%d", &operazione) != 1) {
        printf("\nInput non valido!\n");
        return EXIT_FAILURE;
    }

    /* Calcolo */
    switch (operazione) {
        case 1:
            ris = addizione(n1, n2);
            break;
        case 2:
            ris = sottrazione(n1, n2);
            break;
        case 3:
            ris = moltiplicazione(n1, n2);
            break;
        case 4:
            ris = divisione(n1, n2);
            break;
        case 5:
            printf("Uscita.\n");
            return 0;
        default:
            printf("\nOperazione non valida!\n");
            return EXIT_FAILURE;
    }

    /* Output */
    printf("\nIl risultato è: %.6f\n", ris);
    return 0;
}
