#include "UtilityVehicle.h"
using namespace std;

UtilityVehicle::UtilityVehicle() : Vehicle() {
    this->isStreetLegal = "";
    this->type = "";
}

UtilityVehicle::UtilityVehicle(string identificationNumber, string brand, string name, string color, string isRented, double price, string isStreetLegal,
                               string type) : Vehicle(move(identificationNumber), move(brand), move(name), move(color), move(isRented), price) {
    this->isStreetLegal = move(isStreetLegal);
    this->type = move(type);
}

UtilityVehicle::UtilityVehicle(const UtilityVehicle &utilityVehicle) : Vehicle(utilityVehicle) {
    this->isStreetLegal = utilityVehicle.isStreetLegal;
    this->type = utilityVehicle.type;
}

UtilityVehicle::~UtilityVehicle() = default;

string UtilityVehicle::getIsStreetLegal() {
    return this->isStreetLegal;
}

void UtilityVehicle::setIsStreetLegal(string newIsStreetLegal) {
    this->isStreetLegal = move(newIsStreetLegal);
}

string UtilityVehicle::getType() {
    return type;
}

void UtilityVehicle::setType(string newType) {
    UtilityVehicle::type = move(newType);
}

UtilityVehicle &UtilityVehicle::operator=(const UtilityVehicle &utilityVehicle) {
    if (&utilityVehicle != this) {
        Vehicle::operator=(utilityVehicle);
        setIsStreetLegal(utilityVehicle.isStreetLegal);
        setType(utilityVehicle.type);
    }
    return *this;
}

bool UtilityVehicle::operator==(const UtilityVehicle &utilityVehicle) {
    return Vehicle::operator==(utilityVehicle) && this->isStreetLegal == utilityVehicle.isStreetLegal &&
            this->type == utilityVehicle.type;
}

string UtilityVehicle::toString(bool fileData) {
    string s = Vehicle::toString(fileData) + " " + this->isStreetLegal + " " + this->type;
    if (fileData) {
        s = "UtilityVehicle " + s;
    }
    return s;
}

UtilityVehicle *UtilityVehicle::clone() {
    return new UtilityVehicle(this->identificationNumber, this->brand, this->name,
                              this->color, this->isRented, this->price, this->isStreetLegal,
                              this->type);
}

