#include "ui.h"
#include "controller.h"
#include <stdio.h>

void show_menu(CarController* controller) {
    int choice;
    char reg_number[20], model[30], category[20];
    add_car_controller(controller, "CJ44ABC", "Volvo", "SUV");
    add_car_controller(controller, "BT67KLG", "BMW", "sport");
    add_car_controller(controller, "SJ34ASD", "Audi", "mini");

    while (1) {
        printf("\n--- Meniu Inchirieri Auto ---\n");
        printf("1. Adauga masina\n");
        printf("2. Actualizeaza masina\n");
        printf("3. Inchiriaza masina\n");
        printf("4. Returneaza masina\n");
        printf("5. Sortare masini\n");
        printf("6. Filtrare masini\n");
        printf("7. Afiseaza masini\n");
        printf("8. Iesire\n");
        printf("Alege optiunea: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Numar inmatriculare: ");
            scanf("%s", reg_number);
            printf("Model: ");
            scanf("%s", model);
            printf("Categorie (mini, sport, SUV): ");
            scanf("%s", category);
            if (add_car_controller(controller, reg_number, model, category)) {
                printf("Masina adaugata cu succes!\n");
            }
            else {
                printf("Eroare la adaugare!\n");
            }
            break;

        case 2:
            printf("Numar inmatriculare masina existenta: ");
            scanf("%s", reg_number);
            printf("Model nou: ");
            scanf("%s", model);
            printf("Categorie noua: ");
            scanf("%s", category);
            if (update_car_controller(controller, reg_number, model, category)) {
                printf("Masina actualizata!\n");
            }
            else {
                printf("Eroare la actualizare!\n");
            }
            break;

        case 3:
            printf("Numar inmatriculare: ");
            scanf("%s", reg_number);
            if (rent_car(controller, reg_number)) {
                printf("Masina inchiriata!\n");
            }
            else {
                printf("Eroare la inchiriere!\n");
            }
            break;

        case 4:
            printf("Numar inmatriculare: ");
            scanf("%s", reg_number);
            if (return_car(controller, reg_number)) {
                printf("Masina returnata!\n");
            }
            else {
                printf("Eroare la returnare!\n");
            }
            break;

        case 5: {
            int sort_by, order;
            MyList* sorted = NULL; 
            printf("Sortare dupa: 1 - Model, 2 - Categorie: ");
            scanf("%d", &sort_by);
            printf("Ordine: 1 - Crescator, 2 - Descrescator: ");
            scanf("%d", &order);
            if (sort_by == 2) {
                sorted = sort_cars_controller(controller, compModel, order);
                list_cars_repo(sorted);
            }
            else {
                sorted = sort_cars_controller(controller, compCategory, order);
                list_cars_repo(sorted);
            }
            if (sorted != NULL) {
                free_repository(sorted);
            }
            break;
        }

        case 6: {
            int filter_by;
            printf("Filtrare dupa: 1 - Categorie, 2 - Model: ");
            scanf("%d", &filter_by);
            printf("Valoare: ");
            scanf("%s", category);
            filter_cars_controller(controller, filter_by, category);
            break;
        }

        case 7:
            list_cars(controller);
            break;

        case 8:
            return;

        default:
            printf("Optiune invalida!\n");
        }
    }
}
