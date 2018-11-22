//
// Created by pawel on 19.11.18.
//

#include "Bicycle.h"

Lubricant::Lubricant(std::string n) : lubricantName(n) {

}

Diode::Diode(int lum) : diodeLumens(lum) {

}

Gum::Gum(char q) : gumQuality(q) {

}

Lamp::Lamp(int lum) : Diode(lum), isLampOn(false) {

}

void Lamp::switchLampOn_Off() {
    this->isLampOn = !this->isLampOn;
}

Wheel::Wheel(char q, int size) : Gum(q), wheelDiameterLength(size) {}

Chain::Chain(std::string n, float length) : Lubricant(n), chainLength(length) {}

Bicycle::Bicycle(int lum, char q, int size, std::string n, float length) : Lamp(lum), Wheel(q, size), Chain(n, length) {}
