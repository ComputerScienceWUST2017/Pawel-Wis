//
// Created by pawel on 18.11.18.
//

#ifndef AMPHIBIOUS_CLASSES_H
#define AMPHIBIOUS_CLASSES_H


class VehicleStandard {
    float fuel, fuelUsagePer100;

    void handleInvalidInput();

public:


    VehicleStandard(float, float);


    void tank();

    void drive();

    void horn();
};

class CarStandard : public VehicleStandard {
protected:
    int numberOfWheels;
public:

    CarStandard(float, float, int);

    void displayNumbOfWheels();
};

class BoatStandard : public VehicleStandard {
protected:
    int numberOfSails;
public:

    BoatStandard(float, float, int);

    void displayNumbOfSails();
};

class AmphibiousStandard : public CarStandard, public BoatStandard {
public:
    AmphibiousStandard(float, float, int, int);

    void tank();

    void drive();

    void horn();
};

#endif //AMPHIBIOUS_CLASSES_H
