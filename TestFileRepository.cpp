#include "TestFileRepository.h"
#include "cassert"
#include "Car.h"
#include "UtilityVehicle.h"
#include "iostream"
TestFileRepository::TestFileRepository() {
    Vehicle *vehicle1 = new Car("12ASD", "Toyota", "C-HR GR", "Rosu", "Nu", 30, "Da", "hibrid");
    Vehicle *vehicle2 = new UtilityVehicle("111A", "Toyota Motors", "Sora", "Alb", "Nu", 30, "Da", "autobuz");
    vehicles.push_back(vehicle1);
    vehicles.push_back(vehicle2);
}

TestFileRepository::~TestFileRepository() = default;

void TestFileRepository::testSaveToFile() {
    FileRepository fileRepository = FileRepository(fileNameIn);
    fileRepository.setFileName(fileNameOut);
    auto *newVehicle = new UtilityVehicle("111A", "Toyota Motors", "Sora", "Alb", "Nu", 30, "Da", "autobuz");
    fileRepository.addVehicle(newVehicle);
    fileRepository.deleteVehicle(newVehicle);
    fileRepository.saveToFile();
//    fileRepository.loadFromFile();
//    assert(fileRepository.getSize() == vehicles.size() + 1);
}


void TestFileRepository::testAll() {
    testSaveToFile();
}