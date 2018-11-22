//
// Created by pawel on 18.11.18.
//

#include <iostream>
#include "ClassesStandard.h"

using namespace std;

void VehicleStandard::handleInvalidInput() {
    cin.clear();
    cin.ignore(255, '\n');
    cerr << "\n Invalid input! Provide proper values: " << endl << ' ';
}


VehicleStandard::VehicleStandard(float f, float fUsPer100) : fuel(f), fuelUsagePer100(fUsPer100) {}

void VehicleStandard::drive() {
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

void VehicleStandard::horn() {
    cout << "\n~Beep Beep\n" << endl;
}

void VehicleStandard::tank() {
    float temp;
    while (!(cin >> temp)) {
        handleInvalidInput();
    }
    this->fuel += temp;

    cout << "\n~New fuel level = " << this->fuel << endl << endl;
}

CarStandard::CarStandard(float f, float fUsPer100, int w) : VehicleStandard(f, fUsPer100), numberOfWheels(w) {}

void CarStandard::displayNumbOfWheels() {
    cout << "\n~Number of wheels = " << this->numberOfWheels << endl << endl;
}

BoatStandard::BoatStandard(float f, float fUsPer100, int s) : VehicleStandard(f, fUsPer100), numberOfSails(s) {}

void BoatStandard::displayNumbOfSails() {
    cout << "\n~Number of sails = " << this->numberOfSails << endl << endl;
}

AmphibiousStandard::AmphibiousStandard(float f, float fUsPer100, int w, int s) : CarStandard(f, fUsPer100, w),
                                                                                 BoatStandard(f, fUsPer100, s) {}

void AmphibiousStandard::tank() {
    CarStandard::tank();
}

void AmphibiousStandard::drive() {
    CarStandard::drive();
}

void AmphibiousStandard::horn() {
    BoatStandard::horn();
}

