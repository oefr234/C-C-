#pragma once
//Cream tipul de data Medicament
typedef struct
{
	int cod;
	char* nume;
	int concentratie;//procentaj 
	int cantitate;
}Medicament;

/// <summary>
/// Functia este un constructor. Creeaza o variabila de tip Medicament* folosind date de intrare
/// </summary>
/// <param name="cod"> acesta reprezinta codul medicamentului
/// <param name="nume"> acesta reprezinta numele medicamentului
/// <param name="concentratie"> acesta reprezinta concentratia
/// <param name="cantitate"> acesta reprezinta cantitatea
/// <returns> returneaza o variabila de tipul Medicament*
Medicament* creeazaMedicament(int cod, char* nume, int concentratie, int cantitate);

/// <summary>
/// Functia valideaza datele introduse de utilizator
/// </summary>
/// <param name="x"> variabila de tip Medicament*
/// <returns> returneaza 0 daca datele sunt incorecte si 1 daca sunt corecte
int valideazaMedicament(Medicament* x);

/// <summary>
/// Functia modifica numele unui medicament
/// </summary>
/// <param name="x"> variabila de tip Medicament care va fi modificata</param>
/// <param name="newname">noul nume care urmeaza a fi atribuit lui x</param>
void modificaNume(Medicament* x, char* newname);

/// <summary>
/// Functia modifica concentratia unui medicament
/// </summary>
/// <param name="x"> variabila de tip medicament care va fi modificata</param>
/// <param name="newconc"> noua concentratie care urmeaza a fi atribuita lui x</param>
void modificaConcentratie(Medicament* x, int newconc);

/// <summary>
/// Functia creeaza o copie a medicamentului x
/// </summary>
/// <param name="x">Medicamentul a carui copie se va crea</param>
/// <returns>returneaza un alt obiect de tip Medicament care contine aceleasi date ca x</returns>
Medicament* copie(Medicament* x);

/// <summary>
/// Functia elibereaza spatiul ocupat de o variabila de tip Medicament*
/// </summary>
/// <param name="x">variabila de tip Medicament* al carui spatiu il dealocam
void distrugeMedicament(Medicament* x);






