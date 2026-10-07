#include <stdio.h>




void konverterer(float kilogram, int valg){
float resultat; 
switch (valg) { //jeg synes switch er mer oversiktlig enn mange if løkker

        case 1:
            // Konvertering til Centner
            resultat = kilogram * 0.01;
            printf("%.2f kilogram tilsvarer %.2f centner\n", kilogram, resultat);
            break;
        case 2:
            // Konvertering til Newton
            resultat = kilogram * 9.8;
            printf("%.2f kilogram tilsvarer %.2f newton\n", kilogram, resultat);
            break;
        case 3:
            // Konvertering til Karat
            resultat = kilogram * 5000;
            printf("%.2f kilogram tilsvarer %.2f karat\n", kilogram, resultat);
            break;
        default:
            printf("Ugyldig valg. Vennligst prøv igjen.\n");
            break;
    }

}





int main() {
    float kilogram;
    int valg;
    int ny_konvertering; //brukeren har mulighet til å runne flere konverteringer om gangen.

    printf("Her konverteres det enheter ved bruk av Kilogram, til mulighetene som er, center, newton, eller karat.\n");

    do {
        printf("Hvor mange kilogram ønsker du å konvertere? ");
        scanf("%f", &kilogram);

        printf("Hva ønsker du å konvertere til, 1 for Centner, 2 for Newton og 3 for Karat? ");
        scanf("%d", &valg);

        konverterer(kilogram, valg);

        printf("Ønsker du å gjøre en ny konvertering, 1 for ja og andre tegn for nei? ");
        scanf("%d", &ny_konvertering);

    } while (ny_konvertering == 1);

    printf("Progam avslutt");
    return 0; //avslutt programmvaren
}
