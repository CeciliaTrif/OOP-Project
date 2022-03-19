#include "CarValidator.h"

CarValidator::CarValidator() = default;

CarValidator::~CarValidator() = default;

void CarValidator::validate(Vehicle *vehicle) noexcept(false) {
    string errors;

    try {
        VehicleValidator::validate(vehicle);
    }
    catch (ValidationException &exception) {
        errors += exception.toString();
    }

    auto *car = (Car*)vehicle;
    if (car->getType().empty()) {
        errors += "Tipul nu poate fi gol!\n";
    }

    if (car->getType() != "diesel" and car->getType() != "benzina" and car->getType() != "electrica" and car->getType()
    != "hibrid") {
        errors += "Trebuie sa introduceti un tip valid! (diesel/benzina/electrica/hibrid)\n";
    }

    if (!errors.empty()) {
        throw ValidationException(errors);
    }
}
