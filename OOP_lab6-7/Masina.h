//
// Created by Luca on 3/31/2024.
//
#ifndef INCHIRIERE_AUTO_MASINA_H
#define INCHIRIERE_AUTO_MASINA_H

#include <iostream>
#include <string>

using std::string;

class Masina {
private:
    string numarInmatriculare;
    string model;
    string categorie;
    bool inchiriata;

public:
    Masina() : numarInmatriculare(""), model(""), categorie(""), inchiriata(false) {}

    Masina(const string& nrInmatriculare, const string& model, const string& categorie, bool inchiriata = false)
        : numarInmatriculare{ nrInmatriculare }, model{ model }, categorie{ categorie }, inchiriata{ inchiriata } {
    }

    // Copy constructor
    Masina(const Masina& m)
        : numarInmatriculare{ m.numarInmatriculare }, model{ m.model }, categorie{ m.categorie }, inchiriata{ m.inchiriata } {
        std::cout << "Copy constructor called" << '\n';
    }

    // Getteri
    [[nodiscard]] string getNumarInmatriculare() const { return numarInmatriculare; }
    [[nodiscard]] string getModel() const { return model; }
    [[nodiscard]] string getCategorie() const { return categorie; }
    [[nodiscard]] bool esteInchiriata() const { return inchiriata; }

    // Setteri
    void setModel(const string& modelNou) { model = modelNou; }
    void setCategorie(const string& categorieNoua) { categorie = categorieNoua; }
    void setInchiriata(bool status) { inchiriata = status; }

   
};

#endif //INCHIRIERE_AUTO_MASINA_H
