#include "teste.h"
#include <cassert>

void testeService() {
	Repo repo;
	Service service{ repo };

    // ADD valid
    service.addMasina("B12ABC", "BMW", "suv");
    assert(service.getAllMasini().dim() == 1);
    // ADD invalid (empty number)
    try {
        service.addMasina("", "Audi", "Sedan");
        assert(false);
    }
    catch (const RepoExceptions& e) {
        assert(e.getMsj() == "Numarul de inmatriculare nu poate fi gol!");
    }

    // ADD another car for sort/filter tests
    service.addMasina("C34XYZ", "Audi", "sport");
    assert(service.getAllMasini().dim() == 2);

    // UPDATE valid
    service.updateMasina("B12ABC", "BMW X5", "suv", false);
    assert(service.getAllMasini()[0].getModel() == "BMW X5");

    // UPDATE invalid (non-existent car)
    try {
        service.updateMasina("Fake123", "Dacia", "sport", false);
        assert(false);
    }
    catch (const RepoExceptions&) {
        assert(true);
    }

    // RENT valid
    service.inchiriazaMasina("B12ABC");
    assert(service.getAllMasini()[0].esteInchiriata() == true);

    // RENT again (already rented)
    try {
        service.inchiriazaMasina("B12ABC");
        assert(false);
    }
    catch (const RepoExceptions&) {
        assert(true);
    }

    // RENT non-existent
    try {
        service.inchiriazaMasina("Fake123");
        assert(false);
    }
    catch (const RepoExceptions&) {
        assert(true);
    }

    // RETURN valid
    service.returneazaMasina("B12ABC");
    assert(service.getAllMasini()[0].esteInchiriata() == false);

    // RETURN again (already returned)
    try {
        service.returneazaMasina("B12ABC");
        assert(false);
    }
    catch (const RepoExceptions&) {
        assert(true);
    }

    // RETURN non-existent
    try {
        service.returneazaMasina("Fake123");
        assert(false);
    }
    catch (const RepoExceptions&) {
        assert(true);
    }

    // FILTRARE model
    auto filtrateModel = service.filtrareModel("Audi");
    assert(filtrateModel.dim() == 1);
    assert(filtrateModel[0].getModel() == "Audi");

    // FILTRARE categorie
    auto filtrateCat = service.filtrareCategorie("suv");
    assert(filtrateCat.dim() == 1);
    assert(filtrateCat[0].getCategorie() == "suv");

    // SORTARE model crescator
    auto sortModelCresc = service.sortareModel(true);
    assert(sortModelCresc[0].getModel() == "Audi");

    // SORTARE model descrescator
    auto sortModelDesc = service.sortareModel(false);
    assert(sortModelDesc[0].getModel() == "BMW X5");

    // SORTARE categorie crescator
    auto sortCatCresc = service.sortareCategorie(true);
    assert(sortCatCresc[0].getCategorie() == "suv" || sortCatCresc[0].getCategorie() == "sport");

    // SORTARE categorie descrescator
    auto sortCatDesc = service.sortareCategorie(false);
    assert(sortCatDesc[0].getCategorie() == "suv" || sortCatDesc[0].getCategorie() == "sport");

    // CAUTA valid
    int index = service.cauta("B12ABC");
    assert(index == 0);

    // CAUTA invalid
    try {
        service.cauta("Fake123");
        assert(false);
    }
    catch (const RepoExceptions&) {
        assert(true);
    }

    // STERGE valid
    service.sterge("B12ABC");
    assert(service.getAllMasini().dim() == 1);

    // STERGE invalid
    try {
        service.sterge("B12ABC");
        assert(false);
    }
    catch (const RepoExceptions&) {
        assert(true);
    }

    cout << "All Service tests passed with full coverage!\n";
}


void testeRepo1() {
    Repo repo;

    // Test adding car to Repo
    Masina masina{ "B12ABC", "BMW", "suv", false };
    repo.store(masina);
    auto masini = repo.getAll();
    assert(masini.dim() == 1);
    assert(masini[0].getModel() == "BMW");

    // Test modifying car in Repo
    repo.update(0, "BMW X5", "suv", false);
    assert(repo.getAll()[0].getModel() == "BMW X5");

    // Test searching car by registration number
    int index = repo.cauta("B12ABC");
    assert(index == 0);

    // Test invalid search (non-existing car)
    int invalidIndex = repo.cauta("NonExistent");
    assert(invalidIndex == -1);

    // Test removing car from Repo
    repo.remove(0);
    assert(repo.getAll().empty());

    cout << "Teste Repo terminate!\n";
}



void testeValidator() {
    Validator val;

    string nr = "12345"; 
    try {
        val.validareNumar(nr);
    }
    catch (RepoExceptions& e) {
        assert(false); 
    }

    string modelInvalid = "";
    try {
        val.validareModel(modelInvalid);
    }
    catch (RepoExceptions& e) {
        assert(true); 
    }

    try {
		val.validareCategorie("invalidCategory");
	}
    catch (RepoExceptions& e) {
        assert(true);
    }
    cout << "Teste Validator terminate!\n";
}

void testeDomain() {
    Masina masina{ "B12ABC", "BMW", "suv", false };

    assert(masina.getNumarInmatriculare() == "B12ABC");
    assert(masina.getModel() == "BMW");
    assert(masina.getCategorie() == "suv");
    assert(masina.esteInchiriata() == false);

    // Modify attributes
    masina.setModel("BMW M5");
    masina.setCategorie("sport");
    masina.setInchiriata(true);

    assert(masina.getModel() == "BMW M5");
    assert(masina.getCategorie() == "sport");
    assert(masina.esteInchiriata() == true);

    Masina masina1("B12ABC", "BMW", "suv", false);
    try {
        masina1.setCategorie(""); // Empty category
    }
    catch (const RepoExceptions& e) {
        assert(true); // Exception expected for invalid category
    }

    cout << "Teste Domain terminate!\n";
}

void testeFiltrareSortareDirect() {
    Masina m1("B12ABC", "BMW", "suv", false);
    Masina m2("C34XYZ", "Audi", "sport", true);

    // Test filtreazaModel
    assert(filtreazaModel(m1, "BMW"));
    assert(!filtreazaModel(m1, "Audi"));

    // Test filtreazaCategorie
    assert(filtreazaCategorie(m2, "sport"));
    assert(!filtreazaCategorie(m2, "suv"));

    // Test comparaModel
    assert(comparaModel(m2, m1));  // "Audi" < "BMW"

    // Test comparaCategorie
    assert(comparaCategorie(m2, m1));  // "sport" < "suv"

    cout << "Teste filtreaza/compara directe OK\n";
}

void testeRepo() {
    Repo repo;

    // Add a car
    Masina m("B12ABC", "BMW", "suv", false);
    repo.store(m);
    assert(repo.getAll().dim() == 1);

    // Duplicate add (should throw)
    try {
        repo.store(m);
        assert(false);
    }
    catch (const RepoExceptions& e) {
        assert(e.getMsj() == "Masina deja exista!");
    }

    // Valid update
    repo.update(0, "BMW X5", "suv", true);
    assert(repo.getAll()[0].getModel() == "BMW X5");

    // Invalid update
    try {
        repo.update(1, "x", "x", false);
        assert(false);
    }
    catch (const RepoExceptions& e) {
        assert(e.getMsj() == "Index invalid pentru update!");
    }

    // Valid remove
    repo.remove(0);
    assert(repo.getAll().empty());

    // Invalid remove
    try {
        repo.remove(0);
        assert(false);
    }
    catch (const RepoExceptions& e) {
        assert(e.getMsj() == "Index invalid pentru stergere!");
    }

    // Valid search
    repo.store(m);
    int idx = repo.cauta("B12ABC");
    assert(idx == 0);

    // Invalid search
    assert(repo.cauta("NOPE") == -1);

    // Test copyList()
    auto copie = repo.copyList();
    assert(copie.dim() == repo.getAll().dim());

    cout << "Teste Repo OK\n";
}

void runALL() {
    testeFiltrareSortareDirect();
    testeRepo();
    testeValidator();
    testeRepo1();
    testeDomain();
    testeService();
}
