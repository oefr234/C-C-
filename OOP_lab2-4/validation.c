#include "validation.h"
#include <ctype.h>
#include <string.h>

bool is_valid_license_plate(const char* plate) {
    return strlen(plate) >= 5 && strlen(plate) <= 10;
}

bool is_valid_model(const char* model) {
    for (int i = 0; model[i] != '\0'; i++) {
        if (!isalnum(model[i]) && model[i] != ' ') return false;
    }
    return strlen(model) > 1;
}

bool is_valid_category(const char* category) {
    return strcmp(category, "mini") == 0 || strcmp(category, "sport") == 0 || strcmp(category, "SUV") == 0;
}
