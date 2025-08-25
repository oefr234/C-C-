#include "service.h"
#include <string.h>
#include <stdlib.h>

// Function to create a new service object
ServiceMed* creeazaService() {
    ServiceMed* service = (ServiceMed*)malloc(sizeof(ServiceMed));
    if (service) {
        service->lst_med = creeazaListaVida();
        service->undo = creeazaListaVida();
        service->redo = creeazaListaVida();
        service->validator = 1;
    }
    return service;
}

// Function to save the current state for undo functionality
void save_undo_state(ServiceMed* service) {
    List* copiedList = copiazaLista(service->lst_med);
    for (int i = 0; i < copiedList->dim; ++i) {
        adaugaSfarsit(copiedList->med[i], service->undo);  // Add each element to the undo list
    }
    distrugeLista(service->redo);
    service->redo = creeazaListaVida();
}

// Function to add a medicament to the service
int adaugaMedicament(ServiceMed* service, Medicament* m) {
    printf("%d %s %d %d \n", m->cod, m->nume, m->concentratie, m->cantitate);

    service->validator = valideazaMedicament(m);
    if (!service->validator) {
        distrugeMedicament(m);
        return 0;
    }

    int poz = cautaMedicament(m->cod, service);
    save_undo_state(service);

    if (poz != -1) {
        Medicament* existent = service->lst_med->med[poz];
        if (strcmp(existent->nume, m->nume) == 0 && existent->concentratie == m->concentratie) {
            existent->cantitate += m->cantitate;
            distrugeMedicament(m);
            return 1;
        }
        else {
            distrugeMedicament(m);
            return -1;
        }
    }

    adaugaSfarsit(m, service->lst_med);  // Corrected: add Medicament* to List
    return 1;
}

// Function to modify an existing medicament in the service
int modificaMedicament(ServiceMed* service, int cod, char* newName, int newConc) {
    int poz = cautaMedicament(cod, service);
    if (poz == -1) return -1;

    List* l = service->lst_med;
    Medicament* nou = copiazaLista(l->med[poz]);  // Corrected: copiazaMedicament() must return Medicament*
    modificaNume(nou, newName);
    modificaConcentratie(nou, newConc);

    if (!valideazaMedicament(nou)) {
        distrugeMedicament(nou);
        return 0;
    }

    save_undo_state(service);
    modificaNume(l->med[poz], newName);
    modificaConcentratie(l->med[poz], newConc);
    distrugeMedicament(nou);
    return 1;
}

// Function to delete a medicament by its code
int stergeMedicament(ServiceMed* service, int cod) {
    int poz = cautaMedicament(cod, service);
    if (poz == -1) return 0;

    save_undo_state(service);
    stergePoz(poz, service->lst_med);
    return 1;
}

// Undo function
int undo(ServiceMed* service) {
    if (service->undo->dim == 0) return 0;

    List* copiedList = copiazaLista(service->lst_med);
    for (int i = 0; i < copiedList->dim; ++i) {
        adaugaSfarsit(copiedList->med[i], service->undo);  
    }

    distrugeLista(service->lst_med);
    service->lst_med = eliminaUltimul(service->undo); 
    return 1;
}

// Redo function
int redo(ServiceMed* service) {
    if (service->redo->dim == 0) return 0;

    List* copiedList = copiazaLista(service->lst_med);
    for (int i = 0; i < copiedList->dim; ++i) {
        adaugaSfarsit(copiedList->med[i], service->undo);  // Add each element to the undo list
    }

    distrugeLista(service->lst_med);
    service->lst_med = eliminaUltimul(service->redo);  // Corrected: eliminaUltimul returns List*
    return 1;
}

// Function to filter medicaments by quantity
List* filtrareCantitate(ServiceMed* service, int cantitateData) {
    List* rezultat = creeazaListaVida();
    for (int i = 0; i < service->lst_med->dim; ++i) {
        Medicament* m = service->lst_med->med[i];
        if (m->cantitate < cantitateData) {
            adaugaSfarsit(m, rezultat);  // Corrected: adaugaSfarsit expects Medicament* (not List*)
        }
    }
    return rezultat;
}

// Function to filter medicaments by the first letter of their name
List* filtrareNume(ServiceMed* service, char c) {
    List* rezultat = creeazaListaVida();
    for (int i = 0; i < service->lst_med->dim; ++i) {
        Medicament* m = service->lst_med->med[i];
        if (m->nume[0] == c) {
            adaugaSfarsit(m, rezultat);  // Corrected: adaugaSfarsit expects Medicament* (not List*)
        }
    }
    return rezultat;
}

// Sorting function
List* sorteaza(ServiceMed* service, int (*cmp)(Medicament*, Medicament*), int desc) {
    List* rezultat = copiazaLista(service->lst_med);  // Corrected: copiazaLista returns List*
    for (int i = 0; i < rezultat->dim - 1; ++i) {
        for (int j = i + 1; j < rezultat->dim; ++j) {
            if ((cmp(rezultat->med[i], rezultat->med[j]) > 0 && !desc) || (cmp(rezultat->med[i], rezultat->med[j]) < 0 && desc)) {
                Medicament* tmp = rezultat->med[i];
                rezultat->med[i] = rezultat->med[j];
                rezultat->med[j] = tmp;
            }
        }
    }
    return rezultat;
}

// Function to destroy the service and free memory
void distrugeService(ServiceMed* service) {
    distrugeLista(service->lst_med);
    distrugeLista(service->undo);
    distrugeLista(service->redo);
    free(service);
}

// Function to copy a list (returns List* of copied medicaments)
List* copiazaLista(List* l) {
    List* newList = creeazaListaVida();  // Create an empty list
    for (int i = 0; i < l->dim; ++i) {
        adaugaSfarsit(l->med[i], newList);  // Add each element to the new list
    }
    return newList;
}

int cautaMedicament(int cod, ServiceMed* service) {
    for (int i = 0; i < service->lst_med->dim; ++i) {
        if (service->lst_med->med[i]->cod == cod) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Not found
}

// Function to remove the last element from the list and return it (as List*)
List* eliminaUltimul(List* l) {
    if (l->dim == 0) return NULL;  // Return NULL if the list is empty

    Medicament* lastElement = l->med[l->dim - 1];
    stergePoz(l->dim - 1, l);  // Remove the last element
    List* singleMedList = creeazaListaVida();
    adaugaSfarsit(lastElement, singleMedList);  // Return the last element as a new list
    return singleMedList;
}
