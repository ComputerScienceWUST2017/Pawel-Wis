//
// Created by pawel on 19.11.18.
//

#ifndef BICYCLE_BICYCLE_H
#define BICYCLE_BICYCLE_H

#include <string>

class Lubricant {
public:
    Lubricant(std::string n);

    std::string lubricantName;
};
class Diode {
public:
    Diode(int lum);

    int diodeLumens;
};
class Gum {
public:
    Gum(char q);

    char gumQuality;
};
///
class Lamp : public Diode {
public:
    Lamp(int lum);

    bool isLampOn;

    void switchLampOn_Off();
};
class Wheel : public Gum {
public:
    Wheel(char q, int size);

    int wheelDiameterLength;
};
class Chain : public Lubricant {
public:
    Chain(std::string n, float length);

    float chainLength;
};
///
class Bicycle : public Lamp, public Wheel, public Chain {
public:
    Bicycle(int lum, char q, int size, std::string n, float length);
};


#endif //BICYCLE_BICYCLE_H
