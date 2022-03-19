#include "TestVehicleValidator.h"
#include "VehicleValidator.h"
#include "CarValidator.h"
#include "UtilityVehicleValidator.h"
#include "ValidationException.h"
#include "cassert"

#include "iostream"

using namespace std;

TestVehicleValidator::TestVehicleValidator() = default;

TestVehicleValidator::~TestVehicleValidator() = default;

void TestVehicleValidator::testVehicleValidator() {
    VehicleValidator vehicleValidator;
    auto *vehicle1 = new Vehicle("12ASD","Toyota", "C-HR GR", "Rosu", "Nu", 30);
    try {

        vehicleValidator.validate(vehicle1);
    }
    catch (...) {
        assert(false);
    }

    auto *vehicle2 = new Vehicle("12ASD","Toyota12", "C-HR GR", "Rosu", "Nu", 30);
    try {

        vehicleValidator.validate(vehicle2);
        assert(false);
    }
    catch (ValidationException &error) {}
    catch (...) {
        assert(true);
    }

    auto *vehicle3 = new Vehicle("12ASD","Toyota", "C-HR GR", "Rosu", "Nu", -30);
    try {
        vehicleValidator.validate(vehicle3);
        assert(false);
    }
    catch (ValidationException &error) {}
    catch (...) {
        assert(true);
    }

    auto *vehicle4 = new Vehicle("12ASD","", "C-HR GR", "Rosu", "Nu", 30);
    try {
        vehicleValidator.validate(vehicle4);
        assert(false);
    }
    catch (ValidationException &error) {}
    catch (...) {
        assert(true);
    }

    auto *vehicle5 = new Vehicle("12ASD","Toyota", "", "Rosu", "Nu", 30);
    try {
        vehicleValidator.validate(vehicle5);
        assert(false);
    }
    catch (ValidationException &error) {}
    catch (...) {
        assert(true);
    }

    auto *vehicle6 = new Vehicle("12ASD","Toyota", "C-HR GR", "", "Nu", 30);
    try {
        vehicleValidator.validate(vehicle6);
        assert(false);

    }
    catch (ValidationException &error) {}
    catch (...) {
        assert(true);

    }


//    auto *vehicle7 = new Vehicle("", "C-HR GR", "", false, 30);
//    vehicleValidator.validate(vehicle7);


    delete vehicle1;
    delete vehicle2;
    delete vehicle3;
    delete vehicle4;
    delete vehicle5;
    delete vehicle6;
//    delete vehicle7;
}

void TestVehicleValidator::testCarValidator() {
    CarValidator carValidator;
    auto *car1 = new Car("12ASD","Toyota", "C-HR GR", "Rosu", "Nu", 30, "Nu", "hibrid");
    try {
        carValidator.validate(car1);
    }
    catch (...) {
        assert(false);
    }

    auto *car2 = new Car("12ASD","Toyota", "C-HR GR", "Rosu", "Nu", 30, "Nu", "");
    try {
        carValidator.validate(car2);
        assert(false);
    }
    catch (ValidationException &error) {}
    catch (...) {
        assert(false);
    }

    auto *car3 = new Car("12ASD","Toyota", "C-HR GR", "Rosu", "Nu", 30, "Nu", "asdf12344");
    try {
        carValidator.validate(car3);
        assert(false);
    }
    catch (ValidationException &error) {}
    catch (...) {
        assert(false);
    }

//    auto *car4 = new Car("Toyota", "C-HR GR", "Rosu", false, 30, false, "asdf12344");
//    carValidator.validate(car4);


    delete car1;
    delete car2;
    delete car3;
//    delete car4;
}

void TestVehicleValidator::testUtilityVehicleValidator() {
    UtilityVehicleValidator utilityVehicleValidator;
    auto *utilityVehicle1 = new UtilityVehicle("12ASD","Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "autobuz");
    try {
        utilityVehicleValidator.validate(utilityVehicle1);
    }
    catch(...) {
        assert(false);
    }

    auto *utilityVehicle2 = new UtilityVehicle("12ASD","Toyota", "C-HR GR", "Rosu", "Nu", 30, "Nu", "");
    try {
        utilityVehicleValidator.validate(utilityVehicle2);
        assert(false);
    }
    catch (ValidationException &error) {}
    catch (...) {
        assert(false);
    }

    auto *utilityVehicle3 = new UtilityVehicle("12ASD","Toyota", "C-HR GR", "Rosu", "Nu", 30, "Nu", "asdf12344");
    try {
        utilityVehicleValidator.validate(utilityVehicle3);
        assert(false);
    }
    catch (ValidationException &error) {}
    catch (...) {
        assert(false);
    }
}

void TestVehicleValidator::testAll() {
    testVehicleValidator();
    testCarValidator();
    testUtilityVehicleValidator();
}