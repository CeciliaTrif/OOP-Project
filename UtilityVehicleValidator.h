#ifndef PROIECTOOP_UTILITYVEHICLEVALIDATOR_H
#define PROIECTOOP_UTILITYVEHICLEVALIDATOR_H
#include "UtilityVehicle.h"
#include "VehicleValidator.h"

class UtilityVehicleValidator : public VehicleValidator{
public:
    UtilityVehicleValidator();
    ~UtilityVehicleValidator() override;
    void validate(Vehicle*) noexcept(false) override;
};


#endif //PROIECTOOP_UTILITYVEHICLEVALIDATOR_H
