#include <stdio.h> 
#include <stdbool.h>
/*  Globale variabler */

int main() 
{ // "gitt område"
     //  while (isRunning) {
bool isRunning = true;  //global value input

// char little = 'a';
// char big = 'A';
    int INPUTASCII;
 //use ascii karakter translation instead
int char1, char2;
int EndeligBrukerBokstav;      
// switch (letter) {

//     case 'A':
//         printf("a");
//         break; 
//     case 'a':
//         printf("A");
//         break;
//         default:
//         printf("Please try again: ");
// } min original strategi var slikt men jeg var fortalt å gå mot ascii bokstaver og tabellen.

 printf("Skriv et eller to bokstaver, A, eller a. \n (Denne koden er laget for å kunne forstå to bokstaver om gangen)");

EndeligBrukerBokstav = scanf("%lc%lc",&char1, &char2); // declarerer variablen som til å ha en array av 2 karakterer  


//vi trenger 3 If løkker, en for å sjekke om A eller a er satt inn, og to som da har om de to forholdene, dersom det er to bokstaver satt inn eller om det er kun en bokstav satt in.


if (EndeligBrukerBokstav == 1)
{
    if (char1 == 'A')
    {
        INPUTASCII = char1 + 32 ; //konverter 'A' til 'a' //differansen mellom Liten og stor A er 32
        printf ("%c in lower case is %c\n", char1, INPUTASCII);
    }

} else if (char1 == 'a'){
    INPUTASCII = char1-32; //konverter 'a' mot 'A' differansen er det samme bare motsatt
    printf("%c in upper case is: %c \n", char1, INPUTASCII);
} else {
    
    printf("\n Ugyldig karakter, prøv igjen, enten A, eller a"); 
}


        // nå trenger vi en kode for dobbelte hendelser. 
        if (EndeligBrukerBokstav == 2) 
        {
            //første av to funksjoner
        //lignende oppsettelse bare litt annerledes slik at det er plass for en funksjon i tilfellen det er mer 
        //enn før for flere tilfeller.
            if (char1 == 'A'){
                INPUTASCII = char1 + 32 ; //konverter 'A' til 'a' //differansen mellom Liten og stor A er 32
                printf ("%c i småe bokstav: %c\n", char1, INPUTASCII);
            }
        } else if (char1 == 'a'){
            INPUTASCII = char1-32; //konverter 'a' mot 'A' differansen er det samme bare motsatt
            printf("%c i store bokstav er: %c \n", char1, INPUTASCII);
        } else { //den her går av selv om jeg har inputtet kun et bokstav skrevet inn
            printf("\n Ugyldig karakter, prøv igjen, enten A, eller a");
        }

        // andre plass konvertering av karakter
                if (char2 == 'A') {
                    INPUTASCII = char2 +32;  // konverter 'A' til 'a'
                    printf("\n%c i småe bokstav: %c \n", char2, INPUTASCII);
                } else if (char2 == 'a') {
                    INPUTASCII = char2 -32;  // konverter 'a' til 'A'
                    printf("\n%c i store bokstav er %c \n", char2, INPUTASCII);
                } else {
                    printf("\n Ugyldig karakter, prøv igjen, enten A, eller a");
                }
            }
//}

// jeg har ingen anning på hva ascii er egentlig liksom så det er veldig vanskelig for å kode for noe ukjent.