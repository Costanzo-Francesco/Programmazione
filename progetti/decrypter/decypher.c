#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//costanti importanti
const int LETTEREALFABETO = 21;
const char ALFABETO[] = {'a','b','c','d','e','f','g','h','i',
                         'l','m','n','o','p','q','r','s','t',
                         'u','v','z'};
const int MAXCARATTERI = 20;

//main
int main(int argc, char **argv) {
    
    //"trasformazione" da string in int
    int k = atoi(argv[1]);

    char parola[MAXCARATTERI + 1];
    strncpy(parola, argv[2], MAXCARATTERI);

    //Stampa del "menu"
    printf("Input:  %s\n", parola);
    printf("Chiave: %d", k);

    //cicli for per scorrere lettere e sostituire
    for (int i = 0; parola[i] != '\0'; i++) {
        
        for (int j = 0; j < LETTEREALFABETO; j++) {
            if (parola[i] == ALFABETO[j]) {
                int nuova_pos = (j - k + LETTEREALFABETO) % LETTEREALFABETO;
            
                parola[i] = ALFABETO[nuova_pos];
                break;
            }
        }
    
    }
    //stampa risulitato
    printf("\nRisultato: %s\n", parola);
    return 0;
}