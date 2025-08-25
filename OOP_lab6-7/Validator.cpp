#include "Validator.h"
#include <algorithm>

// Verifică dacă numărul de înmatriculare este valid (nevid)
void Validator::validareNumar(const string& numar) {
    if (numar.empty()) {
        throw ValidatorException("Numarul de inmatriculare nu poate fi gol!");
    }
}

// Verifică dacă modelul este valid (nevid)
void Validator::validareModel(const string& model) {
    if (model.empty()) {
        throw ValidatorException("Modelul nu poate fi gol!");
    }
}

// Verifică dacă categoria este una din cele permise
void Validator::validareCategorie(const string& categorie) {
    static const vector<string> categoriiPermise = { "mini", "suv", "sport", "berlina", "offroad" };

    auto it = std::find(categoriiPermise.begin(), categoriiPermise.end(), categorie);
    if (it == categoriiPermise.end()) {
        throw ValidatorException("Categoria introdusa nu este valida! (ex: mini, suv, sport, etc)");
    }
}
