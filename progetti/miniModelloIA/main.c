//Controllo bit parità pari.
//NOTA: I pesi sono stati pre-calcolati, no Backpropagation e no Gradient Descent.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

const int NUMERO_NEURONI_PRIMO_LAYER = 2;
const int INPUT_SIZE = 3;   //in questo caso 1 2 3

typedef struct {
    double *dati;
    double *pesi;
    double z;
    double a;
    double bias;
} Neurone;

double calcZ(double *w, double *x, int n);
double sigmoid(double z);

int main(int argc, char *argv[]) {

    if (argc < INPUT_SIZE + 1) {
        printf("Uso: %s x1 x2 x3\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen("weight.txt", "r");
    if (!fp) {
        printf("Errore apertura file\n");
        return 1;
    }

    /* ================= INPUT ================= */
    double input[INPUT_SIZE];
    for (int i = 0; i < INPUT_SIZE; i++) {
        input[i] = atof(argv[i + 1]);
    }

    /* ================= PRIMO LAYER ================= */
    Neurone hidden[NUMERO_NEURONI_PRIMO_LAYER];

    for (int i = 0; i < NUMERO_NEURONI_PRIMO_LAYER; i++) {

        hidden[i].dati = malloc(INPUT_SIZE * sizeof(double));
        hidden[i].pesi = malloc(INPUT_SIZE * sizeof(double));

        if (!hidden[i].dati || !hidden[i].pesi) {   //se memoria insufficiente: CRASH
            printf("Memoria insufficiente\n");
            free(hidden[i].dati);
            free(hidden[i].pesi);
            printf("\nQUITTING...\n");
            return 1;
        }

        /* copia input */
        for (int j = 0; j < INPUT_SIZE; j++) {
            hidden[i].dati[j] = input[j];
        }

        /* leggi pesi dal file */
        for (int j = 0; j < INPUT_SIZE; j++) {
            char buffer[64];
            if (!fgets(buffer, sizeof(buffer), fp)) {   //se file vuoto, o non legge per x motivi: CRASH
                printf("Errore lettura pesi\n");
                printf("\nQUITTING...\n");
                return 1;
            }
            hidden[i].pesi[j] = atof(buffer);
        }

        /* leggi bias */
        char buffer[64];
        if (!fgets(buffer, sizeof(buffer), fp)) {
            printf("Errore lettura bias\n");
            printf("\nQUITTING...\n");
            return 1;
        }
        hidden[i].bias = atof(buffer);

        /* forward */
        hidden[i].z = calcZ(hidden[i].pesi, hidden[i].dati, INPUT_SIZE)
                      + hidden[i].bias;

        hidden[i].a = sigmoid(hidden[i].z);
    }

    /* ================= OUTPUT LAYER / SECONDO LAYER ================= */
    Neurone out;

    out.dati = malloc(NUMERO_NEURONI_PRIMO_LAYER * sizeof(double)); //Il massimo di input sono gli 'a' prodotti dai neuroni del primo layer
    out.pesi = malloc(NUMERO_NEURONI_PRIMO_LAYER * sizeof(double));

    if (!out.dati || !out.pesi) {
        printf("Memoria insufficiente\n");
        free(out.dati);
        free(out.pesi);
        printf("\nQUITTING...\n");
        return 1;
    }

    for (int i = 0; i < NUMERO_NEURONI_PRIMO_LAYER; i++) {
        out.dati[i] = hidden[i].a;
    }

    /* pesi output */
    for (int i = 0; i < NUMERO_NEURONI_PRIMO_LAYER; i++) {
        char buffer[64];
        if (!fgets(buffer, sizeof(buffer), fp)) {
            printf("Errore lettura output weights\n");
            printf("\nQUITTING...\n");
            return 1;
        }
        out.pesi[i] = atof(buffer);
    }

    /* bias output */
    char buffer[64];
    if (!fgets(buffer, sizeof(buffer), fp)) {
        printf("Errore lettura output bias\n");
        printf("\nQUITTING...\n");
        return 1;
    }
    out.bias = atof(buffer);

    /* forward output */
    out.z = calcZ(out.pesi, out.dati, NUMERO_NEURONI_PRIMO_LAYER)
            + out.bias;

    out.a = sigmoid(out.z);

    printf("\nOUTPUT FINALE: %lf\n", out.a);
    if (out.a > 0.25){
        printf("\nBit di parita': 1");
    } else {
        printf("\nBit di parita': 0");
    }
    /* ================= FREE ================= */
    for (int i = 0; i < NUMERO_NEURONI_PRIMO_LAYER; i++) { //libero memoria allocata precedentemente
        free(hidden[i].dati);
        free(hidden[i].pesi);
    }

    free(out.dati);
    free(out.pesi);

    fclose(fp);

    return 0;
}

/* ================= FUNZIONI ================= */

double calcZ(double *w, double *x, int n)
{
    double z = 0;
    for (int i = 0; i < n; i++) {
        z += w[i] * x[i];
    }
    return z;
}

double sigmoid(double z)
{
    return 1.0 / (1.0 + exp(-z));
}