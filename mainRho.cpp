#include<iostream>   // Inclusione della libreria per input/output standard (es. cout, cin)
#include<cstring>    // Inclusione della libreria per la gestione delle stringhe C-style (non usata qui direttamente, ma spesso necessaria in programmi più complessi)

#include "CRhombus.h" // Inclusione del file di intestazione della classe Rhombus

using namespace std;  // Per evitare di dover scrivere std:: davanti a ogni elemento della STL (es. std::cout -> cout)

int main() {

    // Creazione di tre oggetti di tipo Rhombus usando diversi costruttori
    Rhombus rhoA(4,1); // Costruttore parametrico: diagonale maggiore = 4, diagonale minore = 1
    Rhombus rhoB(4,2); // Costruttore parametrico: diagonale maggiore = 4, diagonale minore = 2
    Rhombus rhoC=rhoA; // Costruttore di copia: rhoC copia i valori da rhoA

    cout << endl;
    cout << "rhombus A" << endl;
    rhoA.Dump(); // Stampa tutte le informazioni dell’oggetto rhoA (diagonali, lato, perimetro, area)

    cout << endl;    
    cout << "rhombus B" << endl;
    rhoB.Dump(); // Stampa tutte le informazioni dell’oggetto rhoB

    cout << endl;    
    cout << "rhombus C" << endl;
    rhoC.Dump(); // Stampa tutte le informazioni dell’oggetto rhoC (attualmente uguale ad A)

    // Assegnazione: rhoC prende i valori di rhoB (usa operator=)
    rhoC = rhoB;

    // Confronto tra rhoC e rhoB: dovrebbe risultare vero, perché abbiamo appena assegnato rhoB a rhoC
    if (rhoC == rhoB) 
        cout<< "B e C sono uguali" << endl;
    else 
        cout<< "B e C sono diversi" << endl;

    // Confronto tra rhoC (ora uguale a B) e rhoA: dovrebbe risultare falso
    if (rhoC == rhoA) 
        cout<< "A e C sono uguali" << endl;
    else 
        cout<< "A e C sono diversi" << endl;

    // Impostazione delle stesse dimensioni per rhoC e rhoA (entrambe 9 e 2)
    rhoC.SetDim(9,2);
    rhoA.SetDim(9,2);

    // Confronto tra rhoC e rhoA: ora dovrebbero essere uguali
    if (rhoC == rhoA) 
        cout<< "A e C sono uguali" << endl;
    else 
        cout<< "A e C sono diversi" << endl;

    return 0; // Termine del programma con codice di uscita 0 (successo)

}
