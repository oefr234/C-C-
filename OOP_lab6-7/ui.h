#ifndef INCHIRIERE_AUTO_UI_H
#define INCHIRIERE_AUTO_UI_H

#include "service.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

class UI {
    Service& srv;

public:
    explicit UI(Service& service) : srv{ service } {}

    // Meniul principal al aplicației
    void meniu() {
        srv.addMasina("CJ44ABC", "Volvo", "suv");
        srv.addMasina( "BT67KLG", "BMW", "sport");
        srv.addMasina("SJ34ASD", "Audi", "mini");
        int optiune;
        do {
            cout << "\n*** Meniu ***\n";
            cout << "1. Adauga masina\n";
            cout << "2. Afiseaza masini\n";
            cout << "3. Modifica masina\n";
            cout << "4. Sterge masina\n";
            cout << "5. Cauta masina\n";
            cout << "6. Filtrare masini\n";
            cout << "7. Sortare masini\n";
            cout << "0. Iesire\n";
            cout << "Alegeti optiunea: ";
            cin >> optiune;

            switch (optiune) {
            case 1: uiAdd(); break;
            case 2: uiAfisare(); break;
            case 3: uiMod(); break;
            case 4: uiSterge(); break;
            case 5: uiCauta(); break;
            case 6: uiFiltrare(); break;
            case 7: uiSortare(); break;
            case 0: cout << "La revedere!\n"; break;
            default: cout << "Optiune invalida!\n"; break;
            }
        } while (optiune != 0);
    }

    // Adăugarea unei mașini
    void uiAdd() {
        string nrInmatriculare, model, categorie;
        cout << "Introduceti nr. de inmatriculare: ";
        cin >> nrInmatriculare;
        cout << "Introduceti modelul: ";
        cin >> model;
        cout << "Introduceti categoria (mini, sport, suv, etc.): ";
        cin >> categorie;

        try {
            srv.addMasina(nrInmatriculare, model, categorie);
            cout << "Masina a fost adaugata cu succes!\n";
        }
        catch (const ValidatorException& e) {
            cout << "Eroare validare: " << e.getMsj() << '\n';
        }
        catch (const RepoExceptions& e) {
            cout << "Eroare repo: " << e.getMsj() << '\n';
        }
    }

    // Afișarea tuturor mașinilor
    void uiAfisare() {
        auto masini = srv.getAllMasini();
        if (masini.empty()) {
            cout << "Nu exista masini!\n";
        }
        else {
            for (const auto& masina : masini) {
                cout << masina.getNumarInmatriculare()
                    << " | " << masina.getModel()
                    << " | " << masina.getCategorie()
                    << " | " << (masina.esteInchiriata() ? "Inchiriata" : "Disponibila") << '\n';
            }
        }
    }

    // Modificarea detaliilor unei mașini
    void uiMod() {
        string nrInmatriculare, modelNou, categorieNoua;
        bool inchiriataNoua;
        cout << "Introduceti nr. de inmatriculare al masinii de modificat: ";
        cin >> nrInmatriculare;
        cout << "Introduceti modelul nou: ";
        cin >> modelNou;
        cout << "Introduceti categoria noua: ";
        cin >> categorieNoua;
        cout << "Este inchiriata acum? (1 pentru da, 0 pentru nu): ";
        cin >> inchiriataNoua;

        try {
            srv.updateMasina(nrInmatriculare, modelNou, categorieNoua, inchiriataNoua);
            cout << "Masina a fost actualizata cu succes!\n";
        }
        catch (const RepoExceptions& e) {
            cout << "Eroare repo: " << e.getMsj() << '\n';
        }
    }

    // Ștergerea unei mașini
    void uiSterge() {
        string nrInmatriculare;
        cout << "Introduceti nr. de inmatriculare al masinii de sters: ";
        cin >> nrInmatriculare;

        try {
            srv.sterge(nrInmatriculare);
            cout << "Masina a fost stearsa cu succes!\n";
        }
        catch (const RepoExceptions& e) {
            cout << "Eroare repo: " << e.getMsj() << '\n';
        }
    }

    // Căutarea unei mașini după nr. de înmatriculare
    void uiCauta() {
        string nrInmatriculare;
        cout << "Introduceti nr. de inmatriculare al masinii de cautat: ";
        cin >> nrInmatriculare;

        try {
            int index = srv.cauta(nrInmatriculare);
            auto masina = srv.getAllMasini()[index];
            cout << "Masina gasita: " << masina.getNumarInmatriculare() << ", "
                << masina.getModel() << ", " << masina.getCategorie() << '\n';
        }
        catch (const RepoExceptions& e) {
            cout << "Eroare repo: " << e.getMsj() << '\n';
        }
    }

    // Filtrarea mașinilor după model sau categorie
    void uiFiltrare() {
        int optiune;
        cout << "Filtrare dupa:\n";
        cout << "1. Model\n";
        cout << "2. Categorie\n";
        cout << "Alegeti optiunea: ";
        cin >> optiune;

        vector<Masina> masiniFiltrate;

        if (optiune == 1) {
            string model;
            cout << "Introduceti modelul: ";
            cin >> model;
            masiniFiltrate = srv.filtrareModel(model);
        }
        else if (optiune == 2) {
            string categorie;
            cout << "Introduceti categoria: ";
            cin >> categorie;
            masiniFiltrate = srv.filtrareCategorie(categorie);
        }

        if (masiniFiltrate.empty()) {
            cout << "Nu exista masini care sa corespunda criteriului!\n";
        }
        else {
            for (const auto& masina : masiniFiltrate) {
                cout << masina.getNumarInmatriculare() << " - " << masina.getModel() << " - " << masina.getCategorie() << '\n';
            }
        }
    }

    // Sortarea mașinilor după model sau categorie
    void uiSortare() {
        int optiune;
        cout << "Sortare dupa:\n";
        cout << "1. Model\n";
        cout << "2. Categorie\n";
        cout << "Alegeti optiunea: ";
        cin >> optiune;

        bool crescator;
        cout << "Sortare crescatoare (1 pentru da, 0 pentru nu): ";
        cin >> crescator;

        vector<Masina> masiniSortate;

        if (optiune == 1) {
            masiniSortate = srv.sortareModel(crescator);
        }
        else if (optiune == 2) {
            masiniSortate = srv.sortareCategorie(crescator);
        }

        for (const auto& masina : masiniSortate) {
            cout << masina.getNumarInmatriculare() << " - " << masina.getModel() << " - " << masina.getCategorie() << '\n';
        }
    }
};

#endif //INCHIRIERE_AUTO_UI_H
