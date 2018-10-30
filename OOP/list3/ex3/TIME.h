//
// Created by Pawel on 24.10.2018.
//

#ifndef ZAD3_TIME_H
#define ZAD3_TIME_H


#include <iosfwd>

class TIME {
public:
    int hour, minute, second;

    TIME operator+(TIME &obj);

    TIME operator-(TIME &obj);

    friend std::ostream &operator<<(std::ostream &stream, TIME &obj);

    friend std::istream &operator>>(std::istream &stream, TIME &obj);

};


#endif //ZAD3_TIME_H