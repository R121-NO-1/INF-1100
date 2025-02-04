/* Lag en funksjon i C som beregner gjennomsnittet av en tabell(array) med heltall, hvor det minste 
tallet og det største tallet er tatt bort. Tabellen(arrayet) er ikke sortert. 
F.eks. [3,5,2,8,1] vil gi gjennomsnittet 3.333....*/

#include <stdio.h>
//eksempel array
// int array[5] = {3,5,9,4,6};  // trenger ikke å være sortert





double gjennomsnitt(int arr[], int størrelse) {
    int sum = 0;
    int min = arr[0];
    int max = arr[0];

    // Finn summen, og samtidig finn min og max
    for (int i = 0; i < størrelse; i++) {
        sum += arr[i];
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Fjern min og max fra summen
    sum -= min;
    sum -= max;

    // Returner gjennomsnittet, del på (størrelse - 2) siden vi har fjernet 2 elementer
    return (double) sum / (størrelse - 2);
}

int main() {
    int array[] = {1, 3, 5, 6, 9}; // Eksempel på array
    int størrelse = sizeof(array) / sizeof(array[0]); // Beregn størrelsen på arrayet

    double resultat = gjennomsnitt(array, størrelse); // Kall funksjonen
    printf("Gjennomsnittet er: %.2f\n", resultat); // Skriv ut resultatet

    return 0;
}
/* prosessen er altså da: 3+1+6+5+9=sum=24
24-1-9=14
resten av tallene som er igjen i array et ,,{3,6,5}

da blir gjennomsnittet regnet ut


(14)/(3)=4,67


uansett rekkefølga i arrayet blir det funnet, minimum og maksimum i arrayet som fjernes og da
regner gjennomsnittet av resten av tallene, som i denne tilfellen viser til å være,

3,6,5.

FERDIGg
*/