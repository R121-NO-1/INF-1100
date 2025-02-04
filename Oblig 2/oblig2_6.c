#include <stdio.h>



int main(void){ //funksjon for selve tverrsum regningen
int tall, summering; 

printf("sett inn et tall:" );
scanf("%d", &tall);

while (tall >=10){ //forsetter så lenge som det eksisterer noe på titallsplassen


//mellom område slik at vi kan få det til
    summering = 0; //hadde heller satt inn Sigma men det går ikke
    //her setter jeg summet til 0 for å 
        
        // her skjer Beregningen for summen av de sifrene som brukeren har talt på
        int tmp = tall; //gjør at tall er et midertlig tall som kan bli lekt med
        while (tmp > 0) { //dersom tallet er større enn null legger vi til 
            summering += tmp % 10;  // Legger til det siste sifferet av tmp  variablen til summering variablen
            tmp /= 10;        // Fjerner det siste sifferet
        } 

    tall = summering; 
    // setter tallet slik at det er tverrsummen

}
printf("Resultatet av tverrsummeringen er: %d\n", tall);

return 0; //slutter programmet slik at det ikke går igjen og igjen

}





