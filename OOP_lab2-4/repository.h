#ifndef REPOSITORY_H
#define REPOSITORY_H

#define _CRT_SECURE_NO_WARNINGS
#include "domain.h"
typedef Car* ElemType;
typedef int(functieComparare)(Car*, Car*);
typedef struct {
    ElemType* elems;
    int size;
    int capacity;
} MyList;

MyList* init_repository();
void free_repository(MyList* repo);
void resize_repository(MyList* repo);
void reset_repository(MyList* repo);

int add_car(MyList* repo, Car* car);
int update_car(MyList* repo, const char* reg_number, const char* new_model, const char* new_category);
ElemType* find_car_by_plate(MyList* repo, const char* reg_number);
void list_cars_repo(MyList* repo);
MyList* sort_cars(MyList* lst, functieComparare cmp, int desc);
void filter_cars(MyList* repo, int filter_by, const char* value);
int compare_model(const void* a, const void* b);
int compare_category(const void* a, const void* b);

#endif // REPOSITORY_H
