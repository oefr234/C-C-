#include "controller.h"
#include <stdio.h>

void init_controller(CarController* controller) {
    controller->repo = init_repository();
    printf("%d", controller->repo->size);
}

void free_controller(CarController* controller) {
    free_repository(controller->repo);
    free(controller);
}

int add_car_controller(CarController* controller, const char* reg_number, const char* model, const char* category) {
    if (!is_valid_license_plate(reg_number) || !is_valid_model(model) || !is_valid_category(category)) {
        printf("Date invalide! Verifica numarul de inmatriculare, modelul si categoria.\n");
        return 0;
    }
    Car* car = creatCar(reg_number, model, category, 0);
    return add_car(controller->repo, car);
}

int update_car_controller(CarController* controller, const char* reg_number, const char* new_model, const char* new_category) {
    if (!is_valid_model(new_model) || !is_valid_category(new_category)) {
        printf("Model sau categorie invalida!\n");
        return 0;
    }
    return update_car(controller->repo, reg_number, new_model, new_category);
}

int rent_car(CarController* controller, const char* reg_number) {
    Car* car = find_car_by_plate(controller->repo, reg_number);
    if (car == NULL) {
        printf("Masina nu exista!\n");
        return 0;
    }
    if (car->rented == 1) {
        printf("Masina este deja inchiriata!\n");
        return 0;
    }
    car->rented = 1;
    return 1;
}

int return_car(CarController* controller, const char* reg_number) {
    Car* car = find_car_by_plate(controller->repo, reg_number);
    if (car == NULL) {
        printf("Masina nu exista!\n");
        return 0;
    }
    if (!car->rented) {
        printf("Masina nu este inchiriata!\n");
        return 0;
    }
    car->rented = 0;
    return 1;
}

MyList* sort_cars_controller(CarController* controller, functieComparare comp, int order) {
    if (order != 1 && order != 2) {
        printf("Ordinea trebuie sa fie 1 (crescator) sau 2 (descrescator)!\n");
        return;
    }
    return sort_cars(controller->repo, &comp, order);
}



void filter_cars_controller(CarController* controller, int filter_by, const char* value) {
    if (filter_by != 1 && filter_by != 2) {
        printf("Filtrare invalida!\n");
        return;
    }
    filter_cars(controller->repo, filter_by, value);
}


void list_cars(CarController* controller) {
    if (controller->repo->size == 0) {
        printf("Nu exista masini in sistem.\n");
        return;
    }

    printf("\n--- Lista Masinilor ---\n");
    for (int i = 0; i < controller->repo->size; i++) {
        Car* car = controller->repo->elems[i];
        printf("%s | %s | %s | %s\n", car->reg_number, car->model,car->category,
                        car->rented ? "Inchiriata" : "Disponibila");
    }
}