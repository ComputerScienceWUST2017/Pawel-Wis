//
// Created by Pawel on 05.11.2018.
//

#include <iostream>
#include <iomanip>
#include "VehicleInherit.h"

VehicleInherit::VehicleInherit(float mxFuel, float fUsPer100, int hp) : maxFuel(mxFuel), fuelUsagePer100(fUsPer100),
                                                                        horsepower(hp),
                                                                        currentFuel(mxFuel) {}


void VehicleInherit::useHorn() {
    std::cout << " *vehicle horn* " << std::endl;
}

void VehicleInherit::boostEngine(int byHowManyHorses) {
    std::cout << "  prev horsepower = " << horsepower;
    this->horsepower += byHowManyHorses;
    std::cout << ", new horsepower = " << horsepower << std::endl;
}

float VehicleInherit::drive(float kilometers) {
    if (kilometers > maxRange()) {
        std::cout << "  not enough fuel" << std::endl;
        return this->currentFuel;
    }
    currentFuel -= this->fuelUsagePer100 * kilometers / 100;
    return currentFuel;
}

float VehicleInherit::tankFuel(float amount) {
    return this->currentFuel = min(this->maxFuel, this->currentFuel + amount);
}

float VehicleInherit::min(float a, float b) {
    return a < b ? a : b;
}

float VehicleInherit::maxRange() {
    return this->currentFuel * 100 / this->fuelUsagePer100;
}

//////////////// CAR

CarInherit::CarInherit(float mxFuel, float fUsPer100, int hp, int nOfD) : VehicleInherit(mxFuel, fUsPer100, hp),
                                                                          numberOfDoors(nOfD) {}

void CarInherit::useHorn() {
    std::cout << " *car horn* " << std::endl;
}

void CarInherit::displayNumOfDoors() {
    std::cout << "number of doors = " << this->numberOfDoors << std::endl;
}

//////////////// BUS

void BusInherit::useHorn() {
    std::cout << " *bus horn* " << std::endl;
}

void BusInherit::displayNumOfWindows() {
    std::cout << "number of windows = " << this->numberOfWindows << std::endl;
}

BusInherit::BusInherit(float mxFuel, float fUsPer100, int hp, int nOfW) : VehicleInherit(mxFuel, fUsPer100, hp),
                                                                          numberOfWindows(nOfW) {}
