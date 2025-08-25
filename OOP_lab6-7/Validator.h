#ifndef INCHIRIERE_AUTO_VALIDATOR_H
#define INCHIRIERE_AUTO_VALIDATOR_H

#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include "Repo.h"

using std::string;
using std::vector;

class Validator {
public:
    // Validează câmpurile unei mașini
    static void validareNumar(const string& numar);
    static void validareModel(const string& model);
    static void validareCategorie(const string& categorie);
};

class ValidatorException : public RepoExceptions {
public:
    explicit ValidatorException(const string& msg) : RepoExceptions(msg) {}
};

#endif //INCHIRIERE_AUTO_VALIDATOR_H
