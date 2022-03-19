#include "Car.h"

#include <utility>

Car::Car() {
    this->isSport = "";
//    this->isHybrid = false;
    this->type = "";
}

Car::Car(string identificationNumber, string brand, string name, string color, string isRented, double price,
         string isSport, string type) : Vehicle(std::move(identificationNumber), std::move(brand), std::move(name),
                                                std::move(color), std::move(isRented), price) {
    this->isSport = std::move(isSport);
    this->type = std::move(type);
}

Car::Car(const Car &car) : Vehicle(car) {
    this->isSport = car.isSport;
    this->type = car.type;
}

Car::~Car() = default;

string Car::getIsSport() {
    return this->isSport;
}

string Car::getType() {
    return this->type;
}

void Car::setIsSport(string newIsSport) {
    this->isSport = std::move(newIsSport);
}

void Car::setType(string newType) {
    this->type = std::move(newType);
}

Car &Car::operator=(const Car &car) {
    if (&car != this) {
        Vehicle::operator=(car);
        setIsSport(car.isSport);
        setType(car.type);
    }
    return *this;
}

bool Car::operator==(const Car &car) {
    return Vehicle::operator==(car) && this->isSport == car.isSport && this->type == car.type;
}

string Car::toString(bool fileData) {
    string s = Vehicle::toString(fileData) + " " + this->isSport + " " + this->type;
    if (fileData) {
        s = "Car " + s;
    }
    return s;
}

Car *Car::clone() {
    return new Car(this->identificationNumber, this->brand, this->name,
                   this->color, this->isRented, this->price, this->isSport, this->type);
}
