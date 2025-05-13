/// \file CRhombus.cpp
///	\brief class Rhombus: implementation of the functions
///
///	Details.
///

#include<iostream>  // Libreria per input/output standard
#include<cmath>     // Libreria per funzioni matematiche (es. sqrt)
#include "CRhombus.h" // Inclusione del file di intestazione della classe Rhombus

using namespace std;

/// @brief default constructor 
//Implementazione costruttore di deafault
Rhombus::Rhombus() {

	cout << "Rhombus - constructor - default" << endl;

	Init(); // Inizializzazione standard dell'oggetto con valori predefiniti
}

/// @brief constructor 
/// @param dL diagonal (longer)
/// @param dS diagonal (shorter)
// Implementazione costruttore parametrico (by value)
Rhombus::Rhombus(float dL, float dS) {

	Init(); // Inizializzazione standard dell'oggetto con valori predefiniti

	cout << "Rhombus - constructor" << endl;

	// Se i valori sono non validi, stampa un warning e assegna zero alle dimensioni
	if (dL <= 0. || dS <= 0.) {
		WarningMessage("constructor: diagonals should be > 0");  
		SetDim(0,0);
	}
	else
		SetDim(dL,dS);

}

/// @brief destructor 
// Implementazione distruttore
Rhombus::~Rhombus() {

	cout << "Rhombus - destructor" << endl;
	Reset(); // Reset dell'oggetto
}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
// Implementazione costruttore di copia
Rhombus::Rhombus(const Rhombus &r) { 

	cout << "Rhombus - copy constructor" << endl;

	Init(r); // Inizializzazione come copia dell’oggetto fornito 
}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
// Implementazione operatore di assegnazione
Rhombus& Rhombus::operator=(const Rhombus &r) { 

	cout << "Rhombus - operator =" << endl;

	Init(r);// Inizializzazione come copia dell’oggetto fornito 
	
	return *this; // Restituisce il riferimento all’oggetto corrente
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
// Implementazione operatore di confronto
bool Rhombus::operator==(const Rhombus &r) { 

	// Controlla se entrambe le diagonali sono uguali
	if (r.diagL == diagL && r.diagS == diagS)
		return true;
		
	return false; //Altrimenti restituisce 0 ("false")
}

/// @brief default initialization of the object
//Implementazione inizializzazione standard
void Rhombus::Init() {
	
	SetDim(0,0); // Inizializza le diagonali a 0
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
//Implementazione inizializzazione di copia di un oggetto rombo (come copia di un altro oggetto rombo)
void Rhombus::Init(const Rhombus &r) {

	Init(); //Inizializzazione standard impostanfo valori a 0
	SetDim(r.diagL,r.diagS); // Copia le dimensioni

}

/// @brief total reset of the object  
//Implementazoine reset completo
void Rhombus::Reset() {
	
	SetDim(0,0); // Azzera dimensioni
}


/// @brief set longer diagonal of the object
/// @param d diagonal 
// Implementazione setter diagonale maggiore
void Rhombus::SetDiagL(float d) {

	// Se il valore è non valido, stampa un warning e annulla operazione
	if (d < 0.) {
		WarningMessage("SetDiagL: diagonal should be > 0");
		return;
	}

	SetDim(d,diagS); // Imposta la diagonale maggiore mantenendo l'altra invariata
} 

/// @brief set shorter diagonal of the object
/// @param d diagonal 
// Implementazione setter diagonale minore
void Rhombus::SetDiagS(float d) {

	// Se il valore è non valido, stampa un warning e annulla operazione
	if (d < 0.) {
		WarningMessage("SetDiagS: diagonal should be > 0");
		return;
	}

	SetDim(diagL,d); // Imposta la diagonale minore mantenendo l'altra invariata
}


/// @brief get longer diagonal of the object
/// @return longer diagonal 
// Implementazione getter diagonale maggiore
float Rhombus::GetDiagL() {

	return diagL; // Restituisci la diagonale maggiore
}

/// @brief get shorter diagonal of the object
/// @return shorter diagonal 
// Implementazione getter diagonale minore
float Rhombus::GetDiagS() {

	return diagS; // Restituisci la diagonale minore
}

/// @brief get side of the object
/// @return side 
// Implementazione getter diagonale lati del rombo
float Rhombus::GetSide() {
	
	// Calcolo del lato usando il teorema di Pitagora:
	// lato = sqrt((dL/2)^2 + (dS/2)^2)
	return sqrt(diagL*diagL/4. + diagS*diagS/4.);
}

/// @brief set the diagonals of the object
/// @param dL longer diagonal  
/// @param dS shorter diagonal
// Implementazione setter dimensioni complete (diagonale maggiore e minore)
void Rhombus::SetDim(float dL, float dS) {

	diagL = dL; // Assegna la diagonale maggiore
	diagS = dS;  // Assegna la diagonale minore
	
	return;
}

/// @brief get the diagonals of the object
/// @param dL larger diagonal 
/// @param dS shorter diagonal
// Implementazione getter dimensioni complete (diagonale maggiore e minore) (by reference)
void Rhombus::GetDim(float &dL, float &dS) {

	dL = diagL; // Restituisce la diagonale maggiore per riferimento
	dS = diagS; // Restituisce la diagonale minore per riferimento
	
	return;
}

/// @brief computes the area of the object
/// @return the area 
//Implementazione caloclo dell'area
float Rhombus::GetArea() {
	
	// Formula dell’area: (D * d) / 2
	return (diagL*diagS/2.);
}

/// @brief computes the perimeter of the object
/// @return the perimeter 
//Implementazione caloclo del perimetro
float Rhombus::GetPerimeter() {
	// Perimetro = 4 * lato
	return (4*GetSide());
}



/// @brief write an error message 
/// @param string message to be printed
// Stampa messaggio di errore (stampa il contenuto di una stringa che gli passo dalle altre funzioni)
void Rhombus::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Rhombus --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
// Stampa messaggio di avviso (stampa il contenuto di una stringa che gli passo dalle altre funzioni)
void Rhombus::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Rhombus --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
//Stampa tutte le informazioni dell'oggetto
void Rhombus::Dump() {
	cout << endl;
	cout << "---Rhombus---" << endl; 
	cout << endl;
	
	cout << "Longer diagonal = " << diagL << endl;
	cout << "Shorter diagonal = " << diagS << endl; 
	cout << "Side = " << GetSide() << endl; 
	cout << "Perimeter = " << GetPerimeter() << endl; 
	cout << "Area = " << GetArea() << endl;
	
	
	cout << endl;

}
