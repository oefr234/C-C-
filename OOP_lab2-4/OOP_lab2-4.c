#include "ui.h"
#include "tests.h"
#include <stdlib.h>
#include "controller.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
    //run_tests(); 
    CarController* controller = (CarController*)malloc(sizeof(CarController));
    init_controller(controller);
    show_menu(controller);
    free_controller(controller);
    _CrtDumpMemoryLeaks();
    return 0;
}


//C:\Users\onofr\OneDrive - Universitatea Babeş-Bolyai\Facultate FMI\Anul 2\Sem 2\OOP\OOP_lab2-4\x64\Debug\OOP_lab2-4.exe
//C:\Users\onofr\source\repos\OOP_lab2-4\x64\Debug\OOP_lab2-4.exed