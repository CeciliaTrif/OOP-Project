#include "TestVehicle.h"
#include "Vehicle.h"
#include <cassert>
#include "iostream"
void TestVehicle::testImplicitConstructor() {
    Vehicle vehicle;
    assert(vehicle.getIdentificationNumber().empty());
    assert(vehicle.getBrand().empty());
    assert(vehicle.getName().empty());
    assert(vehicle.getColor().empty());
    assert(vehicle.getRented().empty());
    assert(vehicle.getPrice() == 0);
}

void TestVehicle::testConstructorWithParameters() {
    Vehicle vehicle("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30);
    assert(vehicle.getIdentificationNumber() == "12ASD");
    assert(vehicle.getBrand() == "Toyota");
    assert(vehicle.getName() == "C-HR GR");
    assert(vehicle.getColor() == "Rosu");
    assert(vehicle.getRented() == "Nu");
    assert(vehicle.getPrice() == 30);
}

void TestVehicle::testCopyConstructor() {
    Vehicle vehicle1("12ASD", "Toyota", "C-HR GR", "Negru", "Da", 60);
    Vehicle vehicle2(vehicle1);
    assert(vehicle2.getIdentificationNumber() == "12ASD");
    assert(vehicle2.getBrand() == "Toyota");
    assert(vehicle2.getName() == "C-HR GR");
    assert(vehicle2.getColor() == "Negru");
    assert(vehicle2.getRented() == "Da");
    assert(vehicle2.getPrice() == 60);
}

void TestVehicle::testSetIdentificationNumber() {
    Vehicle vehicle("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30);
    assert(vehicle.getIdentificationNumber() == "12ASD");
    vehicle.setIdentificationNumber("111X");
    assert(vehicle.getIdentificationNumber() == "111X");
}

void TestVehicle::testSetBrand() {
    Vehicle vehicle("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30);
    assert(vehicle.getBrand() == "Toyota");
    vehicle.setBrand("Audi");
    assert(vehicle.getBrand() == "Audi");
}

void TestVehicle::testSetName() {
    Vehicle vehicle("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30);
    assert(vehicle.getName() == "C-HR GR");
    vehicle.setName("C-HR");
    assert(vehicle.getName() == "C-HR");
}

void TestVehicle::testSetColor() {
    Vehicle vehicle("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30);
    assert(vehicle.getColor() == "Rosu");
    vehicle.setName("Negru");
    assert(vehicle.getName() == "Negru");
}

void TestVehicle::testSetRented() {
    Vehicle vehicle("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30);
    assert(vehicle.getRented() == "Nu");
    vehicle.setRented("Da");
    assert(vehicle.getRented() == "Da");
}

void TestVehicle::testSetPrice() {
    Vehicle vehicle("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30);
    assert(vehicle.getPrice() == 30);
    vehicle.setPrice(60);
    assert(vehicle.getPrice() == 60);
}

void TestVehicle::testAssignmentOperator() {
    Vehicle vehicle1("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30);
    Vehicle vehicle2;
    vehicle2 = vehicle1;
    assert(vehicle2.getBrand() == "Toyota");
    assert(vehicle2.getRented() == "Nu");
}

void TestVehicle::testEqualityOperator() {
    Vehicle vehicle1("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30);
    Vehicle vehicle2;
    vehicle2 = vehicle1;
    assert(vehicle2 == vehicle1);
}

void TestVehicle::testAll() {
    testImplicitConstructor();
    testConstructorWithParameters();
    testCopyConstructor();

    testSetIdentificationNumber();
    testSetBrand();
    testSetName();
    testSetColor();
    testSetRented();
    testSetPrice();

    testAssignmentOperator();
    testEqualityOperator();
}