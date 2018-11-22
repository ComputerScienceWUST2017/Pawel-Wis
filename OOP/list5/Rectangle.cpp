//
// Created by pawel on 14.11.18.
//

#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle() : a(0), b(0) {}

Rectangle::~Rectangle() = default;

Rectangle::Rectangle(float a, float b) : a(a), b(b) {}

float Rectangle::area() {
    return area(this->a, this->b);
}

float Rectangle::area(float a, float b) {
    return a * b;
}

float Rectangle::diagonal() {
    return static_cast<float>(sqrt(pow(this->a, 2) + pow(this->b, 2)));
}

Cuboid::Cuboid() : Rectangle(), c(0) {}

Cuboid::~Cuboid() = default;

Cuboid::Cuboid(float a, float b, float c) : Rectangle(a, b), c(c) {}

float Cuboid::area() {
    return (Rectangle::area(b, c) + Rectangle::area(a, c)) * 2;
}

float Cuboid::diagonal() {
    return static_cast<float>(sqrt(pow(Rectangle::diagonal(), 2) + pow(c, 2)));
}
