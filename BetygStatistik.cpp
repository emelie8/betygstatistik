/* 
Applikation: BetygStatistik
Skapad av: Emelie Johansen
Skapad: 2021-12-07
Version: 1.0.0
*/

/*
Detta program läser in betyg för ett antal ämnen som ligger sparade i en array.
Därefter omvandlas poängbetygen till bokstavsbetyg enligt bestämda regler.
En metod finns också för att skriva ut alla betyg som har lagrats i arrayerna.
Slutligen skrivs lite statistik ut som visar den totala betygspoängen, medelvärdet
och en kommentar från dator hur bra medelvärdet är. 
*/

#include <iostream>
#include <vector>

using namespace std;

// Metod för att läsa in betyg i alla ämnen
void lasPoang(string amnen [], int poang [], int n){

   // Metoden tar med sig arrayerna ämnen och string
   int poangen;

   // for loop för att stega igenom arrayen med alla ämnen och skapa en ny array
   // med alla poängbetyg som användaren får mata in
   for (int i = 0; i < n; i++){
        cout << "Mata in poängen mellan 0-100 för " << amnen[i] << ": ";
        cin >> poangen;
        poang[i] = poangen;
   }
}

// Metod för att omvandla sifferbetyg till bokstavsbetyg enligt följande regler
// 90 < poäng <= 100 = 'A'
// 80 < poäng <= 90 = 'B'
// 70 < poäng <= 80 = 'C'
// 60 < poäng <= 70 = 'D'
// 50 <= poäng <= 60 = 'E'
// poäng <= 50 = 'F'

void omvandlaBetyg(string amnen [], int poang [], int n, char betyg []) {

    // Gå igenom arrayen med poäng och skapa motsvarande betyg i en ny array
    for (int i = 0; i < n; i++) {
        if (poang[i] > 90) {
            betyg[i] = 'A'; 
        } else if (poang[i] > 80) {
            betyg[i] = 'B';
        } else if (poang[i] > 70) {
            betyg[i] = 'C';
        } else if (poang[i] > 60) {
            betyg[i] = 'D';
        } else if (poang[i] > 50) {
            betyg[i] = 'E';
        } else {
            betyg[i] = 'F';
        }
    }
}

// Metod för att skriva ut alla betyg i alla ämnen    
void skrivUtBetyg(string amnen [], int poang [], int n, char betyg []) {

    // Skriv ut betygen vi har lagrat i våra arrayer
    for (int i = 0; i < n; i++) {
        cout << "\n" << betyg[i] << " - " << poang[i] << " i " << amnen[i];
    }
    cout << "\n";
}

// Metod för att skriva ut betygstatistik och en utvärdering av medelbetyget
void Statistik(string amnen [], int poang [], int n, char betyg []) {

    // Räkna ihop alla bokstavsbetyg för varje bokstav
    // Alltså hur många A, hur många B, hur många C osv
    // Vi skapar en array där vi kan lagra detta
    int betygAntal[5];

    // Skapa en variabel där vi räknar ihop totala betygspoängen
    int totBetyg = 0;

    // Nollställ alla värden i arrayen där antal betyg lagras
    for (int i = 0; i < n+1; i++) {
        betygAntal[i] = 0;
    }

    // for loop där vi skapar en array som håller reda på hur många 
    // bokstavsbetyg av varje sort vi har
    for (int i = 0; i < n; i++){
        switch (betyg[i]) {
            case 'A':
                betygAntal[0]++;
                break;
            case 'B':
                betygAntal[1]++;
                break;
            case 'C':
                betygAntal[2]++;
                break;
            case 'D':
                betygAntal[3]++;
                break;
            case 'E':
                betygAntal[4]++;
                break;
            case 'F':
                betygAntal[5]++;
                break;
            default:
                cout << "Felaktigt betyg hittat i arrayen! Avbryter...";
                break;
        }
    }

    // Skriv ut antalet av alla betyg
    cout << "\nAntal betyg 'A': " << betygAntal[0];
    cout << "\nAntal betyg 'B': " << betygAntal[1];
    cout << "\nAntal betyg 'C': " << betygAntal[2];
    cout << "\nAntal betyg 'D': " << betygAntal[3];
    cout << "\nAntal betyg 'E': " << betygAntal[4];
    cout << "\nAntal betyg 'F': " << betygAntal[5];

    // Räkna ihop alla betygspoäng
    for (int i = 0; i < n; i++){
        totBetyg = totBetyg + poang[i];
    }

    // Skriv ut totala betygspoängen
    cout << "\n\nDen totala betygspoängen är: " << totBetyg << " poäng.\n\n";

    // Skriv ut medelbetyget
    cout << "Medelbetyget är: " << (totBetyg / n) << " poäng.\n\n";

    // Skriv ut en kommentar beroende på hur bra medelbetyget är
    if(totBetyg / n > 90) {
        cout << "Riktigt bra betyg!!! Ett framtida geni?";
    } else if (totBetyg / n > 75) {
        cout << "Ojdå! Det var inga dåliga betyg!";
    } else if (totBetyg / n > 50) {
        cout << "Bra betyg! Över medel!";
    } else if (totBetyg / n > 30) {
        cout << "Nja... Lite bättre borde det kunna vara. Kämpa på!";
    } else {
        cout << "Hmm... Inga höjdarbetyg direkt. Ryck upp dig!!!";
    }

    cout << "\n\n";
} // Slut på statistik()


int main(void){

    // Skapa arrayer för ämnen, poängbetyg och bokstavsbetyg
    string amnen [5] = {"Matematik","Svenska","Engelska","Historia","Fysik"};
    int poang [5];
    char betyg[6];

    // Skapa variabel som ska innehålla antalet ämnen
    int antal = 0;

    // Ta reda på storleken på array 'amnen'
    for(string s: amnen)
        antal++;

    // Rensa skärmen
	cout << "\033[2J\033[1;1H";

    // Skriv ut ett välkomstmeddelande
	cout << "\n\nHej och välkommen till BetygStatistik!\n\n";

    // Anropa metod för att läsa in poängen
    lasPoang(amnen, poang, antal);

    // Anropa metod för att omvandla numeriska poäng till bokstavspoäng
    omvandlaBetyg(amnen, poang, antal, betyg);

    // Anropa metod för att skriva ut alla betyg
    skrivUtBetyg(amnen, poang, antal, betyg);

    // Anropa metod för att skriva ut statistik för alla betyg
    Statistik(amnen, poang, antal, betyg);

    // Returnera alltid siffran 0
    // Framtida versioner kan tänkas returnera andra siffror 
    // beroende på vad som händer i programmet, t.ex. felkoder
    return 0;
}

/* 
Utvärdering

I arbetet med den här uppgiften lärde jag mig mycket om arrayer och hur man kan använda 
dessa för att lagra olika typer av datavärden. Det var också intressant att skapa egna
metoder för att lägga till och skriva ut värden till/från arrayerna.

Jag fick också möjlighet att använda mina tidigare kunskaper från tidigare inlämningsuppgifter
som t.ex. for-loopar, switch-satser etc.

Användarvänligheten i programmet är hög och enkel att förstå.

Problemet med applikationen är att ingen data lagras på disk utan endast finns medan man kör 
programmet. Detta gör att betygsarrayerna blir nollställda varje gång man startar programmet.
I en riktig applikation skulle alla arrayer sparas i en databas på disk och på så sätt byggas
upp med mer och mer data.

Framtida versioner bör också kompletteras med robusta felkontroller som kontrollerar alla
inmatningar användaren gör innan variablarna används i simulatorn. Oväntade fel behöver
också fångas upp och hanteras på ett snyggt sätt så att informativa felmeddelanden skrivs
ut på skärmen.
*/

