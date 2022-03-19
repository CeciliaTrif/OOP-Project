#ifndef PROIECTOOP_VEHICLEVALIDATOR_H
#define PROIECTOOP_VEHICLEVALIDATOR_H
#include "Vehicle.h"
#include "ValidationException.h"
#include "cstring"
#include "set"

class VehicleValidator {
public:
    VehicleValidator();
    virtual ~VehicleValidator();

    virtual void validate(Vehicle*) noexcept(false);
//    void removeIdentificationNumber(string); TODO
};


#endif //PROIECTOOP_VEHICLEVALIDATOR_H
