#ifndef LAB6_REPO_H
#define LAB6_REPO_H

#include "Masina.h"
#include "VectorDinamic.h"
#include <string>
using std::string;

class RepoExceptions {
private:
    string msj;
public:
    explicit RepoExceptions(string m) : msj{ std::move(m) } {}
    string getMsj() const { return msj; }
};

class Repo {
private:
    VectorDinamic<Masina> masini{ 1 }; // initialize with capacity 1

public:
    // Adaugă o mașină nouă în repo
    // Complexitate: O(n) - verificare duplicat
    void store(const Masina& m);

    // Returnează lista completă de mașini
    const VectorDinamic<Masina>& getAll() const;

    // Caută o mașină după numărul de înmatriculare și returnează indexul sau -1
    int cauta(const string& nrInmatriculare) const;

    // Actualizează o mașină existentă
    void update(int index, const string& modelNou, const string& categorieNoua, bool inchiriataNoua);

    // Șterge mașina de la un anumit index
    void remove(int index);

    // Returnează o copie a listei
    VectorDinamic<Masina> copyList() const;
};

// Filtrare după model
bool filtreazaModel(const Masina& m, const string& model);

// Filtrare după categorie
bool filtreazaCategorie(const Masina& m, const string& categorie);

// === Funcții de sortare ===

// Sortare după model
bool comparaModel(const Masina& m1, const Masina& m2);

// Sortare după categorie
bool comparaCategorie(const Masina& m1, const Masina& m2);

// Teste pentru repo
void testeRepo();

#endif //LAB6_REPO_H
