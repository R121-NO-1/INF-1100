#include <stdio.h>
/*Oppgave 1
Lag en funksjon i C som tar 2 helltall som argumenter og bytter verdiene mellom disse
heltallene. Funksjonen skal ikke returnere noe. Endringene på heltallene skal også være
synlig/gyldige på utsiden av funksjonen.*/
int tall_a;
int tall_b; //global values    
    

void verdi_bytter(){ // value swapper function  
int temp_AtilB; 


 // Transfer logic
    temp_AtilB = tall_a;  // Store value of tall_a in temporary variable
    tall_a = tall_b;      // Assign value of tall_b to tall_a
    tall_b = temp_AtilB;  // Assign stored value of tall_a to tall_b
//really confusing 




}

void main(){

    printf("Sett inn verdien for tallet A: \n");
scanf("%d", &tall_a); //input av tallet A 
    printf("Sett inn verdien for tallet B: \n");
scanf("%d", &tall_b); //input av tallet B

printf("Før bytte: A = %d, B = %d \n", tall_a, tall_b );
// vanlig tall verdien og hva det er
verdi_bytter(); // runner funksjonen
printf("\nFunction request sent:\n "); // smal segregation bit for easier reading capabilties


printf("\n Etter bytte: A= %d, B = %d \n", tall_a, tall_b); 
//obvi etter bytte burde tallet være annerledes 

//this should function if it doenst then im losing my mind 
}