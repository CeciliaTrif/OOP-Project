#include "UtilityVehicleValidator.h"

UtilityVehicleValidator::UtilityVehicleValidator() = default;

UtilityVehicleValidator::~UtilityVehicleValidator() = default;

void UtilityVehicleValidator::validate(Vehicle *vehicle) noexcept(false) {
    string errors;

    try {
        VehicleValidator::validate(vehicle);
    }
    catch (ValidationException &exception) {
        errors += exception.toString();
    }

    auto *utilityVehicle = (UtilityVehicle*)vehicle;
    if (utilityVehicle->getType().empty()) {
        errors += "Tipul nu poate fi gol!\n";
    }

    if (utilityVehicle->getType() != "tractor" and utilityVehicle->getType() != "combina" and utilityVehicle->getType()
        != "autobuz" and utilityVehicle->getType() != "camion") {
        errors += "Trebuie sa introduceti un tip valid! (tractor/combina/autobuz/camion)\n";
    }

    if (!errors.empty()) {
        throw ValidationException(errors);
    }
}