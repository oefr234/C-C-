#ifndef CONTROLLER_H
#define CONTROLLER_H

#define _CRT_SECURE_NO_WARNINGS
#include "repository.h"
#include "validation.h"

typedef struct {
    MyList* repo;
} CarController;

void init_controller(CarController* controller);
void free_controller(CarController* controller);

int add_car_controller(CarController* controller, const char* reg_number, const char* model, const char* category);
int update_car_controller(CarController* controller, const char* reg_number, const char* new_model, const char* new_category);
int rent_car(CarController* controller, const char* reg_number);
int return_car(CarController* controller, const char* reg_number);
MyList* sort_cars_controller(CarController* controller, functieComparare comp, int order);
void filter_cars_controller(CarController* controller, int filter_by, const char* value);
void list_cars(CarController* controller);

#endif // CONTROLLER_H
