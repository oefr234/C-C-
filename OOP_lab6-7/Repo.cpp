#include "Repo.h"
#include <iostream>

// Adaugă o mașină nouă, dar nu permite duplicat (după număr de înmatriculare)
void Repo::store(const Masina& m) {
    for (int i = 0; i < masini.dim(); ++i) {
        if (masini[i].getNumarInmatriculare() == m.getNumarInmatriculare()) {
            throw RepoExceptions("Masina deja exista!");
        }
    }
    masini.adaugaSfarsit(m);
}

const VectorDinamic<Masina>& Repo::getAll() const {
    return masini;
}

int Repo::cauta(const string& nrInmatriculare) const {
    for (int i = 0; i < masini.dim(); ++i) {
        if (masini[i].getNumarInmatriculare() == nrInmatriculare)
            return i;
    }
    return -1;
}

void Repo::update(int index, const string& modelNou, const string& categorieNoua, bool inchiriataNoua) {
    if (index < 0 || index >= masini.dim()) {
        throw RepoExceptions("Index invalid pentru update!");
    }
    masini[index].setModel(modelNou);
    masini[index].setCategorie(categorieNoua);
    masini[index].setInchiriata(inchiriataNoua);
}

void Repo::remove(int index) {
    if (index < 0 || index >= masini.dim()) {
        throw RepoExceptions("Index invalid pentru stergere!");
    }
    masini.sterge(masini[index]);
}

VectorDinamic<Masina> Repo::copyList() const {
    VectorDinamic<Masina> copie(1);
    for (int i = 0; i < masini.dim(); ++i) {
        copie.adaugaSfarsit(masini[i]);
    }
    return copie;
}

// === Filtrare ===

bool filtreazaModel(const Masina& m, const string& model) {
    return m.getModel() == model;
}

bool filtreazaCategorie(const Masina& m, const string& categorie) {
    return m.getCategorie() == categorie;
}

// === Sortare ===

bool comparaModel(const Masina& m1, const Masina& m2) {
    return m1.getModel() < m2.getModel();
}

bool comparaCategorie(const Masina& m1, const Masina& m2) {
    return m1.getCategorie() < m2.getCategorie();
}
