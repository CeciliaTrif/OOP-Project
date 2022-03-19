#include <fstream>
#include <iostream>
#include "FileRepository.h"
#include "FileRepositoryException.h"
#include "Car.h"
#include "UtilityVehicle.h"


FileRepository::FileRepository() = default;

FileRepository::FileRepository(string fileName) {
    this->fileName = std::move(fileName);
    this->loadFromFile();
}

FileRepository::~FileRepository() = default;

void FileRepository::setFileName(string newFileName) {
    this->fileName = std::move(newFileName);
}

void FileRepository::loadFromFile() noexcept(false) {
    fstream file(fileName);

    if (file.is_open()) {
        this->empty();
        string line;
        string space = " ";
        try {
            while (getline(file, line)) {
                if (line.substr(0, 3) == "Car") {
                    line = line.erase(0, 3);

                    unsigned int pos = line.find(space);
                    string identificationNumber = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string brand = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string name = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string color = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string isRented = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    double price = stod(line.substr(0, pos));
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string isSport = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string type = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    auto *car = new Car(identificationNumber, brand, name, color, isRented, price, isSport, type);
                    this->carValidator.validate(car);
                    this->vehicles.push_back(car);

                } else if (line.substr(0, 14) == "UtilityVehicle") {
                    line = line.erase(0, 14);

                    unsigned int pos = line.find(space);
                    string identificationNumber = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string brand = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string name = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string color = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string isRented = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    double price = stod(line.substr(0, pos));
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string isStreetLegal = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    pos = line.find(space);
                    string type = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    auto *utilityVehicle = new UtilityVehicle(identificationNumber, brand, name, color, isRented, price, isStreetLegal, type);
                    this->utilityVehicleValidator.validate(utilityVehicle);
                    this->vehicles.push_back(utilityVehicle);
                }
            }
        }
        catch (...) {
            throw FileRepositoryException("Eroare la citirea din fisier! Datele sunt incorecte!\n");
        }
        file.close();
    }
    else {
        throw FileRepositoryException("Fisierul nu exista!\n");
    }
}

void FileRepository::saveToFile() {
    ofstream file(fileName);
    if (file.is_open()) {
        for (auto *vehicle : vehicles) {
            file << vehicle->toString(true) << endl;
        }
    }
}

void FileRepository::addVehicle(Vehicle *vehicle) noexcept(false) {
    Repository::addVehicle(vehicle);
    this->saveToFile();
}

void FileRepository::deleteVehicle(Vehicle *vehicle) noexcept(false) {
    Repository::deleteVehicle(vehicle);
    this->saveToFile();
}

void FileRepository::updateVehicle(Vehicle *currentVehicle, Vehicle *newVehicle) noexcept(false) {
    Repository::updateVehicle(currentVehicle, newVehicle);
    this->saveToFile();
}