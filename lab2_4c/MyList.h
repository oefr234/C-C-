#pragma once
#include "domain.h"  // Assuming Medicament is defined in domain.h

// We no longer use `void*` as the element type, but specifically `Medicament*`.
typedef Medicament* ElemType;

typedef struct
{
    ElemType* med;
    int dim;
    int cp;
} List;

/// <summary>
/// Functia creeaza si returneaza o lista vida
/// </summary>
/// <returns>o lista vida daca e totul in regula sau NULL daca nu s-a creat</returns>
List* creeazaListaVida();

/// <summary>
/// Functia dubleaza capacitatea listei
/// </summary>
/// <param name="l">lista de medicamente de tip List*</param>
/// la final: l->cp :=2*l->cp
void redimensionare(List* l);

/// <summary>
/// Functia adauga la sfarsitul listei un element
/// </summary>
/// <param name="x">de tip Medicament*, elementul care va fi adaugat la sfarsitul listei</param>
/// <param name="l">de tip List*, lista in care se va adauga elementul</param>
/// la final: dimenisunea listei va creste cu 1
void adaugaSfarsit(ElemType x, List* l);

/// <summary>
/// Functia sterge un medicament de pe o anumita pozitie
/// </summary>
/// <param name="poz">parametru de tip int,unde poz se afla in intervalul [0,l->dim]</param>
/// <param name="l">parametru de tip List*,lista de medicamente</param>
/// la final l->dim :=l->dim-1
void stergePoz(int poz, List* l);

/// <summary>
/// Functia distruge o lista
/// </summary>
/// <param name="l">de tip List*, lista care va fi distrusa</param>
void distrugeLista(List* l);
