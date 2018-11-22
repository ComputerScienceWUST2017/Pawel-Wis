//
// Created by pawel on 14.11.18.
//

#ifndef EXE1_RECTANGLE_H
#define EXE1_RECTANGLE_H


#include <cmath>

class Rectangle {
protected:
    float a,b;
    virtual float area(float,float);
public:
    Rectangle();
    Rectangle(float,float);
    virtual float area();
    virtual float diagonal();
    virtual ~Rectangle();
};

class Cuboid: public Rectangle{
protected:
    float c;
public:
    Cuboid();
    Cuboid(float,float,float);
    float area() override;
    float diagonal() override;
    ~Cuboid() override;
};
#endif //EXE1_RECTANGLE_H
