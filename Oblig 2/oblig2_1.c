#include <stdio.h>


void triangel(char tegn, int antall_linjer);

int main() {
int gay = 5;
    triangel('*', 5); // passing a character instead of a string
    return 0; 
}

void triangel(char tegn, int antall_linjer) { // custom function declared
    for(int i = 1; i <= antall_linjer; i++) { // outer loop for "rows"
        for(int j = 1; j <= i; j++) { // inner loop for "columns"
            printf("%c", tegn); // print the character
        }
        printf("\n"); // move to the next line after each row
    }
}