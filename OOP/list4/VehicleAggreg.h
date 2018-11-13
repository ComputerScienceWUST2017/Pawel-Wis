//
// Created by pawel on 08.11.18.
//

#ifndef LIST4_VEHICLEAGGREG_H
#define LIST4_VEHICLEAGGREG_H


class VehicleAggreg {

public:

    int horsepower;
    float maxFuel, currentFuel, fuelUsagePer100;

    float min(float a, float b);

    float tankFuel(float amount);

    float drive(float kilometers);

    void boostEngine(int byHowManyHorses);

    void useHorn();

    float maxRange();
};

///////

class CarAggreg{
public:
    VehicleAggreg v;
    int numberOfDoors;
    void displayNumOfDoors();
};

////////

class BusAggreg{
public:
    VehicleAggreg v;
    int numberOfWindows;
    void displayNumOfWindows();
};

////////

#endif //LIST4_VEHICLEAGGREG_H
