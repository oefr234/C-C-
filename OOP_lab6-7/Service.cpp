#include "service.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Adaugă o mașină după validare
void Service::addMasina(const string& nrInmatriculare, const string& model, const string& categorie) {
    val.validareNumar(nrInmatriculare);
    val.validareModel(model);
    val.validareCategorie(categorie);
    Masina masina{ nrInmatriculare, model, categorie, false };
    repo.store(masina);
}

// Actualizează o mașină existentă
void Service::updateMasina(const string& nrInmatriculare, const string& modelNou, const string& categorieNoua, bool inchiriataNoua) {
    val.validareNumar(nrInmatriculare);
    val.validareModel(modelNou);
    val.validareCategorie(categorieNoua);

    int index = repo.cauta(nrInmatriculare);
    if (index == -1) {
        throw RepoExceptions("Mașina nu există în listă!");
    }
    else {
        repo.update(index, modelNou, categorieNoua, inchiriataNoua);
    }
}

// Închiriază o mașină
void Service::inchiriazaMasina(const string& nrInmatriculare) {
    int index = repo.cauta(nrInmatriculare);
    if (index == -1) {
        throw RepoExceptions("Mașina nu există în listă!");
    }
    else {
        Masina masina = repo.getAll().element(index);  // obține copia
        if (masina.esteInchiriata()) {
            throw RepoExceptions("Mașina este deja închiriată!");
        }
        else {
            repo.update(index, masina.getModel(), masina.getCategorie(), true);
        }
    }
}

// Returnează o mașină
void Service::returneazaMasina(const string& nrInmatriculare) {
    int index = repo.cauta(nrInmatriculare);
    if (index == -1) {
        throw RepoExceptions("Mașina nu există în listă!");
    }
    else {
        Masina masina = repo.getAll().element(index);  // obține copia
        if (!masina.esteInchiriata()) {
            throw RepoExceptions("Mașina nu este închiriată!");
        }
        else {
            repo.update(index, masina.getModel(), masina.getCategorie(), false);
        }
    }
}

// Returnează toate mașinile
VectorDinamic<Masina> Service::getAllMasini() const {
    return repo.copyList();  // returnează o copie
}

// Filtrare după model
VectorDinamic<Masina> Service::filtrareModel(const string& model) {
    VectorDinamic<Masina> masiniFiltrate(1);
    for (int i = 0; i < repo.getAll().dim(); ++i) {
        const Masina& masina = repo.getAll().element(i);
        if (masina.getModel() == model) {
            masiniFiltrate.adaugaSfarsit(masina);
        }
    }
    return masiniFiltrate;
}

// Filtrare după categorie
VectorDinamic<Masina> Service::filtrareCategorie(const string& categorie) {
    VectorDinamic<Masina> masiniFiltrate(1);
    for (int i = 0; i < repo.getAll().dim(); ++i) {
        const Masina& masina = repo.getAll().element(i);
        if (masina.getCategorie() == categorie) {
            masiniFiltrate.adaugaSfarsit(masina);
        }
    }
    return masiniFiltrate;
}

// Sortare după model
VectorDinamic<Masina> Service::sortareModel(bool crescator) {
    VectorDinamic<Masina> masini = repo.copyList();
    for (int i = 0; i < masini.dim() - 1; ++i) {
        for (int j = i + 1; j < masini.dim(); ++j) {
            bool shouldSwap = crescator ?
                masini.element(i).getModel() > masini.element(j).getModel() :
                masini.element(i).getModel() < masini.element(j).getModel();
            if (shouldSwap) {
                Masina aux = masini.element(i);
                masini.element(i) = masini.element(j);
                masini.element(j) = aux;
            }
        }
    }
    return masini;
}

// Sortare după categorie
VectorDinamic<Masina> Service::sortareCategorie(bool crescator) {
    VectorDinamic<Masina> masini = repo.copyList();
    for (int i = 0; i < masini.dim() - 1; ++i) {
        for (int j = i + 1; j < masini.dim(); ++j) {
            bool shouldSwap = crescator ?
                masini.element(i).getCategorie() > masini.element(j).getCategorie() :
                masini.element(i).getCategorie() < masini.element(j).getCategorie();
            if (shouldSwap) {
                Masina aux = masini.element(i);
                masini.element(i) = masini.element(j);
                masini.element(j) = aux;
            }
        }
    }
    return masini;
}

// Caută o mașină după numărul de înmatriculare
int Service::cauta(const string& nrInmatriculare) {
    int index = repo.cauta(nrInmatriculare);
    if (index == -1) {
        throw RepoExceptions("Mașina nu există în listă!");
    }
    return index;
}

// Șterge o mașină după număr de înmatriculare
void Service::sterge(const string& nrInmatriculare) {
    int index = repo.cauta(nrInmatriculare);
    if (index == -1) {
        throw RepoExceptions("Mașina nu există în listă!");
    }
    repo.remove(index);
}
