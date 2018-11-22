//
// Created by pawel on 18.11.18.
//

#include <iostream>
#include "ClassesVirtual.h"

using namespace std;

void VehicleVirtual::handleInvalidInput() {
    cin.clear();
    cin.ignore(255, '\n');
    cerr << "\n Invalid input! Provide proper values: " << endl << ' ';
}


VehicleVirtual::VehicleVirtual(float f, float fUsPer100) : fuel(f), fuelUsagePer100(fUsPer100) {}

void VehicleVirtual::drive() {
    float temp;
    while (!(cin >> temp)) {
        handleInvalidInput();
    }
    this->fuel -= this->fuelUsagePer100 * temp / 100;
    if (this->fuel <= 0) {
        cout << "\n~No more fuel!\n" << endl;
        this->fuel = 0;
    } else {
        cout << "\n~Fuel left = " << this->fuel << endl << endl;
    }
}

void VehicleVirtual::horn() {
    cout << "\n~Beep Beep\n" << endl;
}

void VehicleVirtual::tank() {
    float temp;
    while (!(cin >> temp)) {
        handleInvalidInput();
    }
    this->fuel += temp;

    cout << "\n~New fuel level = " << this->fuel << endl << endl;
}

VehicleVirtual::VehicleVirtual() = default;

CarVirtual::CarVirtual(float f, float fUsPer100, int w) : VehicleVirtual(f, fUsPer100), numberOfWheels(w) {}

void CarVirtual::displayNumbOfWheels() {
    cout << "\n~Number of wheels = " << this->numberOfWheels << endl << endl;
}

BoatVirtual::BoatVirtual(float f, float fUsPer100, int s) : VehicleVirtual(f, fUsPer100), numberOfSails(s) {}

void BoatVirtual::displayNumbOfSails() {
    cout << "\n~Number of sails = " << this->numberOfSails << endl << endl;
}

AmphibiousVirtual::AmphibiousVirtual(float f, float fUsPer100, int w, int s) : CarVirtual(f, fUsPer100, w),
                                                                                 BoatVirtual(f, fUsPer100, s) {}

