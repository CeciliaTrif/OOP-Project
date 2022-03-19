#ifndef PROIECTOOP_REPOSITORY_H
#define PROIECTOOP_REPOSITORY_H
#include <vector>
#include "Vehicle.h"
#include "CarValidator.h"
#include "UtilityVehicleValidator.h"
#include "RepositoryException.h"

class Repository {
protected:
    vector<Vehicle*> vehicles;
    CarValidator carValidator;
    UtilityVehicleValidator utilityVehicleValidator;

public:
    Repository();
    virtual ~Repository();

    vector<Vehicle*> getAll();
    int getSize();
    Vehicle* getByPosition(int) noexcept(false);

    virtual void addVehicle(Vehicle*) noexcept(false);
    virtual void deleteVehicle(Vehicle*) noexcept(false);
    virtual void updateVehicle(Vehicle*, Vehicle*) noexcept(false);

    int findVehicle(Vehicle*);
    void empty();
};


#endif //PROIECTOOP_REPOSITORY_H
