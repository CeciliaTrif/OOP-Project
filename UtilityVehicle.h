#ifndef PROIECTOOP_UTILITYVEHICLE_H
#define PROIECTOOP_UTILITYVEHICLE_H

#include "Vehicle.h"

class UtilityVehicle : public Vehicle {
protected:
    string isStreetLegal;
    string type;

public:
    UtilityVehicle();
    UtilityVehicle(string, string, string, string, string, double, string, string);
    UtilityVehicle(const UtilityVehicle &utilityVehicle);
    ~UtilityVehicle() override;

    string getIsStreetLegal();
    void setIsStreetLegal(string);

    string getType();
    void setType(string type);

    UtilityVehicle *clone() override;
    UtilityVehicle &operator=(const UtilityVehicle &utilityVehicle);
    bool operator==(const UtilityVehicle &utilityVehicle);

    string toString(bool fileData) override;
};


#endif //PROIECTOOP_UTILITYVEHICLE_H
