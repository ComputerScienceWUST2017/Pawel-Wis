//
// Created by pawel on 11.01.19.
//

#include <sstream>
#include <iostream>
#include "RPN.h"

using namespace std;

RPN::RPN(string equat) {
    this->rawEquation = equat;

}

int RPN::getPriority(string input) {
    if (input == "(") return 0;
    if (input == "+" || input == "-" || input == ")") return 1;
    if (input == "*" || input == "/") return 2;
}

bool RPN::comparePrior(string a, string b) {
    return getPriority(a) > getPriority(b);
}

Stack<string> *RPN::convertToRPN(string equat) {
    Stack<string> *queueEquat = new Stack<string>(100);
    Stack<string> *stackRPN = new Stack<string>(100);
    Stack<string> *stackTemp = new Stack<string>(100);
    stringstream ss(equat);

    string elem;
    while (!ss.eof()) {
        ss >> elem;
        queueEquat->push(elem);
    }


    while (queueEquat->deq(elem)) {
        if (isDouble(elem)) { // number
            stackRPN->push(elem);
        } else if (elem == "(") { // (
            stackTemp->push(elem);
        } else if (elem == ")") { // )
            stackTemp->pop(elem);
            while (!stackTemp->isEmpty() && elem != "(") {
                stackRPN->push(elem);
                stackTemp->pop(elem);
            }
        } else {
            string topStackTempVal;
            stackTemp->getTop(topStackTempVal);
            if (stackTemp->isEmpty() || comparePrior(elem, topStackTempVal)) {
                stackTemp->push(elem);
            } else {
                while (!stackTemp->isEmpty() && !comparePrior(elem, topStackTempVal)) {
                    string temp;
                    stackTemp->pop(temp);
                    stackRPN->push(temp);
                    stackTemp->getTop(topStackTempVal);
                }
                stackTemp->push(elem);
            }
        }
    }
    while (!stackTemp->isEmpty()) {
        string temp;
        stackTemp->pop(temp);
        stackRPN->push(temp);
    }
    return stackRPN;
}


bool RPN::isDouble(std::string input) {
    try {
        stod(input);
    } catch (...) {
        return false;
    }
    return true;
}

double RPN::strToDouble(string input) {
    stringstream ss(input);
    double result;
    ss >> result;
    return result;
}

double RPN::calculate() {
    Stack<string> *stackRPN = convertToRPN(this->rawEquation);

    Stack<string> *stackTemp = new Stack<string>(100);
    string elem;
    while (stackRPN->deq(elem)) {
        if (isDouble(elem)) {
            stackTemp->push(elem);
        } else {
            string a, b;
            stackTemp->pop(a);
            stackTemp->pop(b);
            double result = evaluateEquation(b, elem, a);
            stackTemp->push((to_string(result)));
        }
    }
    stackTemp->pop(elem);
    return strToDouble(elem);
}

double RPN::evaluateEquation(string a, string sign, string b) {
    char s = sign[0];
    switch (s) {
        case '+': {
            return strToDouble(a) + strToDouble(b);
        }
        case '-': {
            return strToDouble(a) - strToDouble(b);
        }
        case '*': {
            return strToDouble(a) * strToDouble(b);
        }
        case '/': {
            return strToDouble(a) / strToDouble(b);
        }
        default: {
            return 0;
        }
    }

}
