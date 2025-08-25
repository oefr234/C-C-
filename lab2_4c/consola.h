#pragma once
#include "service.h"
typedef struct
{
	ServiceMed* service;
}UI;

/// <summary>
/// Cream obiect de tipul UI*:  consola
/// </summary>
/// <returns>obiect de tip UI* sau NULL daca nu s-a creat</returns>
UI* creeazaUI();

/// <summary>
/// Functia afiseaza utilizatorului posibilele optiuni
/// </summary>
void print_menu();

/// <summary>
/// Functia efectueaza afisarea unui medicament
/// </summary>
/// <param name="x"> variabila de tip Medicament*
void afiseazaMedicament(Medicament* x);

/// <summary>
/// Functia se ocupa cu adaugarea unui element in service
/// </summary>
/// <param name="consola">obicet de tip UI*</param>
void adaugaUI(UI* consola);

/// <summary>
/// Functia se ocupa cu stergerea unui element din service
/// </summary>
/// <param name="consola">obicet de tip UI*</param>
void stergeUI(UI* consola);

/// <summary>
/// Functia se ocupa cu modificarea unui element din service
/// </summary>
/// <param name="consola">obiect de tip UI*</param>
void modificaUI(UI* consola);

/// <summary>
/// Functia se ocupa cu afisarea listei de medicamente sortate dupa anumite criterii, fara a o modifica
/// </summary>
/// <param name="consola">obiect de tip UI*</param>
void sortareUI(UI* consola);

/// <summary>
/// Functia se ocupa cu afisarea unor medicamente care sunt mai mici decat o cantitate introdusa de utiizator
/// </summary>
/// <param name="consola">obiect de tip UI*</param>
void filtreazaCantitateUI(UI* consola);

/// <summary>
/// Functia se ocupa cu afisarea unor medicamente a caror nume incepe cu un caracter dat de utilizator
/// </summary>
/// <param name="consola">obiect de tip UI*</param>
void filtreazaNumeUI(UI* consola);

/// <summary>
/// Functia ruleaza programul
/// </summary>
/// <param name="consola">obiect de tip UI*</param>
void run(UI* consola);

/// <summary>
/// Functia dealoca spatiul care fusese alocat obiectului de tip UI*
/// </summary>
/// <param name="consola">obiectul care va fi sters din memorie</param>
void distrugeUI(UI* consola);
