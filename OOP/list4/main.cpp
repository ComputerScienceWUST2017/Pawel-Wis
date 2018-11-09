#include <iostream>
#include <iomanip>
#include "VehicleInherit.h"
#include "VehicleAggreg.h"

using namespace std;


bool invalidInput() {
    if (!cin.good()) {
        cin.clear();
        cin.ignore(255, '\n');
        cout << "  invalid input!" << endl;
        return true;
    }
    return false;
}

void testVehicle(VehicleInherit *v) {
    int intOption;
    char option;
    cout << "\nusing VEHICLE\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n0: return\n"
         << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                return;
            }
            case 1: {
                float temp;
                do {
                    cout << "  enter how many fuel do you want to tank: ";
                    cin >> temp;
                } while (invalidInput());
                cout << "  new fuel level = " << v->tankFuel(temp) << 'l' << endl;
                break;
            }
            case 2: {
                float temp;
                do {
                    cout << "  enter how many kilometers do you want to drive: ";
                    cin >> temp;
                } while (invalidInput());
                float output = v->drive(temp);
                cout << "  new fuel level = " << output << 'l' << endl;
                break;
            }
            case 3: {
                int temp;
                do {
                    cout << "  enter how many horsepower do you want to add: ";
                    cin >> temp;
                } while (invalidInput());
                v->boostEngine(temp);
                break;
            }
            case 4: {
                v->useHorn();
                break;
            }
            case 5: {
                cout << "  your fuel level is enough to drive: " << v->maxRange() << "km" << endl;
                break;
            }
            default: {
                cout << "  invalid number of option!" << endl;
            }
        }
        cout << "\nusing VEHICLE\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n0: return\n"
             << endl;
    }
}

void testCar(CarInherit *c) {
    int intOption;
    char option;
    cout
            << "\nusing CAR\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n6: check number of doors\n0: return\n"
            << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                return;
            }
            case 1: {
                float temp;
                do {
                    cout << "  enter how many fuel do you want to tank: ";
                    cin >> temp;
                } while (invalidInput());
                cout << "  new fuel level = " << c->tankFuel(temp) << 'l' << endl;
                break;
            }
            case 2: {
                float temp;
                do {
                    cout << "  enter how many kilometers do you want to drive: ";
                    cin >> temp;
                } while (invalidInput());
                float output = c->drive(temp);
                cout << "  new fuel level = " << output << 'l' << endl;
                break;
            }
            case 3: {
                int temp;
                do {
                    cout << "  enter how many horsepower do you want to add: ";
                    cin >> temp;
                } while (invalidInput());
                c->boostEngine(temp);
                break;
            }
            case 4: {
                c->useHorn();
                break;
            }
            case 5: {
                cout << "  your fuel level is enough to drive: " << c->maxRange() << "km" << endl;
                break;
            }
            case 6: {
                c->displayNumOfDoors();
                break;
            }
            default: {
                cout << "  invalid number of option!" << endl;
            }
        }
        cout
                << "\nusing CAR\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n6: check number of doors\n0: return\n"
                << endl;
    }
}

void testBus(BusInherit *b) {
    int intOption;
    char option;
    cout
            << "\nusing BUS\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n6: check number of windows\n0: return\n"
            << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                return;
            }
            case 1: {
                float temp;
                do {
                    cout << "  enter how many fuel do you want to tank: ";
                    cin >> temp;
                } while (invalidInput());
                cout << "  new fuel level = " << b->tankFuel(temp) << 'l' << endl;
                break;
            }
            case 2: {
                float temp;
                do {
                    cout << "  enter how many kilometers do you want to drive: ";
                    cin >> temp;
                } while (invalidInput());
                float output = b->drive(temp);
                cout << "  new fuel level = " << output << 'l' << endl;
                break;
            }
            case 3: {
                int temp;
                do {
                    cout << "  enter how many horsepower do you want to add: ";
                    cin >> temp;
                } while (invalidInput());
                b->boostEngine(temp);
                break;
            }
            case 4: {
                b->useHorn();
                break;
            }
            case 5: {
                cout << "  your fuel level is enough to drive: " << b->maxRange() << "km" << endl;
                break;
            }
            case 6: {
                b->displayNumOfWindows();
                break;
            }
            default: {
                cout << "  invalid number of option!" << endl;
            }
        }
        cout
                << "\nusing BUS\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n6: check number of windows\n0: return\n"
                << endl;
    }
}


void testVehicleAgg(VehicleAggreg v) {
    int intOption;
    char option;
    cout << "\nusing VEHICLE\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n0: return\n"
         << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                return;
            }
            case 1: {
                float temp;
                do {
                    cout << "  enter how many fuel do you want to tank: ";
                    cin >> temp;
                } while (invalidInput());
                cout << "  new fuel level = " << v.tankFuel(temp) << 'l' << endl;
                break;
            }
            case 2: {
                float temp;
                do {
                    cout << "  enter how many kilometers do you want to drive: ";
                    cin >> temp;
                } while (invalidInput());
                float output = v.drive(temp);
                cout << "  new fuel level = " << output << 'l' << endl;
                break;
            }
            case 3: {
                int temp;
                do {
                    cout << "  enter how many horsepower do you want to add: ";
                    cin >> temp;
                } while (invalidInput());
                v.boostEngine(temp);
                break;
            }
            case 4: {
                v.useHorn();
                break;
            }
            case 5: {
                cout << "  your fuel level is enough to drive: " << v.maxRange() << "km" << endl;
                break;
            }
            default: {
                cout << "  invalid number of option!" << endl;
            }
        }
        cout << "\nusing VEHICLE\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n0: return\n"
             << endl;
    }
}



void testCarAgg(CarAggreg c) {
    int intOption;
    char option;
    cout
            << "\nusing CAR\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n6: check number of doors\n0: return\n"
            << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                return;
            }
            case 1: {
                float temp;
                do {
                    cout << "  enter how many fuel do you want to tank: ";
                    cin >> temp;
                } while (invalidInput());
                cout << "  new fuel level = " << c.v.tankFuel(temp) << 'l' << endl;
                break;
            }
            case 2: {
                float temp;
                do {
                    cout << "  enter how many kilometers do you want to drive: ";
                    cin >> temp;
                } while (invalidInput());
                float output = c.v.drive(temp);
                cout << "  new fuel level = " << output << 'l' << endl;
                break;
            }
            case 3: {
                int temp;
                do {
                    cout << "  enter how many horsepower do you want to add: ";
                    cin >> temp;
                } while (invalidInput());
                c.v.boostEngine(temp);
                break;
            }
            case 4: {
                c.v.useHorn();
                break;
            }
            case 5: {
                cout << "  your fuel level is enough to drive: " << c.v.maxRange() << "km" << endl;
                break;
            }
            case 6: {
                c.displayNumOfDoors();
                break;
            }
            default: {
                cout << "  invalid number of option!" << endl;
            }
        }
        cout
                << "\nusing CAR\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n6: check number of doors\n0: return\n"
                << endl;
    }
}


void testBusAgg(BusAggreg b) {
    int intOption;
    char option;
    cout
            << "\nusing BUS\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n6: check number of windows\n0: return\n"
            << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                return;
            }
            case 1: {
                float temp;
                do {
                    cout << "  enter how many fuel do you want to tank: ";
                    cin >> temp;
                } while (invalidInput());
                cout << "  new fuel level = " << b.v.tankFuel(temp) << 'l' << endl;
                break;
            }
            case 2: {
                float temp;
                do {
                    cout << "  enter how many kilometers do you want to drive: ";
                    cin >> temp;
                } while (invalidInput());
                float output = b.v.drive(temp);
                cout << "  new fuel level = " << output << 'l' << endl;
                break;
            }
            case 3: {
                int temp;
                do {
                    cout << "  enter how many horsepower do you want to add: ";
                    cin >> temp;
                } while (invalidInput());
                b.v.boostEngine(temp);
                break;
            }
            case 4: {
                b.v.useHorn();
                break;
            }
            case 5: {
                cout << "  your fuel level is enough to drive: " << b.v.maxRange() << "km" << endl;
                break;
            }
            case 6: {
                b.displayNumOfWindows();
                break;
            }
            default: {
                cout << "  invalid number of option!" << endl;
            }
        }
        cout
                << "\nusing BUS\n1: tank fuel\n2: drive\n3: boost engine\n4: use horn\n5: check range\n6: check number of windows\n0: return\n"
                << endl;
    }
}


int main() {
    cout << setprecision(1) << fixed;
    int intOption;
    char option;

    cout << "\n\n///////////////////////// INHERITANCE /////////////////////////\n\n" << endl;

    cout << "\n1: create and use new Vehicle\n2: create and use new Car\n3: create and use new Bus\n0: quit\n" << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        if (intOption == 0) break;

        switch (intOption) {
            case 1: {
                testVehicle(new VehicleInherit(78.2, 9.2, 120));
                break;
            }
            case 2: {
                testCar(new CarInherit(57.2, 6.1, 156, 3));
                break;
            }
            case 3: {
                testBus(new BusInherit(133.5, 8.8, 210, 17));
                break;
            }
            default: {
                cout << "  invalid number of option!" << endl;
            }

        }
        cout << "\n1: create and use new Vehicle\n2: create and use new Car\n3: create and use new Bus\n0: quit"
             << endl;

    }

    cout << "\n\n///////////////////////// AGGREGATION /////////////////////////\n\n" << endl;

    cout << "\n1: create and use new Vehicle\n2: create and use new Car\n3: create and use new Bus\n0: quit\n" << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        if (intOption == 0) break;

        switch (intOption) {
            case 1: {
                testVehicleAgg(VehicleAggreg{120,56.5,56.5,6.7});
                break;
            }
            case 2: {
                testCarAgg(CarAggreg{144,62.1,62.1,7.7,5});
                break;
            }
            case 3: {
                testBusAgg(BusAggreg{155,162.1,162.1,11.3,18});
                break;
            }
            default: {
                cout << "  invalid number of option!" << endl;
            }

        }
        cout << "\n1: create and use new Vehicle\n2: create and use new Car\n3: create and use new Bus\n0: quit"
             << endl;

    }

    return 0;
}