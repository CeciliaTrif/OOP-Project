#include "TestRepository.h"
#include "Car.h"
#include "UtilityVehicle.h"
#include "Repository.h"
#include "cassert"
#include "iostream"

TestRepository::TestRepository() {
    auto *vehicle1 = new Car("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "hibrid");
    auto *vehicle2 = new UtilityVehicle("111A", "Toyota Motors", "Sora", "Alb", "Nu", 30, "Da", "autobuz");
    vehicles.push_back(vehicle1);
    vehicles.push_back(vehicle2);
}

TestRepository::~TestRepository() {
    for (auto &vehicle : vehicles) {
        if (vehicle != nullptr) {
            delete vehicle;
            vehicle = nullptr;
        }
    }
    vehicles.clear();
}

void TestRepository::testGetAll() {
    Repository repository;
    for (auto &vehicle : vehicles) {
        repository.addVehicle(vehicle);
    }
    vector<Vehicle *> newVehicles = repository.getAll();

    assert(vehicles.size() == newVehicles.size());
    for (int i = 0; i < vehicles.size(); i++) {
        assert(*vehicles[i] == *newVehicles[i]);
    }
}

void TestRepository::testGetSize() {
    Repository repository;
    assert(repository.getSize() == 0);

    for (auto &vehicle : vehicles) {
        repository.addVehicle(vehicle);
    }
    assert(vehicles.size() == repository.getSize());
}

void TestRepository::testGetByPosition() {
    Repository repository;
    for (auto &vehicle : vehicles) {
        repository.addVehicle(vehicle);
    }
    vector<Vehicle *> vehicles_ = repository.getAll();

    for (int i = 0; i < vehicles.size(); i++) {
        assert(*repository.getByPosition(i) == *vehicles_[i]);
    }

    try {
        assert(repository.getByPosition(-1) == nullptr);
    }
    catch (RepositoryException &error) { assert(true); }
    catch (...) {
        assert(false);
    }

    try {
        assert(repository.getByPosition(repository.getSize()) == nullptr);
    }
    catch (RepositoryException &error) { assert(true); }
    catch (...) {
        assert(false);
    }
}

void TestRepository::testAddVehicle() {
    Repository repository;
    for (auto &vehicle : vehicles) {
        repository.addVehicle(vehicle);
    }

    auto *car = new Car("ASD-11", "Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "electrica");
    repository.addVehicle(car);
    assert(repository.getSize() == vehicles.size() + 1);
    assert(repository.findVehicle(car) != -1);


//    try {
//        repository.addVehicle(car);
//    }
//    catch (RepositoryException &error) {assert(true);}
//    catch (...) {
//        assert(false);
//    }
}

void TestRepository::testDeleteVehicle() {
    Repository repository;
    for (auto &vehicle : vehicles) {
        repository.addVehicle(vehicle);
    }

    assert(repository.getSize() == 2);
    repository.deleteVehicle(vehicles[0]);
    assert(repository.getSize() == 1);
    assert(repository.getAll()[0]->getIdentificationNumber() == "111A");

    auto *car = new Car("ASD-11", "Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "electrica");

    try {
        repository.deleteVehicle(car);
    }
    catch (RepositoryException &error) { assert(true); }
    catch (...) { assert(false); }
}

void TestRepository::testUpdateVehicle() {
    Repository repository;
    for (auto &vehicle : vehicles) {
        repository.addVehicle(vehicle);
    }
    assert(vehicles[0]->getColor() == "Rosu");
    assert(vehicles[0]->getRented() == "Nu");

    auto *vehicle1 = new Car("12ASD", "Toyota", "C-HR GR", "Albastru", "Da", 50, "Da", "hibrid");
    auto *vehicle2 = new Car("11111A", "Toyota", "C-HR GR", "Albastru", "Da", 50, "Da", "hibrid");

    repository.updateVehicle(vehicles[0], vehicle1);
    assert(repository.getAll()[0]->getColor() == "Albastru");
    assert(repository.getAll()[0]->getRented() == "Da");

    try {
        repository.updateVehicle(vehicles[0], vehicle2);
    }
    catch (RepositoryException &error) { assert(true); }
    catch (...) { assert(false); }
}

void TestRepository::testAll() {
    testGetAll();
    testGetSize();
    testGetByPosition();

    testAddVehicle();
    testDeleteVehicle();
    testUpdateVehicle();
}