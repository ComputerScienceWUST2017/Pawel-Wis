//
// Created by Pawel on 24.10.2018.
//

#include <ostream>
#include "TIME.h"
#include <string>
#include <iostream>

using namespace std;

TIME TIME::operator+(TIME &obj) {
    TIME output{};
    int reminder;

    reminder = (this->second + obj.second) / 60;
    output.second = (this->second + obj.second) % 60;

    output.minute = (this->minute + obj.minute + reminder) % 60;
    reminder = (this->minute + obj.minute + reminder) / 60;


    output.hour = (this->hour + obj.hour + reminder) % 24;

    return output;
}

TIME TIME::operator-(TIME &obj) {
    TIME output{};

    bool temp = this->second < obj.second;
    output.second = this->second - obj.second;
    if (temp) output.second += 60;

    output.minute = this->minute - obj.minute - temp;
    temp = output.minute < 0;
    if(temp) output.minute +=60;

    output.hour = this->hour - obj.hour - temp;
    temp = output.hour < 0;
    if(temp) output.hour +=24;

    return output;
}

std::ostream &operator<<(std::ostream &stream, TIME &obj) {
    stream << (obj.hour < 10 ? "0" : "") << obj.hour << ":" << (obj.minute < 10 ? "0" : "") << obj.minute << ":"
           << (obj.second < 10 ? "0" : "") << obj.second;

    return stream;
}

std::istream &operator>>(std::istream &stream, TIME &obj) {
    string input[3];

    getline(cin, input[0], ':');
    getline(cin, input[1], ':');
    cin >> input[2];

    try {
        obj.hour = stoi(input[0]);
        obj.minute = stoi(input[1]);
        obj.second = stoi(input[2]);

        if (obj.hour > 23 || obj.hour < 0) {
            throw invalid_argument(" Hours must be between 0-23");
        }

        if (obj.minute > 59 || obj.minute < 0) {
            throw invalid_argument(" Minutes must be between 0-59");
        }

        if (obj.second > 59 || obj.second < 0) {
            throw invalid_argument(" Seconds must be between 0-59");
        }
    }
    catch (exception &e) {
        cerr << "Invalid input: " << e.what() << endl;
        stream.setstate(ios::failbit);
    }


    return stream;
}


