#ifndef PROIECTOOP_TESTREPOSITORY_H
#define PROIECTOOP_TESTREPOSITORY_H
#include "vector"
#include "Vehicle.h"

class TestRepository {
private:
    vector<Vehicle*> vehicles;

    void testGetAll();
    void testGetSize();
    void testGetByPosition();

    void testAddVehicle();
    void testDeleteVehicle();
    void testUpdateVehicle();


public:
    TestRepository();
    ~TestRepository();
    void testAll();
};


#endif //PROIECTOOP_TESTREPOSITORY_H
