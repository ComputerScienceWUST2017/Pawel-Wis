//
// Created by pawel on 08.11.18.
//

#include <iostream>
#include "VehicleAggreg.h"

void CarAggreg::displayNumOfDoors() {
    std::cout<<"number of doors = "<<this->numberOfDoors<<std::endl;
}

////////

void BusAggreg::displayNumOfWindows() {
    std::cout<<"number of doors = "<<this->numberOfWindows<<std::endl;
}

/////////

void VehicleAggreg::useHorn() {
    std::cout << " *beep beep* " << std::endl;
}

void VehicleAggreg::boostEngine(int byHowManyHorses) {
    std::cout << "  prev horsepower = " << horsepower;
    this->horsepower += byHowManyHorses;
    std::cout << ", new horsepower = " << horsepower << std::endl;
}

float VehicleAggreg::drive(float kilometers) {
    if (kilometers > maxRange()) {
        std::cout << "  not enough fuel" << std::endl;
        return this->currentFuel;
    }
    currentFuel -= this->fuelUsagePer100 * kilometers / 100;
    return currentFuel;
}

float VehicleAggreg::tankFuel(float amount) {
    return this->currentFuel = min(this->maxFuel, this->currentFuel + amount);
}

float VehicleAggreg::min(float a, float b) {
    return a < b ? a : b;
}

float VehicleAggreg::maxRange() {
    return this->currentFuel * 100 / this->fuelUsagePer100;
}