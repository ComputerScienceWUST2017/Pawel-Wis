//
// Created by pawel on 14.11.18.
//

#include <iostream>
#include "ArabianNumbers.h"

ArabianNumbers::ArabianNumbers(int x) : num(x) {}

void ArabianNumbers::printNum() {
    std::cout << "The number is " << this->num << std::endl;
}

void RomanNumbers::printNum() {
    std::cout << "The number is " << convertToRoman(this->num) << std::endl;
}

std::string RomanNumbers::convertToRoman(int input) {
    struct romanstruct {
        int value;
        char const *numeral;
    };

    const romanstruct romanarr[] =
            {
                    {1000, "M"},
                    {900,  "CM"},
                    {500,  "D"},
                    {400,  "CD"},
                    {100,  "C"},
                    {90,   "XC"},
                    {50,   "L"},
                    {40,   "XL"},
                    {10,   "X"},
                    {9,    "IX"},
                    {5,    "V"},
                    {4,    "IV"},
                    {1,    "I"},
                    {0,    nullptr} // end marker
            };

    std::string result;
    for (const romanstruct *current = romanarr; current->value > 0; ++current) {
        while (input >= current->value) {
            result += current->numeral;
            input -= current->value;
        }
    }
    return result;
}

RomanNumbers::RomanNumbers(int x) : ArabianNumbers(x) {}
