#include <stdio.h>
#include <math.h> //slik som hintet ber om setter jeg inn math.h

double planetPunktRegner(double x1, double y1, double x2, double y2)
{
    // lage funksjon for bruk i main seinere samme konvensjon som sist gang
    double x = x1 - x2;
    double y = y1 - y2;
    double x_2 = x*x;
    double y_2 = y*y;
    double sum = x_2 + y_2;
    double val = sqrt(sum);
    return val;
    
     /*sqrt er square root
 vi trenger ikke pow i denne funksjonen 
 siden vi ikke har større enn 2 på grunn av dette gjør 
 vi ting lett for oss selv samt også gjør ting mer oversiktlig 
 ved å gjøre et operasjon per linje
 da har vi formelen klar nå er 
 det bare å bruke selve greia etter å kalle på funksjonen
*/

}
int main (void) /*deklarerr et gitt sted for funksjonen til å ta plass, 
så deklarer variablene som vi vil bruke i følgende print og scan spørsmålet
*/

{
 // jeg har litt "flavor text" for å ikke gjøre det gorr kjedelig samt også et pil som viser fra punkt A til B
 printf("Dette er PlanetPunktRegner et funksjon programmert i C for å programmere hva som er distansen mellom punkt A og B");
 printf("A\n");
     printf("    ========>\n");
     printf("             ========>\n");
     printf("                      ========>\n");
     printf("                               ========> B\n");
 
 double x1, y1, x2,y2; 
 /* for å gjøre ting lett kopierer jeg printf 
 kommandoen og erstatter det jeg ikke trenger */
 
 printf("Skriv inn x koordinatet til punkt A\n");
 
 scanf("%lf",&x1); /*%lf deklarerer for å innta double point verdier og 
  &x1 vil si inni i variablen x1 */ 
 //nå skanner jeg for det jeg vil ha gjennom de forskjellige spørsmålene
 
 printf("Skriv inn y koordinatet til punkt A\n");
 // jeg har satt \n for å lage mer mellomrom mellom linjene og input stedet for brukeren.
 scanf("%lf",&y1);
 
 
 printf("Skriv inn x koordinatet til punkt B\n");
 scanf("%lf",&x2);
 printf("Skriv inn y koordinatet til punkt B\n");
 scanf("%lf",&y2);
/*satt gitt inn verdier inni formelen slik at vi får et gjengittsvar som kan bli satt 
 inni planetPunktRegner funksjonen.*/


double gjengittSvar = planetPunktRegner(x1,y1,x2,y2); //nå er svaret beregnet, men vi trenger et til print funksjon
printf(".2f:\t%.2f\n", gjengittSvar);
printf("lf:\t%lf\n", gjengittSvar); //lf gir flere sifre/desimaltall, mens %.2f er rundet oppover
// her gir vi to svar med annet mengde sifre. 
}