#include <stdio.h>
#include <string.h> //for bruk av strlen som

// int main(){
//     //programmet skal skrive ut første og siste bokstav i tekstrengen
//     char **ptekst;
//     char tekst[] = "Hvor skal det pekes?";
//     *ptekst = &tekst; // ptekst må initialiseres før det brukes.
//     printf("s innholder tekstrengen %s \n", ptekst);// Feilet her er at  "ptekst" peker ikke på en gyldig minneadresse.
//     ptekst[0]=tekst; // ptekst må initialiseres før det brukes.igjen
//     printf("s[0] innehold %s\n", ptekst[0]); //udefinert ting
//     int lengde = strlen(tekst);
//     ptekst[lengde] = tekst; //udefinert ting
//     printf("s[lengde] inneholder %s\n", ptekst[lengde]); //udefinert ting
//     return 0;    
// }

int main(){
    char tekst[] = "Hvor skal det pekes?";
    char *ptekst = tekst; // ptekst peker nå på første karakter i tekst

    // Skriv ut første og siste bokstav
    printf("Første bokstav: %c\n", ptekst[0]); // Første bokstav
    printf("Siste bokstav: %c\n", ptekst[strlen(tekst) - 2]); // Siste bokstav (før newline)

    return 0;    
}

