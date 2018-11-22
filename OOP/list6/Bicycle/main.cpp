#include <iostream>
#include "Bicycle.h"

using namespace std;

int getOption() {
    char c;
    cin >> c;
    c -= '0';
    cin.clear();
    cin.ignore(255, '\n');
    return c;
}

void testBicycleStandard(Bicycle *b) {
    int intOption;
    char option;
    cout << "\nusing Bicycle\n"
            "1: check if lamp is on\n"
            "2: switch the lamp\n"
            "3: check length of the chain\n"
            "4: check how many lumens the diode has\n"
            "5: check the quality of the gum\n"
            "6: check the name of the lubricant\n"
            "7: check the diameter of the wheel\n"
            "0: return\n" << endl;
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
                cout << "\n~The lamp is " << (b->isLampOn ? "on" : "off") << endl << endl;
                break;
            }
            case 2: {
                b->switchLampOn_Off();
                cout << "\n~The lamp is " << (b->isLampOn ? "on" : "off") << endl << endl;
                break;
            }
            case 3: {
                cout << "\nThe chain has length = " << b->chainLength << endl << endl;
                break;
            }
            case 4: {
                cout << "\n~The diode has " << b->diodeLumens << " lumens\n" << endl;
                break;
            }
            case 5: {
                cout << "\n~The gum is of quality " << b->gumQuality << endl << endl;
                break;
            }
            case 6: {
                cout << "\n~The lubricant has name " << b->lubricantName << endl << endl;
                break;
            }
            case 7: {
                cout << "\n~The wheel diameter has " << b->wheelDiameterLength << " inches" << endl << endl;
                break;
            }
            default: {
                cerr << "\n~invalid number of option!\n" << endl;
            }
        }
        cout << "Using Bicycle\n"
                "1: check if lamp is on\n"
                "2: switch the lamp\n"
                "3: check length of the chain\n"
                "4: check how many lumens the diode has\n"
                "5: check the quality of the gum\n"
                "6: check the name of the lubricant\n"
                "7: check the diameter of the wheel\n"
                "0: return\n" << endl;
    }
}

int main() {
    testBicycleStandard(new Bicycle(500,'B',29,"Pretty Oil",1.2));
    return 0;
}