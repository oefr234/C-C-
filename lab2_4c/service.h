#pragma once
#include "MyList.h"
#include "domain.h"  

typedef struct
{
    List* lst_med;
    List* undo;
    List* redo;
    int validator;
} ServiceMed;

/// <summary>
/// Functia creeaza un service
/// </summary>
/// <returns>returneaza un obiect de tipul ServiceMed* sau NULL daca nu s-a creat</returns>
ServiceMed* creeazaService();

/// <summary>
/// Functia returneaza lista de medicamente
/// </summary>
/// <param name="serv">parametru de tip ServiceMed* de unde se va extrage lista de medicamente</param>
/// <returns>List* care contine lista de medicamente</returns>
List* listaMed(ServiceMed* serv);

/// <summary>
/// Functia cauta un medicament in lista 
/// </summary>
/// <param name="cod">parametru de tip int care reprezinta codul medicamentului pe care dorim sa il gasim</param>
/// <param name="serv">parametru de tipul ServiceMed* in care urmeaza sa cautam obiectul cu codul cod</param>
/// <returns>returneaza -1 daca obiectul nu se afla in lista sau pozitia pe care o ocupa in lista</returns>
int cautaMedicament(int cod, ServiceMed* serv);

/// <summary>
/// Functia adauga un medicament in lista
/// </summary>
/// preconditii: m nu trebuie sa existe deja sau codul lui m nu trebuie sa fie atribuit altui obiect (medicamentele se identifica unic prin cod)
///              m trebuie sa fie valid
/// postconditii: se incrementeaza dimensiunea listei daca adaugarea a fost realizata cu succes
/// <param name="m">parametru de tip Medicament* care urmeaza a fi adaugat</param>
/// <param name="serv">parametru de tip ServiceMed* in care se va efectua adugarea</param>
/// <returns>returneaza 1 daca adaugarea s-a efectuat ,-1 daca exista deja sau 0 daca datele introduse nu sunt valide</returns>
int adaugaMedicament(ServiceMed* serv, Medicament* m);

int redo(ServiceMed* service);

int undo(ServiceMed* service);

/// <summary>
/// Functia efectueaza o stergere a unui medicament intr-o lista
/// </summary>
/// preconditii: medicamentul cu codul cod trebuie sa existe in memorie ca sa poata fi sters
/// postconditii: se decrementeaza dimensiunea listei daca stergerea s-a realizat cu succes
/// <param name="cod">parametru de tip int, codul medicamentului pe care dorim sa il eliminam</param>
/// <param name="serv">parametru de tip ServiceMed* in care se va efectua stergerea</param>
/// <returns>returneaza 1 daca s-a efectuat stergerea sau 0 in caz contrar</returns>
int stergeMedicament(int cod, ServiceMed* serv);

/// <summary>
/// Functia realizeaza modificarea unui medicament (numele si concentratia)
/// </summary>
/// <param name="newconc">Concentratia noua cu care se va inlocui cea veche</param>
/// <param name="newname">Numele nou cu care se va inlocui cel vechi</param>
/// <param name="cod">Codul medicamentului asupra caruia se vor realiza modificarile</param>
/// <param name="service">Parametru de tip ServiceMed* in care se va efectua modificarea</param>
/// <returns>returneaza -1 daca medicamentul nu a fost gasit, 0 daca datele introduse nu sunt valide sau 1 daca totul a fost in regula</returns>
int modificaMedicament(int newconc, char* newname, int cod, ServiceMed* service);

/// <summary>
/// Functia creeaza o copie a unui medicament
/// </summary>
/// <param name="m">medicamentul pe care dorim sa il copiem</param>
/// <returns>returneaza o copie a medicamentului</returns>
Medicament* copieMedicament(Medicament* m);

/// <summary>
/// Functia compara doua medicamente dupa un anumit criteriu (nume sau cantitate)
/// </summary>
/// <param name="m1">obiect de tip medicament care se va compara</param>
/// <param name="m2">obiect de tip medicament care se va compara</param>
/// <param name="crt">criteriul de comparare (ex: "nume" sau "cantitate")</param>
/// <returns>0 daca cele 2 campuri comparate sunt egale, ceva mai mic ca 0 daca m1 e mai mic ca m2 dupa criteriul crt sau ceva mai mare ca 0 altfel</returns>
int compara(Medicament* m1, Medicament* m2, char* crt);

/// <summary>
/// Functia compara doua medicamente dupa un anumit criteriu, crescator sau descrescator
/// </summary>
/// <param name="m1">obiect de tip medicament care se va compara</param>
/// <param name="m2">obiect de tip medicament care se va compara</param>
/// <param name="crt">criteriul de comparare (ex: "nume" sau "cantitate")</param>
/// <param name="reverse">0 pentru comparare crescatoare, 1 pentru descrescatoare</param>
/// <returns>1 daca trebuie sa se faca swap, 0 daca nu si -1 daca crt si reverse nu sunt valide</returns>
int compara2(Medicament* m1, Medicament* m2, char* crt, int reverse);

List* sorteaza(ServiceMed* service, int (*cmp)(Medicament*, Medicament*), int desc);
/// <summary>
/// Functia returneaza o versiune sortata a listei de medicamente
/// </summary>
/// <param name="service">ServiceMed* care contine lista nesortata</param>
/// <param name="compara">functia de comparare a medicamentelor</param>
/// <param name="crt">criteriul dupa care se va sorta (ex: "nume" sau "cantitate")</param>
/// <param name="reverse">0 pentru sortare crescatoare, 1 pentru sortare descrescatoare</param>
/// <returns>o copie sortata a listei initiale sau NULL daca criteriile de sortare sunt invalide</returns>
List* sorteaza2(ServiceMed* service, int(*compara)(Medicament*, Medicament*, char*, int), char* crt, int reverse);

/// <summary>
/// Functia valideaza criteriile de sortare
/// </summary>
/// <param name="crt">criteriul de sortare (ex: "nume" sau "cantitate")</param>
/// <param name="reverse">0 pentru sortare crescatoare, 1 pentru sortare descrescatoare</param>
/// <returns>1 daca criteriile sunt valide, 0 daca nu sunt valide</returns>
int valideazaCriterii(char* crt, int reverse);

/// <summary>
/// Functia returneaza o versiune sortata a listei de medicamente
/// </summary>
/// <param name="service">ServiceMed* care contine lista nesortata</param>
/// <param name="crt">criteriul dupa care se va sorta (ex: "nume" sau "cantitate")</param>
/// <param name="reverse">0 pentru sortare crescatoare, 1 pentru sortare descrescatoare</param>
/// <returns>o copie sortata a listei initiale sau NULL daca criteriile de sortare sunt invalide</returns>
List* sorteaza(ServiceMed* service, char* crt, int reverse);

/// <summary>
/// Functia returneaza o lista de medicamente a caror cantitate este mai mica decat o valoare data
/// </summary>
/// <param name="service">ServiceMed* care contine lista de medicamente</param>
/// <param name="cantitateData">valoare de tip int care reprezinta cantitatea dupa care se va filtra lista</param>
/// <returns>o lista de medicamente (List*) care respecta criteriul cantitate</returns>
List* filtrareCantitate(ServiceMed* service, int cantitateData);

/// <summary>
/// Functia returneaza o lista de medicamente a caror nume incepe cu un caracter dat
/// </summary>
/// <param name="service">ServiceMed* care contine lista de medicamente</param>
/// <param name="c">un caracter care reprezinta caracterul cu care trebuie sa inceapa numele medicamentelor</param>
/// <returns>o lista de medicamente (List*) care respecta criteriul nume</returns>
List* filtrareNume(ServiceMed* service, char c);

/// <summary>
/// Functia are rolul de a dealoca spatiul ocupat de o variabila de tip ServiceMed*
/// </summary>
/// <param name="serv">parametru de tip ServiceMed* al carui spatiu va fi dealocat</param>
void distrugeService(ServiceMed* serv);
List* copiazaLista(List* l);
List* eliminaUltimul(List* l);