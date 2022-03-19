#include "TestCar.h"
#include "Car.h"
#include "cassert"

void TestCar::testImplicitConstructor() {
    Car car;
    assert(car.getIsSport().empty());
    assert(car.getType().empty());
}

void TestCar::testConstructorWithParameters() {
    Car car("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "hibrid");
    assert(car.getIsSport() == "Da");
    assert(car.getType() == "hibrid");
}

void TestCar::testCopyConstructor() {
    Car car1("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "hibrid");
    Car car2(car1);
    assert(car2.getIsSport() == "Da");
    assert(car2.getType() == "hibrid");
}

void TestCar::testSetIsSport() {
    Car car("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "hibrid");
    car.setIsSport("Nu");
    assert(car.getIsSport() == "Nu");
}

void TestCar::testSetType() {
    Car car("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "hibrid");
    car.setType("diesel");
    assert(car.getType() == "diesel");
}

void TestCar::testAssignmentOperator() {
    Car car1("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "hibrid");
    Car car2;
    car2 = car1;
    assert(car2.getIsSport() == "Da");
    assert(car2.getType() == "hibrid");
}

void TestCar::testEqualityOperator() {
    Car car1("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "hibrid");
    Car car2("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "hibrid");
    assert(car2 == car1);
}

void TestCar::testAll() {
    testImplicitConstructor();
    testConstructorWithParameters();
    testCopyConstructor();

    testSetIsSport();
    testSetType();

    testAssignmentOperator();
    testEqualityOperator();
}