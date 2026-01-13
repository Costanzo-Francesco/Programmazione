/*
Scrivi un programma che, partendo dalla stringa "oggi piove", 
stampi la stringa in maiuscolo, aggiunga alla stringa la frase "domani sarà bel tempo" e stampi la nuova frase, 
restituisca in output la lunghezza della stringa e,infine, trasformi tutte le vocali "i", visualizzando il risultato
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (void) {

    char loStr[]="oggi piove";
    int len = strlen(loStr);
    char upStr[len];
    

    for (int i = 0; i <= len - 1; i++){
        upStr[i] = toupper(loStr[i]);
    }
   // char upStr[]=toupper(loStr);
    char str2[]="domani sarà bel tempo";

    printf("%s\n", upStr);
    strcat (upStr, str2);
    printf("%s\n", upStr);

    return 0;
}