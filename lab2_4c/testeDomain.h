#pragma once

/// <summary>
/// Functia testeaza daca un medicament a fost creat corect (testam functia creeazaMedicament)
/// </summary>
void testCreeaza();

/// <summary>
/// Functia testeaza functia de validare a datelor introduse (testam functia valideazaMedicament)
/// </summary>
void testValideaza();

/// <summary>
/// Functia testeaza functia care modifica numele unui medicament (testam functia modificaNume) 
/// </summary>
void testModificaNume();

/// <summary>
/// Functia testeaza functia care modifica concentratia unui medicament (testam functia modificaConcentratie) 
/// </summary>
void testModificaConcentratie();

/// <summary>
/// Functia testeaza functia de creare a unei copii la un medicament
/// </summary>
void testCopie();

/// <summary>
/// Functia ruleaza toate testele pentru domain
/// </summary>
void testeDomain();