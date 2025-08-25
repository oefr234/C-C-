#include <iostream>
#include "ui.h"
#include "teste.h"

int main() {
    runALL();
    Repo repo;
    Service srv{ repo };
    UI ui{ srv };
    ui.meniu();

    return 0;
}
