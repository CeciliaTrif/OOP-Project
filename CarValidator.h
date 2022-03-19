#ifndef PROIECTOOP_CARVALIDATOR_H
#define PROIECTOOP_CARVALIDATOR_H
#include "Car.h"
#include "VehicleValidator.h"

class CarValidator : public VehicleValidator{
public:
    CarValidator();
    ~CarValidator();
    void validate(Vehicle*) noexcept(false);
};


#endif //PROIECTOOP_CARVALIDATOR_H
