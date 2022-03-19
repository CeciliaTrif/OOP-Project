#ifndef PROIECTOOP_CAR_H
#define PROIECTOOP_CAR_H
#include "Vehicle.h"

class Car : public Vehicle {
private:
    string isSport;
    string type;

public:
    Car();
    Car(string, string , string , string , string , double, string, string);
    Car(const Car&);
    ~Car() override;

    string getIsSport();
    string getType();

    void setIsSport(string);
    void setType(string);

    Car* clone() override;
    Car& operator=(const Car &car);
    bool operator==(const Car &car);

    string toString(bool fileData) override;
};


#endif //PROIECTOOP_CAR_H
