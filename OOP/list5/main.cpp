#include <iostream>
#include <iomanip>
#include "Rectangle.h"
#include "ArabianNumbers.h"

using namespace std;

int getOption() {
    char c;
    cin >> c;
    c -= '0';
    cin.clear();
    cin.ignore(255, '\n');
    return c;
}

void handleInvalidInput() {
    cin.clear();
    cin.ignore(255, '\n');
    cerr << "\n Invalid input! Provide proper values: " << endl << ' ';
}

int main() {
    cout << setprecision(2) << fixed;
    int intOption;
    Rectangle *ptr = nullptr;

    do {
        cout
                << "\n1: create and use new Rectangle\n2: create and use new Cuboid\n3: get area\n4: get diagonal\n0: quit\n"
                << endl;

        intOption = getOption();

        if (intOption == 0) break;

        switch (intOption) {
            case 1: {
                int a, b;
                cout << "Enter the dimensions of the Rectangle: ";
                while (!(cin >> a >> b)) {
                    handleInvalidInput();
                }
                delete ptr;
                ptr = new Rectangle(a, b);
                break;
            }
            case 2: {
                int a, b, c;
                cout << "Enter the dimensions of the Cuboid: ";
                while (!(cin >> a >> b >> c)) {
                    handleInvalidInput();
                }
                delete ptr;
                ptr = new Cuboid(a, b, c);
                break;
            }
            case 3: {
                if (ptr == nullptr) {
                    cerr << "\n pointer not initialised!\n" << endl;
                    break;
                }
                cout << "Area = " << ptr->area() << endl;
                break;
            }
            case 4: {
                if (ptr == nullptr) {
                    cerr << "\n pointer not initialised!\n" << endl;
                    break;
                }
                cout << "diagonal = " << ptr->diagonal() << endl;
                break;
            }
            default: {
                cerr << "\n invalid number of option!\n" << endl;
            }

        }

    } while (intOption != 0);


    cout << "\nARABIAN\n" << endl;

    ArabianNumbers *number = new ArabianNumbers(15);
    number = new ArabianNumbers(494);
    number->printNum();

    cout << "\nROMAN\n" << endl;

    number = new RomanNumbers(494);
    number->printNum();
    return 0;
}
