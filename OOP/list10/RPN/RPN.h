//
// Created by pawel on 11.01.19.
//

#ifndef RPN_RPN_H
#define RPN_RPN_H

#include <string>
#include "Stack.h"

using namespace std;

class RPN {
    string rawEquation;

    int getPriority(string input);

    bool comparePrior(string a, string b);

    bool isDouble(string input);

    double strToDouble(string input);

    double evaluateEquation(string a, string sign, string b);

    Stack<string> *convertToRPN(string equat);

public:
    RPN(string equat);

    double calculate();
};


#endif //RPN_RPN_H
