//
// Created by pawel on 19.11.18.
//

#ifndef AMPHIBIOUS_CLASSESVIRTUAL_H
#define AMPHIBIOUS_CLASSESVIRTUAL_H


class VehicleVirtual {
    float fuel, fuelUsagePer100;

    void handleInvalidInput();

public:
    VehicleVirtual();

    VehicleVirtual(float, float);


    void tank();

    void drive();

    void horn();
};

class CarVirtual : virtual public VehicleVirtual {
protected:
    int numberOfWheels;
public:

    CarVirtual(float, float, int);

    void displayNumbOfWheels();
};

class BoatVirtual : virtual public VehicleVirtual {
protected:
    int numberOfSails;
public:

    BoatVirtual(float, float, int);

    void displayNumbOfSails();
};

class AmphibiousVirtual : virtual public CarVirtual, virtual public BoatVirtual {
public:
    AmphibiousVirtual(float, float, int, int);

};


#endif //AMPHIBIOUS_CLASSESVIRTUAL_H
