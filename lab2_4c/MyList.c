#include <malloc.h>
#include "MyList.h"

List* creeazaListaVida()
{
    List* lista = (List*)malloc(sizeof(List));
    if (lista)
    {
        lista->dim = 0;
        lista->cp = 1;
        lista->med = (ElemType*)malloc(sizeof(ElemType) * lista->cp);
        return lista;
    }
    return NULL;  // Return NULL if allocation fails
}

void redimensionare(List* l)
{
    ElemType* newv = (ElemType*)malloc(2 * l->cp * sizeof(ElemType));
    if (newv)
    {
        // Copy all elements from the old array to the new array
        for (int i = 0; i < l->dim; i++)
            newv[i] = l->med[i];

        l->cp *= 2;
        free(l->med);
        l->med = newv;
    }
}

void adaugaSfarsit(ElemType x, List* l)
{
    if (l->cp == l->dim)
        redimensionare(l);
    l->med[l->dim++] = x;
}

void stergePoz(int poz, List* l)
{
    distrugeMedicament(l->med[poz]);  // Assuming this function frees the medicament memory
    for (int i = poz; i < l->dim - 1; i++)
        l->med[i] = l->med[i + 1];
    l->med[l->dim - 1] = NULL;  // Prevent accidental access to an invalid pointer
    l->dim--;
}

void distrugeLista(List* l)
{
    for (int i = 0; i < l->dim; i++)
        distrugeMedicament(l->med[i]);  // Free each Medicament in the list
    free(l->med);
    free(l);
}
