#include "VehicleValidator.h"
#include "ValidationException.h"
#include "algorithm"

VehicleValidator::VehicleValidator() = default;

VehicleValidator::~VehicleValidator() = default;

void VehicleValidator::validate(Vehicle *vehicle) noexcept(false){
    string errors;

    if (vehicle->getIdentificationNumber().empty()) {
        errors += "Numarul de identificare trebuie sa existe!\n";
    }

    if (vehicle->getBrand().empty()) {
        errors += "Brand-ul trebuie sa existe!\n";
    }

    for (char c : vehicle->getBrand()) {
        if (!isalpha(c) && c != ' ') {
            errors += "Brand-ul poate fi format doar din litere!\n";
            break;
        }
    }

    if (vehicle->getName().empty()) {
        errors += "Numele trebuie sa existe!\n";
    }

    if (vehicle->getColor().empty()) {
        errors += "Culoarea trebuie sa existe!\n";
    }

    if (vehicle->getPrice() < 0) {
        errors += "Pretul trebuie sa fie pozitiv mai mare decat 0!\n";
    }


    if (!errors.empty()) {
        throw ValidationException(errors);
    }
}
