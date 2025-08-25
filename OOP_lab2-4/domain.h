#ifndef DOMAIN_H
#define DOMAIN_H

#define MAX_CARS 100

typedef struct {
    char* reg_number;
    char* model;
    char* category;
    int rented; // 0 - disponibil, 1 - inchiriat
} Car;



Car* creatCar(char* reg_number, char* model, char* category, int rented);

void destroyCar(Car* car);

void valideaza(Car);

int compModel(Car* car1, Car* car2);
int compCategory(Car * car1, Car * car2);

#endif // DOMAIN_H
