#include <stdio.h> 
/*Lag en funksjon som skriver ut tall i et gitt område, sammen med en indikasjon
om tallet er oddetall 
eller partall, og om et annet tall er faktor i tallet. */


/*en fortalte meg at for at jeg skal være en god programererer, 
så må jeg ha så lett kode at det forklarer seg selv.*/


void sjekk_tall(int start, int slutt, int faktor){ //funksjon deklarasjon
    for (int i = start; i <= slutt; i++){ // denne funksjonen leter etter tallene i main funksjonen
        
        // char oddetall = 0;
        // char partall = 0;
        // char faktor = 0;
        
        if ((i % 2) == 0){ //hvis resten er 0 så er det partall, dersom det er annet da er det oddetall.
            // partall
            printf("%d er partall", i);
        }
        else{
            printf("%d er oddetall", i);
            // oddetall
        }
        
        if (i % faktor == 0){ //hvis resten er null da er det faktor
            // faktor
        printf(", og %d er en faktor av %d", faktor, i);
        }
        else{
//for klaritet la jeg til "ikke faktor" for å forvirre for mye med alle bokstavene
            printf(", og %d er ikke en faktor av %d", faktor,i);
            // printf("IKKE FAKTOR"); denne vises ikke vet ikke hvorfor. 
            printf("\n");
        } //som oppgaven spør, printes det ut dersom det ikke er faktor, som ikke faktor.
printf(".\n"); //hver gang løkken går igjen vil det printes ut på en ny linje
    }
}


// int side(void){
// char svar; //hvis du som lærer vil ha spesefikke verdier her kan du velge de 
// printf("Vil du ha egne tall eller vil du ha besluttet tall som var her fra før av?");
// scanf("%c", &svar );

// switch(svar){
//     case 'y':
//     case 'Y': //denne tåler både stor Y og liten Y
//     printf("Du valgte ja");

// }
// } 
/* jeg ville ha en system som lar læreren velge hvilken som helst variabler,
 men det tar alt for mye arbeid før de 2 oppgavene igjen */









int main(void)  //gitt sted.
{

    
int start = 0, slutt = 30, faktor = 6;
// det var ingen regel over hva tallene skulle være, så jeg valgte disse
    sjekk_tall(start, slutt, faktor); // så må vi selvfølgelig kalle på funksjonen
    // men den sliter med å forstå at det er noe der. 




}