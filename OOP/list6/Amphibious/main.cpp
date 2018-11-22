#include <iostream>
#include "ClassesStandard.h"
#include "ClassesVirtual.h"
#include <iomanip>

using namespace std;

int getOption() {
    char c;
    cin >> c;
    c -= '0';
    cin.clear();
    cin.ignore(255, '\n');
    return c;
}

void testVehicleStandard(VehicleStandard *v) {
    int intOption;
    char option;
    cout << "\nusing VehicleStandard\n1: tank fuel\n2: drive\n3: use horn\n0: return\n" << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                delete v;
                return;
            }
            case 1: {
                v->tank();
                break;
            }
            case 2: {
                v->drive();
                break;
            }
            case 3: {
                v->horn();
                break;
            }
            default: {
                cerr << "\n~invalid number of option!\n" << endl;
            }
        }
        cout << "\nusing VehicleStandard\n1: tank fuel\n2: drive\n3: use horn\n0: return\n" << endl;
    }
}

void testCarStandard(CarStandard *c) {
    int intOption;
    char option;
    cout << "\nusing CarStandard\n1: tank fuel\n2: drive\n3: use horn\n4: get number of wheels\n0: return\n" << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                delete c;
                return;
            }
            case 1: {
                c->tank();
                break;
            }
            case 2: {
                c->drive();
                break;
            }
            case 3: {
                c->horn();
                break;
            }
            case 4: {
                c->displayNumbOfWheels();
                break;
            }
            default: {
                cerr << "\n~invalid number of option!\n" << endl;
            }
        }
        cout << "\nusing CarStandard\n1: tank fuel\n2: drive\n3: use horn\n4: get number of wheels\n0: return\n"
             << endl;
    }
}

void testBoatStandard(BoatStandard *b) {
    int intOption;
    char option;
    cout << "\nusing BoatStandard\n1: tank fuel\n2: drive\n3: use horn\n4: get number of sails\n0: return\n" << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                delete b;
                return;
            }
            case 1: {
                b->tank();
                break;
            }
            case 2: {
                b->drive();
                break;
            }
            case 3: {
                b->horn();
                break;
            }
            case 4: {
                b->displayNumbOfSails();
                break;
            }
            default: {
                cerr << "\n~invalid number of option!\n" << endl;
            }
        }
        cout << "\nusing BoatStandard\n1: tank fuel\n2: drive\n3: use horn\n4: get number of sails\n0: return\n"
             << endl;
    }
}

void testAmphibiousStandard(AmphibiousStandard *a) {
    int intOption;
    char option;
    cout
            << "\nusing AmphibiousStandard\n1: tank fuel\n2: drive\n3: use horn\n4: get number of sails\n5: get number of wheels\n0: return\n"
            << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                delete a;
                return;
            }
            case 1: {
                a->tank();
                break;
            }
            case 2: {
                a->drive();
                break;
            }
            case 3: {
                a->horn();
                break;
            }
            case 4: {
                a->displayNumbOfSails();
                break;
            }
            case 5: {
                a->displayNumbOfWheels();
                break;
            }
            default: {
                cerr << "\n~invalid number of option!\n" << endl;
            }
        }
        cout
                << "\nusing AmphibiousStandard\n1: tank fuel\n2: drive\n3: use horn\n4: get number of sails\n5: get number of wheels\n0: return\n"
                << endl;
    }
}
//// virtual

void testVehicleVirtual(VehicleVirtual *v) {
    int intOption;
    char option;
    cout << "\nusing VehicleVirtual\n1: tank fuel\n2: drive\n3: use horn\n0: return\n" << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                delete v;
                return;
            }
            case 1: {
                v->tank();
                break;
            }
            case 2: {
                v->drive();
                break;
            }
            case 3: {
                v->horn();
                break;
            }
            default: {
                cerr << "\n~invalid number of option!\n" << endl;
            }
        }
        cout << "\nusing VehicleVirtual\n1: tank fuel\n2: drive\n3: use horn\n0: return\n" << endl;
    }
}

void testCarVirtual(CarVirtual *c) {
    int intOption;
    char option;
    cout << "\nusing CarVirtual\n1: tank fuel\n2: drive\n3: use horn\n4: get number of wheels\n0: return\n" << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                delete c;
                return;
            }
            case 1: {
                c->tank();
                break;
            }
            case 2: {
                c->drive();
                break;
            }
            case 3: {
                c->horn();
                break;
            }
            case 4: {
                c->displayNumbOfWheels();
                break;
            }
            default: {
                cerr << "\n~invalid number of option!\n" << endl;
            }
        }
        cout << "\nusing CarVirtual\n1: tank fuel\n2: drive\n3: use horn\n4: get number of wheels\n0: return\n"
             << endl;
    }
}

void testBoatVirtual(BoatVirtual *b) {
    int intOption;
    char option;
    cout << "\nusing BoatVirtual\n1: tank fuel\n2: drive\n3: use horn\n4: get number of sails\n0: return\n" << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                delete b;
                return;
            }
            case 1: {
                b->tank();
                break;
            }
            case 2: {
                b->drive();
                break;
            }
            case 3: {
                b->horn();
                break;
            }
            case 4: {
                b->displayNumbOfSails();
                break;
            }
            default: {
                cerr << "\n~invalid number of option!\n" << endl;
            }
        }
        cout << "\nusing BoatVirtual\n1: tank fuel\n2: drive\n3: use horn\n4: get number of sails\n0: return\n"
             << endl;
    }
}

void testAmphibiousVirtual(AmphibiousVirtual *a) {
    int intOption;
    char option;
    cout
            << "\nusing AmphibiousVirtual\n1: tank fuel\n2: drive\n3: use horn\n4: get number of sails\n5: get number of wheels\n0: return\n"
            << endl;
    while (cin >> option) {
        intOption = option - '0';
        cin.clear();
        cin.ignore(255, '\n');

        switch (intOption) {
            case 0: {
                delete a;
                return;
            }
            case 1: {
                a->tank();
                break;
            }
            case 2: {
                a->drive();
                break;
            }
            case 3: {
                a->horn();
                break;
            }
            case 4: {
                a->displayNumbOfSails();
                break;
            }
            case 5: {
                a->displayNumbOfWheels();
                break;
            }
            default: {
                cerr << "\n~invalid number of option!\n" << endl;
            }
        }
        cout
                << "\nusing AmphibiousVirtual\n1: tank fuel\n2: drive\n3: use horn\n4: get number of sails\n5: get number of wheels\n0: return\n"
                << endl;
    }
}

int main() {
    cout << setprecision(2) << fixed;
    int intOption;
    cout << "~~~ Standard Inheritance ~~~" << endl;
    do {
        cout
                << "\n1: create and use new VehicleStandard" \
                   "\n2: create and use new CarStandard" \
                   "\n3: create and use new BoatStandard" \
                   "\n4: create and use new AmphibiousStandard"\
                   "\n0: quit\n"
                << endl;

        intOption = getOption();

        if (intOption == 0) break;

        switch (intOption) {
            case 1: {
                testVehicleStandard(new VehicleStandard(56.6, 8.7));
                break;
            }
            case 2: {
                testCarStandard(new CarStandard(56.6, 8.7, 4));
                break;
            }
            case 3: {
                testBoatStandard(new BoatStandard(56.6, 8.7, 1));
                break;
            }
            case 4: {
                testAmphibiousStandard(new AmphibiousStandard(56.6, 8.7, 4, 0));
                break;
            }
            default: {
                cerr << "\n~invalid number of option!\n" << endl;
            }

        }

    } while (intOption != 0);

    cout << "~~~ Virtual Inheritance ~~~" << endl;

    do {
        cout
                << "\n1: create and use new VehicleVirtual" \
                   "\n2: create and use new CarVirtual" \
                   "\n3: create and use new BoatVirtual" \
                   "\n4: create and use new AmphibiousVirtual"\
                   "\n0: quit\n"
                << endl;

        intOption = getOption();

        if (intOption == 0) break;

        switch (intOption) {
            case 1: {
                testVehicleVirtual(new VehicleVirtual(56.6, 8.7));
                break;
            }
            case 2: {
                testCarVirtual(new CarVirtual(56.6, 8.7, 4));
                break;
            }
            case 3: {
                testBoatVirtual(new BoatVirtual(56.6, 8.7, 2));
                break;
            }
            case 4: {
                testAmphibiousVirtual(new AmphibiousVirtual(56.6, 8.7, 4, 0));
                break;
            }
            default: {
                cerr << "\n invalid number of option!\n" << endl;
            }

        }

    } while (intOption != 0);


    return 0;
}