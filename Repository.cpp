#include "Repository.h"
#include "typeinfo"

Repository::Repository() = default;

Repository::~Repository() {
    this->empty();
}

vector<Vehicle *> Repository::getAll() {
    return vehicles;
}

int Repository::getSize() {
    return vehicles.size();
}

Vehicle *Repository::getByPosition(int position) noexcept(false) {
    if (position < 0 or position >= vehicles.size()) {
        throw RepositoryException("Pozitie invalida!\n");
    }
    return vehicles[position];
}

void Repository::addVehicle(Vehicle *vehicle) noexcept(false) {
    if (typeid(*vehicle) == typeid(Car)) {
        this->carValidator.validate(vehicle);
    }

    if (typeid(*vehicle) == typeid(UtilityVehicle)) {
        this->utilityVehicleValidator.validate(vehicle);
    }

//    if (this->findVehicle(vehicle) != -1) {                                    // maybe change this
//        throw RepositoryException("Acest vehicul exista deja!\n");
//    }
    vehicles.push_back(vehicle->clone());
}

void Repository::deleteVehicle(Vehicle *vehicle) noexcept(false) {
    bool found = false;
    for (int i = 0; i < this->vehicles.size(); i++) {
        if (**(this->vehicles.begin() + i) == *vehicle) {
            delete this->vehicles[i];
            this->vehicles.erase(this->vehicles.begin() + i);
            i--;
            found = true;
        }
    }
    if (!found) throw RepositoryException("Eroare la stergere, vehiculul nu exista!\n");
}

void Repository::updateVehicle(Vehicle *currentVehicle, Vehicle *newVehicle) noexcept(false) {
    if (typeid(*newVehicle) == typeid(Car)) carValidator.validate(newVehicle);
    if (typeid(*newVehicle) == typeid(UtilityVehicle)) utilityVehicleValidator.validate(newVehicle);

    for (auto & vehicle : vehicles) {
        if (vehicle->getIdentificationNumber() == newVehicle->getIdentificationNumber()) {
            delete vehicle;
            vehicle = newVehicle->clone();
            return;
        }
    }
    throw RepositoryException("Eroare la update! Acest vehicul nu exista!\n");
}


void Repository::empty() {
    for (auto &vehicle : this->vehicles) {
        if (vehicle != nullptr) {
            delete vehicle;
            vehicle = nullptr;
        }
    }
    this->vehicles.clear();
}

int Repository::findVehicle(Vehicle *vehicle) { // todo test for this
    for (int i = 0; i < vehicles.size(); i++) {
        if (*this->vehicles[i] == *vehicle) {
            return i;
        }
    }
    return -1;
}