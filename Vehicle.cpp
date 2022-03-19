#include "Vehicle.h"
#include "Utils.h"
#include <utility>

Vehicle::Vehicle() {
    this->identificationNumber = "";
    this->brand = "";
    this->name = "";
//    this->registrationNumber = "";
//    this->engine = "";
//    this->transmissionSystem = "";
    this->color = "";
    this->isRented = "";
    this->price = 0;

}

Vehicle::~Vehicle() = default;

Vehicle::Vehicle(string identificationNumber, string brand, string name, string color, string rented, double price) {
    this->identificationNumber = std::move(identificationNumber);
    this->brand = std::move(brand);
    this->name = std::move(name);
    this->color = std::move(color);
    this->isRented = std::move(rented);
    this->price = price;
}

Vehicle::Vehicle(const Vehicle &vehicle) {
    this->identificationNumber = vehicle.identificationNumber;
    this->brand = vehicle.brand;
    this->name = vehicle.name;
    this->color = vehicle.color;
    this->isRented = vehicle.isRented;
    this->price = vehicle.price;
}


string Vehicle::getIdentificationNumber() {
    return this->identificationNumber;
}

string Vehicle::getBrand() {
    return this->brand;
}

string Vehicle::getName() {
    return this->name;
}

string Vehicle::getColor() {
    return this->color;
}

string Vehicle::getRented() {
    return this->isRented;
}

double Vehicle::getPrice() {
    return this->price;
}

void Vehicle::setIdentificationNumber(string newIdentificationNumber) {
    this->identificationNumber = std::move(newIdentificationNumber);
}

void Vehicle::setBrand(string newBrand) {
    this->brand = std::move(newBrand);
}

void Vehicle::setName(string newName) {
    this->name = std::move(newName);
}

void Vehicle::setColor(string newColor) {
    this->color = std::move(newColor);
}

void Vehicle::setRented(string newRented) {
    this->isRented = std::move(newRented);
}

void Vehicle::setPrice(double newPrice) {
    this->price = newPrice;
}

Vehicle *Vehicle::clone() {
    return new Vehicle(this->identificationNumber, this->brand, this->name,
                       this->color, this->isRented, this->price);
}

Vehicle &Vehicle::operator=(const Vehicle &vehicle) {
    if (&vehicle != this) {
        this->setIdentificationNumber(vehicle.identificationNumber);
        this->setName(vehicle.name);
        this->setBrand(vehicle.brand);
        this->setColor(vehicle.color);
        this->setRented(vehicle.isRented);
        this->setPrice(vehicle.price);
    }
    return *this;
}

bool Vehicle::operator==(const Vehicle &vehicle) const {
    return this->identificationNumber == vehicle.identificationNumber && this->name == vehicle.name &&
           this->brand == vehicle.brand && this->color == vehicle.color && this->isRented == vehicle.isRented &&
           this->price == vehicle.price;
}

string Vehicle::toString(bool fileData) {
    return this->identificationNumber + " " + this->brand + " " + this->name + " " + this->color + " " +
           this->isRented + " " + doubleToString(this->price);
}