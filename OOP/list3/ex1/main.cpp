#include <iostream>
#include "DATE.h"

using namespace std;


int main() {
    DATE *d1 = new DATE(25, 12, 2018);
    DATE *d2 = new DATE(31, 12, 2018);
    cout << d1->daysBetween(*d2) << endl;


    d1 = new DATE(1, 1, 2016);
    d2 = new DATE(1, 1, 2017);
    cout << d1->daysBetween(*d2) << endl;

    d1 = new DATE(1, 10, 1277);
    d2 = new DATE(2, 10, 1277);
    cout << d1->daysBetween(*d2) << endl << endl;

    //

    d1 = new DATE(3, 1, 2015);
    d2 = new DATE(4, 1, 1997);
    cout << d1->age(*d2) << endl;

    d1 = new DATE(5, 1, 2015);
    d2 = new DATE(4, 1, 1997);
    cout << d1->age(*d2) << endl;

    d1 = new DATE(5, 5, 2015);
    d2 = new DATE(14, 6, 1997);
    cout << d1->age(*d2) << endl <<endl;

    //

    d1 = new DATE(31, 1, 2015);
    cout << d1->daysInYear() << endl;

    d1 = new DATE(30, 6, 2017);
    cout << d1->daysInYear() << endl;

    d1 = new DATE(25, 12, 2018);
    cout << d1->daysInYear() << endl<<endl;

    //

    d1 = new DATE(1, 3, 2019);
    cout << d1->areShopsOpenedNextSunday() << endl;

    d1 = new DATE(20, 3, 2019);
    cout << d1->areShopsOpenedNextSunday() << endl;

    d1 = new DATE(26, 10, 2018);
    cout << d1->areShopsOpenedNextSunday() << endl;

    return 0;
}