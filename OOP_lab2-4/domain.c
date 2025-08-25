#include "domain.h"
#include <stdlib.h>

Car* creatCar(char* reg_number, char* model, char* category, int rented) {
	Car* car = (Car*)malloc(sizeof(Car));
	car->reg_number = malloc(20 * sizeof(char));
	car->model = malloc(20 * sizeof(char));
	car->category = malloc(20 * sizeof(char));
	strcpy(car->reg_number, reg_number);
	strcpy(car->model, model);
	strcpy(car->category, category);
	car->rented = rented;
	return car;

}

void destroyCar(Car* car) {
	free(car->reg_number);
	free(car->model);
	free(car->category);
	car->rented = -1;
}

int compModel(Car* car1, Car* car2) {
	return strcmp(car1->model, car2->model);
}

int compCategory(Car* car1, Car* car2) {
	return strcmp(car1->category, car2->category);
}