#include "testeDomain.h"
#include "domain.h"
#include <stdlib.h>
#include <assert.h>

void testCreeaza()
{
    Medicament* x = creeazaMedicament(123, "Paracetamol", 20, 400);
    assert(x != NULL);
    assert(x->cod == 123);
    assert(strcmp(x->nume, "Paracetamol") == 0);
    assert(abs(x->concentratie - 20)==0);
    assert(x->cantitate == 400);
    distrugeMedicament(x);
    Medicament* y = creeazaMedicament(124, "Paracetamol", 30, 450);
    assert(y != NULL);
    assert(y->cod == 124);
    assert(strcmp(y->nume, "Paracetamol") == 0);
    assert(abs(y->concentratie -30)==0);
    assert(y->cantitate == 450);
    distrugeMedicament(y);
}

void testValideaza()
{
    Medicament* x = creeazaMedicament(123, "", 12, 2);
    assert(x != NULL);
    assert(valideazaMedicament(x) == 0);
    distrugeMedicament(x);

    Medicament* y = creeazaMedicament(-123, "", -12, 2);
    assert(y != NULL);
    assert(valideazaMedicament(y) == 0);
    distrugeMedicament(y);

    Medicament* m = creeazaMedicament(123, "asxhas", 120, 2);
    assert(m != NULL);
    assert(valideazaMedicament(y) == 0);
    distrugeMedicament(m);

    Medicament* z = creeazaMedicament(120, "abc", 12, 2);
    assert(z != NULL);
    assert(valideazaMedicament(z) == 1);
    distrugeMedicament(z);

    Medicament* a = creeazaMedicament(120, "abc", 12, -2);
    assert(a != NULL);
    assert(valideazaMedicament(a) == 0);
    distrugeMedicament(a);

    Medicament* b = creeazaMedicament(120, "abc", -12, 2);
    assert(b != NULL);
    assert(valideazaMedicament(b) == 0);
    distrugeMedicament(b);
}

void testModificaNume()
{
    Medicament* x = creeazaMedicament(123, "Paracetamol", 12, 40);
    assert(x != NULL);
    modificaNume(x, "Nurofen");
    assert(strcmp(x->nume, "Paracetamol") != 0);
    assert(strcmp(x->nume, "Nurofen") == 0);
    modificaNume(x, "Decasept");
    assert(strcmp(x->nume, "Paracetamol") != 0);
    assert(strcmp(x->nume, "Nurofen") != 0);
    assert(strcmp(x->nume, "Decasept") == 0);
    distrugeMedicament(x);
}

void testModificaConcentratie()
{
    Medicament* x = creeazaMedicament(123, "Paracetamol",20, 40);
    modificaConcentratie(x, 30);
    assert(abs(x->concentratie-30)==0);
    modificaConcentratie(x, 40);
    assert(abs(x->concentratie - 40)==0);
    distrugeMedicament(x);
}

void testCopie()
{
    Medicament* x = creeazaMedicament(123, "Paracetamol", 20, 40);
    Medicament* y = copie(x);
    assert(x != y);
    assert(x->cod == y->cod);
    assert(strcmp(x->nume, y->nume) == 0);
    assert(x->concentratie == y->concentratie);
    assert(x->cantitate == y->cantitate);
    distrugeMedicament(x);
    distrugeMedicament(y);
}
void testeDomain()
{
    testCreeaza();
    testValideaza();
    testModificaNume();
    testModificaConcentratie();
    testCopie();
}