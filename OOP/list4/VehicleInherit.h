//
// Created by Pawel on 05.11.2018.
//

#ifndef LIST4_VEHICLE_H
#define LIST4_VEHICLE_H


class VehicleInherit {
protected:
    int horsepower;
    float maxFuel, fuelUsagePer100, currentFuel;

    float min(float a, float b);

public:
    VehicleInherit(float mxFuel, float fUsPer100, int hp);

    float tankFuel(float amount);

    float drive(float kilometers);

    void boostEngine(int byHowManyHorses);

    virtual void useHorn();

    float maxRange();
};

////////

class CarInherit: public VehicleInherit{
private:
    int numberOfDoors;
public:
    CarInherit(float mxFuel, float fUsPer100, int hp, int nOfD);
    void useHorn() override;
    void displayNumOfDoors();
};

////////

class BusInherit: public VehicleInherit{
private:
    int numberOfWindows;
public:
    BusInherit(float mxFuel, float fUsPer100, int hp, int nOfW);
    void useHorn() override;
    void displayNumOfWindows();
};
#endif //LIST4_VEHICLE_H
