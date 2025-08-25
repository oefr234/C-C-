#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MyList* init_repository() {
    MyList* repo= (MyList*)malloc(sizeof(MyList));
    repo->size = 0;
    repo->capacity = 10;
    repo->elems = (ElemType*)malloc(repo->capacity * sizeof(ElemType));
    return repo;
}

void free_repository(MyList* repo) {
	for (int i = 0; i < repo->size; i++) {
		destroyCar(repo->elems[i]);
		free(repo->elems[i]);
	}
    free(repo->elems);
	free(repo);
}

MyList* copy_list(MyList* repo) {
    MyList* new_list = init_repository();
    if (new_list == NULL) return NULL;

    if (new_list->elems == NULL) {
        free(new_list);
        return NULL;
    }

    for (int i = 0; i < repo->size; i++) {
        Car* car = creatCar(repo->elems[i]->reg_number, repo->elems[i]->model, repo->elems[i]->category, repo->elems[i]->rented);
        add_car(new_list, car);
    }

    return new_list;
}

void resize_repository(MyList* repo) {
    ElemType* new_elems = (ElemType*)malloc(2 * repo->capacity * sizeof(ElemType));
    if (new_elems != NULL) {
        for (int i = 0; i < repo->size; i++) {
            new_elems[i] = repo->elems[i];
        }
        free(repo->elems);
        repo->elems = new_elems;
        repo->capacity *= 2;
    }
}


void reset_repository(MyList* repo) {
    repo->size = 0;
}

int add_car(MyList* repo, Car* car) {
    if (repo->size >= repo->capacity) {
        resize_repository(repo);
    }
    repo->elems[repo->size] = car;
    repo->size++;
    return 1;
}

int update_car(MyList* repo, const char* reg_number, const char* new_model, const char* new_category) {
    ElemType car = find_car_by_plate(repo, reg_number);
    if (car == NULL) return 0;

    strcpy(car->model, new_model);
    strcpy(car->category, new_category);
    return 1;
}

ElemType* find_car_by_plate(MyList* repo, const char* reg_number) {
    for (int i = 0; i < repo->size; i++) {
        if (strcmp(repo->elems[i]->reg_number, reg_number) == 0) {
            return repo->elems[i];
        }
    }
    return NULL;
}

MyList* sort_cars(MyList* lst, functieComparare cmp, int desc) {
    MyList* sorted = copy_list(lst);
    if (sorted == NULL) return NULL;
    for (int i = 0; i < sorted->size - 1; i++) {
        for (int j = i + 1; j < sorted->size; j++) {
            int compare = cmp(sorted->elems[i], sorted->elems[j]);
            if ((desc == 1 && compare < 0) || (desc == 2 && compare > 0)) {
                ElemType temp = sorted->elems[i];
                sorted->elems[i] = sorted->elems[j];
                sorted->elems[j] = temp;
            }
        }
    }

    return sorted;
}

void filter_cars(MyList* repo, int filter_by, const char* value) {
    int found = 0;
    for (int i = 0; i < repo->size; i++) {
        if ((filter_by == 2 && strcmp(repo->elems[i]->model, value) == 0) ||
            (filter_by == 1 && strcmp(repo->elems[i]->category, value) == 0)) {
            printf("%s | %s | %s | %s\n", repo->elems[i]->reg_number, repo->elems[i]->model,
                repo->elems[i]->category,
                repo->elems[i]->rented ? "Inchiriata" : "Disponibila");
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found matching the criteria.\n");
    }
}

int compare_model(const void* a, const void* b) {
    return strcmp(((Car*)a)->model, ((Car*)b)->model);
}

int compare_category(const void* a, const void* b) {
    return strcmp(((Car*)a)->category, ((Car*)b)->category);
}

void list_cars_repo(MyList* repo) {
    for (int i = 0; i < repo->size; i++) {
        printf("%s | %s | %s | %s\n", repo->elems[i]->reg_number, repo->elems[i]->model, repo->elems[i]->category,
            repo->elems[i]->rented ? "Inchiriata" : "Disponibila");
    }
}
