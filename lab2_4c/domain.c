#define _CRT_SECURE_NO_WARNINGS
#include "domain.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

Medicament* creeazaMedicament(int cod, char* nume, int concentratie, int cantitate)
{
    Medicament* element = (Medicament*)malloc(sizeof(Medicament));
    if (!element) return NULL; // Verificare alocare
    int size_t = strlen(nume)+1;
    element->nume = malloc(size_t * sizeof(char));
    strcpy(element->nume, nume);

    element->cod = cod;
    element->concentratie = concentratie;
    element->cantitate = cantitate;
    return element;
}


int valideazaMedicament(Medicament* x)
{
    if (x->cod <= 0)
        return 0;
    if (x->nume == NULL || strlen(x->nume) == 0)
        return 0;
    if (x->concentratie < 0 ||  x->concentratie>100)
        return 0;
    if (x->cantitate < 0)
        return 0;

    return 1;
}
void modificaNume(Medicament* x,char *newname)
{
    int size_t = strlen(newname)+1;
    free(x->nume);
    x->nume = (char*)malloc(size_t * sizeof(char));
    strcpy(x->nume, newname);
}

void modificaConcentratie(Medicament* x, int newConc)
{
    x->concentratie = newConc;
}

Medicament* copie(Medicament* x)
{
    Medicament* y = creeazaMedicament(x->cod, x->nume, x->concentratie, x->cantitate);
    return y;
}

void distrugeMedicament(Medicament* x)
{
    free(x->nume);
    free(x);
}
