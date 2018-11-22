//
// Created by pawel on 14.11.18.
//

#ifndef EXE1_ARABIANNUMBERS_H
#define EXE1_ARABIANNUMBERS_H

#include <iostream>

using namespace std;

class ArabianNumbers {
protected:
    int num;
public:
    ArabianNumbers(int);

    virtual void printNum();
};

class RomanNumbers : public ArabianNumbers {
private:
    string convertToRoman(int input);

public:
    RomanNumbers(int);
    void printNum() override;
};

#endif //EXE1_ARABIANNUMBERS_H
