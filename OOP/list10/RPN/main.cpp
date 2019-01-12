#include <iostream>
#include "Stack.h"
#include "RPN.h"
#include <string>
#include <sstream>

using namespace std;

int main() {
    RPN *rnp;
    rnp = new RPN("2 + 2 * 2");
    cout << "\nfinal result = " << rnp->calculate() << endl;

    rnp = new RPN("3 / 3 * ( 1 + 2 )");
    cout << "\nfinal result = " << rnp->calculate() << endl;

    rnp = new RPN("1 + 2 * 3 / 4 - 5");
    cout << "\nfinal result = " << rnp->calculate() << endl;

    rnp = new RPN("( 10 + 5 ) / 3") ;
    cout << "\nfinal result = " << rnp->calculate() << endl;
    return 0;
}