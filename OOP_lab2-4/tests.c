//#include "tests.h"
//#include "repository.h"
//#include "controller.h"
//#include "validation.h"
//#include <assert.h>
//#include <stdio.h>
//#include <string.h>
//#define _CRT_SECURE_NO_WARNINGS
//
//void test_add_car() {
//    MyList repo;
//    init_repository(&repo);
//
//    assert(add_car(&repo, "B123XYZ", "Dacia Logan", "mini") == 1);
//    assert(add_car(&repo, "CJ45ABC", "BMW X5", "SUV") == 1);
//    assert(add_car(&repo, "EF34GH", "Audi A4", "sport") == 1);
//
//    free_repository(&repo);
//}
//
//void test_update_car() {
//    MyList repo;
//    init_repository(&repo);
//    add_car(&repo, "B123XYZ", "Dacia Logan", "mini");
//
//    assert(update_car(&repo, "B123XYZ", "Dacia Duster", "SUV") == 1);
//    assert(update_car(&repo, "XYZ999", "Tesla", "electric") == 0);
//    assert(update_car(&repo, "B123XYZ", "BMW", "sport") == 1);
//
//    free_repository(&repo);
//}
//
//
//
//void test_filter_cars() {
//    MyList repo;
//    init_repository(&repo);
//    add_car(&repo, "B123XYZ", "Dacia Logan", "mini");
//    add_car(&repo, "CJ45ABC", "BMW X5", "SUV");
//
//    filter_cars(&repo, 1, "SUV");
//    filter_cars(&repo, 2, "Dacia Logan");
//    filter_cars(&repo, 1, "luxury");
//
//    free_repository(&repo);
//}
//
//void test_sort_cars() {
//    MyList repo;
//    init_repository(&repo);
//    add_car(&repo, "B123XYZ", "Audi", "sport");
//    add_car(&repo, "CJ45ABC", "BMW", "SUV");
//    add_car(&repo, "IF77DEF", "Volkswagen", "mini");
//
//    printf("\nSort by Model Ascending:\n");
//    sort_cars(&repo, 1, 1);
//    list_cars(&repo);
//
//    printf("\nSort by Category Descending:\n");
//    sort_cars(&repo, 2, 2);
//    list_cars(&repo);
//
//    free_repository(&repo);
//}
//
//void test_add_car_controller() {
//    CarController controller;
//    init_controller(&controller);
//
//    assert(add_car_controller(&controller, "B123XYZ", "Dacia Logan", "mini") == 1);
//    assert(controller.repo.size == 1);
//    assert(add_car_controller(&controller, "", "Ford Focus", "sport") == 0);
//    assert(add_car_controller(&controller, "B123XYZ", "Invalid Model", "mini") == 1);
//    assert(add_car_controller(&controller, "EF34GH", "Audi A4", "luxury") == 0);
//
//    free_controller(&controller);
//}
//
//void test_update_car_controller() {
//    CarController controller;
//    init_controller(&controller);
//    add_car_controller(&controller, "B123XYZ", "Dacia Logan", "mini");
//
//    assert(update_car_controller(&controller, "B123XYZ", "BMW X5", "SUV") == 1);
//    Car* car = find_car_by_plate(&controller.repo, "B123XYZ");
//    assert(car != NULL);
//    assert(strcmp(car->model, "BMW X5") == 0);
//    assert(strcmp(car->category, "SUV") == 0);
//
//    assert(update_car_controller(&controller, "INVALID", "BMW X5", "SUV") == 0);
//    assert(update_car_controller(&controller, "B123XYZ", "Invalid Model", "SUV") == 1);
//    assert(update_car_controller(&controller, "B123XYZ", "BMW X5", "invalid") == 0);
//
//    free_controller(&controller);
//}
//
//void test_rent_car() {
//    CarController controller;
//    init_controller(&controller);
//    add_car_controller(&controller, "B123XYZ", "Dacia Logan", "mini");
//
//    assert(rent_car(&controller, "B123XYZ") == 1);
//    Car* car = find_car_by_plate(&controller.repo, "B123XYZ");
//    assert(car->rented == 1);
//
//    assert(rent_car(&controller, "B123XYZ") == 0);
//    assert(rent_car(&controller, "INVALID") == 0);
//    free_controller(&controller);
//}
//
//void test_return_car() {
//    CarController controller;
//    init_controller(&controller);
//    add_car_controller(&controller, "B123XYZ", "Dacia Logan", "mini");
//
//    rent_car(&controller, "B123XYZ");
//    assert(return_car(&controller, "B123XYZ") == 1);
//    Car* car = find_car_by_plate(&controller.repo, "B123XYZ");
//    assert(car->rented == 0);
//
//    assert(return_car(&controller, "INVALID") == 0);
//    assert(return_car(&controller, "B123XYZ") == 0);
//
//    free_controller(&controller);
//}
//void test_sort_cars_controller() {
//    MyList repo;
//    init_repository(&repo);
//    add_car(&repo, "B123XYZ", "Dacia Logan", "mini");
//    add_car(&repo, "CJ45ABC", "BMW X5", "SUV");
//
//    sort_cars(&repo, 1, 1);
//    assert(strcmp(repo.elems[0]->model, "BMW X5") == 0);
//
//    sort_cars(&repo, 2, 2);
//    assert(strcmp(repo.elems[0]->category, "mini") == 0);
//
//    free_repository(&repo);
//}
//
//void test_filter_cars_controller() {
//    MyList repo;
//    init_repository(&repo);
//    add_car(&repo, "B123XYZ", "Dacia Logan", "mini");
//    add_car(&repo, "CJ45ABC", "BMW X5", "SUV");
//
//    filter_cars(&repo, 1, "BMW X5");
//    filter_cars(&repo, 2, "SUV");
//    filter_cars(&repo, 3, "Invalid");
//
//    free_repository(&repo);
//}
//
//void test_validations() {
//    assert(is_valid_license_plate("B123XYZ") == 1);
//    assert(is_valid_license_plate("1234") == 0);
//    assert(is_valid_model("Dacia") == 1);
//    assert(is_valid_model("") == 0);
//    assert(is_valid_category("sport") == 1);
//    assert(is_valid_category("luxury") == 0);
//}
//
//void run_tests() {
//    test_add_car();
//    test_update_car();
//    //test_rent_return_car();
//    test_filter_cars();
//    test_sort_cars();
//    test_validations();
//    test_add_car_controller();
//    test_update_car_controller();
//    test_rent_car();
//    test_return_car();
//    test_sort_cars_controller();
//    test_filter_cars_controller();
//}
