/*! \file CRhombus.h
	\brief Declaration of the class Rhombus

	Details.
*/

//GUARDIA --> per evitare doppie inclusioni
#ifndef RHOMBUS_H
#define RHOMBUS_H


/// @class Rhombus
/// @brief to manage an object with the shape of a rhombus
//Definizione della classe rombo
class Rhombus 
{
private:
	float diagL;  // Diagonale maggiore del rombo
    float diagS;  // Diagonale minore del rombo
	

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Rhombus(); // Costruttore di default: inizializza le diagonali con valori predefiniti (es. 0)
	Rhombus(float dL, float dS); // Costruttore parametrico: inizializza con valori specificati dall'utente
	Rhombus(const Rhombus &r); // Costruttore di copia: crea un nuovo oggetto copiando i valori da un altro rombo (by reference)
	
	~Rhombus(); // Distruttore: viene chiamato automaticamente alla distruzione dell'oggetto
	/// @}
	
	/// @name OPERATORS
	/// @{
	Rhombus& operator=(const Rhombus &r); // Operatore di assegnazione: permette di assegnare un rombo a un altro
	bool operator==(const Rhombus &r);  // Operatore di uguaglianza: confronta se due rombi hanno le stesse diagonali
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init(); // Inizializza le diagonali a valori predefiniti (es. 0)										
	void Init(const Rhombus &r); // Inizializza questo oggetto copiando i valori da un altro rombo (by reference)
	void Reset(); // Reimposta lo stato del rombo (es. azzera le diagonali)							
	/// @}
	
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetDiagL(float d); // Imposta la diagonale maggiore
	void SetDiagS(float d); // Imposta la diagonale minore
	void SetDim(float dL, float dS); // Imposta entrambe le diagonali contemporaneamente
		
	void GetDim(float &dL, float &dS); // Restituisce le due diagonali tramite parametri di riferimento (by reference)
	float GetDiagL(); // Restituisce la diagonale maggiore
	float GetDiagS(); // Restituisce la diagonale minore
	float GetPerimeter(); // Calcola e restituisce il perimetro del rombo
	float GetArea(); // Calcola e restituisce l'area del rombo
	float GetSide(); // Calcola e restituisce la lunghezza del lato del rombo
	/// @}
	
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); // Stampa un messaggio di errore
	void WarningMessage(const char *string); // Stampa un messaggio di avviso
	void Dump(); // Stampa lo stato interno dell'oggetto rombo
	/// @}
		
};

#endif // RHOMBUS_H