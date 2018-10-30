#include <iostream>
#include "TIME.h"

using namespace std;

int main() {
    const int numInputs = 20;
    TIME timeArr[numInputs];

    for (int i = 0; i < numInputs; ++i) {
        if (cin >> timeArr[i]) {
            cout << i << " "<<timeArr[i] << endl;
        } else {
            if (cin.eof()) break;
            cin.clear();
            --i;
        }
    }

    cout << endl << "add:" << endl;

    TIME temp{0, 0, 0};
    for (int i = 0; i < numInputs; ++i) {
        cout << temp << " + "<<timeArr[i]<< " = ";
        temp = temp + timeArr[i];
        cout << temp << endl;
    }

    cout << endl << "sub:" << endl;

    TIME temp2{0, 0, 0};
    for (int i = 0; i < numInputs; ++i) {
        cout << temp2 << " - "<<timeArr[i]<< " = ";
        temp2 = temp2 - timeArr[i];
        cout << temp2 <<endl;
    }
    return 0;
}