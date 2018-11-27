#include <iostream>
#include "Point.h"

using namespace std;

template<class T>
void selectionSort(T **arr, const unsigned arrLen, bool(*comp)(const T *one, const T *two)) {
    unsigned minIndex;
    for (unsigned i = 0; i < arrLen; ++i) {
        minIndex = i;
        for (unsigned j = i; j < arrLen; ++j) {
            if (comp(arr[minIndex], arr[j]) == true) {
                minIndex = j;
            }
        }
        T *temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}


bool compX(const Point *one, const Point *two) {
    return two->getX() < one->getX();
}

bool compY(const Point *one, const Point *two) {
    return two->getY() < one->getY();
}

int main() {

    const unsigned len = 50;

    Point **arrayOfPoints = new Point *[len];

    for (int i = 0; i < len; ++i) {
        arrayOfPoints[i] = new Point(len - i, i);
    }

    for (int j = 0; j < len; ++j) {
        std::cout << j << ' ' << arrayOfPoints[j]->getX() << ',' << arrayOfPoints[j]->getY() << std::endl;
    }

    selectionSort(arrayOfPoints, len, compX);

    std::cout << "\nsorted\n";
    for (int j = 0; j < len; ++j) {
        std::cout << j << ' ' << arrayOfPoints[j]->getX() << ',' << arrayOfPoints[j]->getY() << std::endl;
    }
    return 0;
}