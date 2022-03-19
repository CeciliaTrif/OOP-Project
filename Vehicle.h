#ifndef PROIECTOOP_VEHICLE_H
#define PROIECTOOP_VEHICLE_H
#include <string>
using namespace std;

class Vehicle {
protected:
    string identificationNumber;
    string brand;
    string name;
//    string registrationNumber;
//    string engine;
//    string chassis;
//    string body;
    string color;
    string isRented;
    double price;

public:
    Vehicle();
    Vehicle(string, string , string , string , string , double);
    Vehicle(const Vehicle &);
    virtual ~Vehicle();

    string getIdentificationNumber();
    string getBrand();
    string getName();
    string getColor();
    string getRented();
    double getPrice();

    void setIdentificationNumber(string);
    void setBrand(string);
    void setName(string);
    void setColor(string);
    void setRented(string);
    void setPrice(double);

    virtual Vehicle* clone();
    Vehicle &operator=(const Vehicle &vehicle);
    bool operator==(const Vehicle &vehicle) const;

    virtual string toString(bool fileData);
};


#endif //PROIECTOOP_VEHICLE_H
