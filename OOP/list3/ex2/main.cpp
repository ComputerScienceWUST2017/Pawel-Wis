#include <iostream>
#include <string>
#include "Complex.h"

using namespace std;

int main() {
    Complex c1{};
    Complex c2{};
    string input;

    cout << endl;

    while (!cin.eof()) {
        getline(cin, input);
        bool first = sscanf(input.c_str(), "%f %f", &c1.real, &c1.imag) != 2 || cin.eof();
        getline(cin, input);
        bool second = sscanf(input.c_str(), "%f %f", &c2.real, &c2.imag) != 2;
        if (first || second) {
            cerr << "invalid input" << endl << endl;
        } else {
            Complex c3 = c1 + c2;
            cout << "sum = " << c3.real << " " << c3.imag << 'j' << endl;

            c3 = c1 - c2;
            cout << "diff = " << c3.real << " " << c3.imag << 'j' << endl;

            c3 = c1 * c2;
            cout << "prod = " << c3.real << " " << c3.imag << 'j' << endl;

            c3 = c1 / c2;
            cout << "quot = " << c3.real << " " << c3.imag << 'j' << endl << endl;

        }
    }


    return 0;
}