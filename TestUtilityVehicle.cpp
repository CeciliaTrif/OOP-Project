#include "TestUtilityVehicle.h"
#include "UtilityVehicle.h"
#include "cassert"

void TestUtilityVehicle::testImplicitConstructor() {
    UtilityVehicle utilityVehicle;
    assert(utilityVehicle.getIsStreetLegal().empty());
    assert(utilityVehicle.getType().empty());
}

void TestUtilityVehicle::testConstructorWithParameters() {
    UtilityVehicle utilityVehicle("12ASD","Toyota Motors", "Sora", "Alb", "Nu", 30, "Da", "autobuz");
    assert(utilityVehicle.getIsStreetLegal() == "Da");
    assert(utilityVehicle.getType() == "autobuz");
}

void TestUtilityVehicle::testCopyConstructor() {
    UtilityVehicle utilityVehicle1("12ASD","Toyota Motors", "Sora", "Alb", "Nu", 30, "Da", "autobuz");
    UtilityVehicle utilityVehicle2(utilityVehicle1);
    assert(utilityVehicle2.getIsStreetLegal() == "Da");
    assert(utilityVehicle2.getType() == "autobuz");
}

void TestUtilityVehicle::testSetIsStreetLegal() {
    UtilityVehicle utilityVehicle("12ASD","Toyota Motors", "Sora", "Alb", "Nu", 30, "Da", "autobuz");
    utilityVehicle.setIsStreetLegal("Nu");
    assert(utilityVehicle.getIsStreetLegal() == "Nu");
}

void TestUtilityVehicle::testSetType() {
    UtilityVehicle utilityVehicle("12ASD","Toyota Motors", "Sora", "Alb", "Nu", 30, "Da", "autobuz");
    utilityVehicle.setType("tractor");
    assert(utilityVehicle.getType() == "tractor");
}

void TestUtilityVehicle::testAssignmentOperator() {
    UtilityVehicle utilityVehicle1("12ASD","Toyota Motors", "Sora", "Alb", "Nu", 30, "Da", "autobuz");
    UtilityVehicle utilityVehicle2;
    utilityVehicle2 = utilityVehicle1;
    assert(utilityVehicle2.getIsStreetLegal() == "Da");
    assert(utilityVehicle2.getType() == "autobuz");
}

void TestUtilityVehicle::testEqualityOperator() {
    UtilityVehicle utilityVehicle1("12ASD","Toyota Motors", "Sora", "Alb", "Nu", 30, "Da", "autobuz");
    UtilityVehicle utilityVehicle2("12ASD","Toyota Motors", "Sora", "Alb", "Nu", 30, "Da", "autobuz");
    assert(utilityVehicle1 == utilityVehicle2);
}

void TestUtilityVehicle::testAll() {
    testImplicitConstructor();
    testConstructorWithParameters();
    testCopyConstructor();

    testSetIsStreetLegal();
    testSetType();

    testAssignmentOperator();
    testEqualityOperator();
}