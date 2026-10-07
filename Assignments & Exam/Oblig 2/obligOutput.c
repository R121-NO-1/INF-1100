#include <stdio.h>
#include "oppgaver.h"  // Inkluder header-filen som deklarerer funksjonene

int main() {
    int valg;  // Brukervalg

    // Print menyen
    printf("Velg en oppgave:\n");
    printf("1. Oppgave 1: \n");
    printf("2. Oppgave 2: \n");
    printf("3. Oppgave 3: \n");
    printf("4. Oppgave 4: \n");
    printf("5. Oppgave 5: \n");
    printf("Ditt valg: ");
    
    scanf("%d", &valg);  // Les brukerens valg

    // Bruk en switch for å kalle riktig funksjon basert på valg
    switch(valg) {
        case 1:
            oppgave1();  // Kaller funksjonen for oppgave 1
            break;
        case 2:
            oppgave2();  // Kaller funksjonen for oppgave 2
            break;
        case 3:
            oppgave3();  // Kaller funksjonen for oppgave 3
            break;
        case 4:
        oppgave4();  // Kaller funksjonen for oppgave 4
        break;
        // Legg til flere tilfeller her for oppgave 4, 5 og 6
        default:
            printf("Ugyldig valg!PRØV IGJEN\n");
    }

    return 0;
}


// while(true){
// printf("Hvilket vil Program vil du sjekke?");

// char valg;
// printf("vi har case, 1,2,3,4,5,6");
// scanf("%d", valg);

// switch (valg)
// {
// case 1:
    // //run code 
    // break;

// default:
    // break;
// }
// }
//slik som omtalt i en discord chat bruker jeg forskjellige funksjoner for mer oversiktlighet.





