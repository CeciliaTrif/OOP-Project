#include <iostream>
#include "Car.h"
#include "TestVehicle.h"
#include "TestVehicleValidator.h"
#include "TestUtilityVehicle.h"
#include "TestCar.h"
#include "TestRepository.h"
#include "TestFileRepository.h"

int main() {
    TestVehicle::testAll();
    TestCar::testAll();
    TestUtilityVehicle::testAll();
    TestVehicleValidator::testAll();

    TestRepository testRepository;
    testRepository.testAll();
    TestFileRepository testFileRepository;
    testFileRepository.testAll();

}
