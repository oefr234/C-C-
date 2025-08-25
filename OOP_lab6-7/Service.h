#ifndef INCHIRIERE_AUTO_SERVICE_H
#define INCHIRIERE_AUTO_SERVICE_H

#include "Repo.h"
#include "Validator.h"
#include "VectorDinamic.h"

class Service {
private:
    Repo& repo;
    Validator val;

public:
    explicit Service(Repo& r) : repo{ r }, val{} {}

    // Adaugă o mașină nouă după validare
    void addMasina(const string& nrInmatriculare, const string& model, const string& categorie);

    // Actualizează o mașină după nr. înmatriculare
    void updateMasina(const string& nrInmatriculare, const string& modelNou, const string& categorieNoua, bool inchiriataNoua);

    // Închiriază o mașină
    void inchiriazaMasina(const string& nrInmatriculare);

    // Returnează o mașină
    void returneazaMasina(const string& nrInmatriculare);

    // Returnează toate mașinile
    VectorDinamic<Masina> getAllMasini() const;

    // Filtrare după model
    VectorDinamic<Masina> filtrareModel(const string& model);

    // Filtrare după categorie
    VectorDinamic<Masina> filtrareCategorie(const string& categorie);

    // Sortare după model
    VectorDinamic<Masina> sortareModel(bool crescator = true);

    // Sortare după categorie
    VectorDinamic<Masina> sortareCategorie(bool crescator = true);

    // Caută o mașină după număr
    int cauta(const string& nrInmatriculare);

    // Șterge o mașină după număr
    void sterge(const string& nrInmatriculare);
};

#endif //INCHIRIERE_AUTO_SERVICE_H
