#pragma once

/// <summary>
/// Functia testeaza functia de creare a service-ului
/// </summary>
void testCreeazaService();

/// <summary>
/// Functia testeaza daca intr-adevar se returneaza lista de medicamente
/// </summary>
void testListaMed();

/// <summary>
/// Functia testeaza functia de cautare a unui medicament dupa cod
/// </summary>
void testCautaMedicament();

/// <summary>
/// Functia testeaza functia de adaugare a unui medicament in lista
/// </summary>
void testAdaugaMedicament();

/// <summary>
/// Functia testeaza functia de stergere a unui medicament dupa cod
/// </summary>
void testStergeMedicament();

/// <summary>
/// Functia testeaza functia de modificare a unui medicament
/// </summary>
void testModificaMedicament();

/// <summary>
/// Functia testeaza functia de creare a unei copii a listei de medicamente
/// </summary>
void testCreeazaCopieMed();

/// <summary>
/// Functia testeaza functia de comparare a doua medicamente dupa un anumit criteriu
/// </summary>
void testCompara();

/// <summary>
/// Functia testeaza functia de comparare a doua medicamente dupa un anumit criteriu, descrescator sau descrescator
/// </summary>
void testCompara2();

/// <summary>
/// Functia testeaza functia de validare a criteriilor pentru sortare
/// </summary>
void testValideazaCriterii();

/// <summary>
/// Functia testeaza functia de sortare a listei de medicamente
/// </summary>
void testSorteaza();

/// <summary>
/// Functia testeaza functia de sortare a listei de medicamente dar foloseste functia compara2 ca parametru
/// </summary>
void testSorteaza2();

/// <summary>
/// Functia testeaza functia de filtrare a listei de medicamente dupa cantitate
/// </summary>
void testFiltrareCantitate();

/// <summary>
/// Functia testeaza functia de filtrare a listei de medicamente dupa nume
/// </summary>
void testFiltrareNume();

/// <summary>
/// Functia apeleaza toate celelalte functii de test
/// </summary>
void testeService();