#include <iostream>
#include "Point.h"
using namespace std;

template<class T>
void selectionSort(T **arr, const unsigned arrLen, bool(*comp)(const T *one, const T *two)) {
    unsigned minIndex;
    for (unsigned i = 0; i < arrLen; ++i) {
        minIndex = i;
        for (unsigned j = i; j < arrLen; ++j) {
            if (comp(arr[j],arr[minIndex]) == true) {
                minIndex = j;
            }
        }
        T *temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}


bool compX(const Point *one, const Point *two) {
    return one->getX() < two->getX();
}

bool compY(const Point *one, const Point *two) {
    return one->getY() < two->getY();
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    const unsigned len = 50; // number of points in the array

    Point **arrayOfPoints = new Point *[len]; // declare arra of points

    for (unsigned i = 0; i < len; ++i) {
        arrayOfPoints[i] = new Point(rand()%100-50, rand()%100-50); // initialize all the points
    }

    for (unsigned j = 0; j < len; ++j) { // print before sorting
        std::cout << arrayOfPoints[j]->getX() << ',' << arrayOfPoints[j]->getY() << std::endl;
    }

    selectionSort(arrayOfPoints, len, compX); // sort by x coordinate

    std::cout << "\n~sorted by X\n"<<endl;
    for (unsigned j = 0; j < len; ++j) { // print after sorting
        std::cout << arrayOfPoints[j]->getX() << ',' << arrayOfPoints[j]->getY() << std::endl;
    }

    selectionSort(arrayOfPoints, len, compY); // sort by y coordinate

    std::cout << "\n~sorted by Y\n"<<endl;
    for (unsigned j = 0; j < len; ++j) { // print after sorting
        std::cout << arrayOfPoints[j]->getX() << ',' << arrayOfPoints[j]->getY() << std::endl;
    }
    return 0;
}