//
// Created by Pawel on 25.11.2018.
//

#include "Point.h"

double Point::getX() const {
    return this->x;
}

double Point::getY() const {
    return this->y;
}

Point::Point(double x, double y) : x(x), y(y) {

}

Point::~Point() = default;


Point::Point() = default;


