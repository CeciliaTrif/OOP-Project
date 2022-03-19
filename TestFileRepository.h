#ifndef PROIECTOOP_TESTFILEREPOSITORY_H
#define PROIECTOOP_TESTFILEREPOSITORY_H
#include "FileRepository.h"
#include "vector"


class TestFileRepository {
private:
    const string fileNameIn = "C:/Users/trifc/CLionProjects/ProiectOOP/testVehiclesIn.txt";
    const string fileNameOut = "C:/Users/trifc/CLionProjects/ProiectOOP/testVehiclesOut.txt";
    const string fileNameInvalid = "C:/Users/trifc/CLionProjects/ProiectOOP/testInvalidVehicles.txt";
    vector<Vehicle*> vehicles;

//    void testLoadFromFile();
    void testSaveToFile();

//    void testAddVehicle();
//    void testDeleteVehicle();
//    void testUpdateVehicle();

public:
    TestFileRepository();
    ~TestFileRepository();
    void testAll();

};


#endif //PROIECTOOP_TESTFILEREPOSITORY_H
