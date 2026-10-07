/* Lag en funksjon i C som reverserer en tekststreng. I C, så er en tekststreng representert med en 
tabell(array) av tegn (characters). Funksjonen skal manipulere tabellen(arrayet) slik at innholdet 
er reversert. Dersom funksjonen var kalt opp med tekststrengen "A string", så skal innholdet i 
tabellen(arrayet) være "gnirts A". 
Funksjonen skal ikke returnere noe. Du må manipulere strengen 
selv; det er ikke lov å bruke en innebygd funksjon (som strrev på windows).*/

#include <stdio.h>

int reverse_array(char *arr, int arrlen, char *rev_arr) {
    for (int i = 0; i < arrlen; i++) {
        int end_index =(arrlen - 1)-i;
        char tmp = arr[end_index];
        rev_arr[i] = tmp;
    }    
}

void printArray(char *arr, int length) 
{
    for (int i=0; i < length; i++){
        printf("%c", arr[i]);
    }
}

char word; // husker ikke ka æ sku brukke den for

int main() {
    int length = 11; 
    char mystring[] = "Hello World";
    char rev_arr[length + 1];  

    reverse_array(mystring, length, rev_arr);  
    
    

    printArray(rev_arr, length);  // Printer ut reverset lengde som er da manipulert som oppgaven ber om
    return 1;
}

//jeg flyttet den fra main.c til oblig3-3.c men nå er det noe feil fordi alle variablene ikke er gul lenger, de er kun grått.

//ferDIGG 