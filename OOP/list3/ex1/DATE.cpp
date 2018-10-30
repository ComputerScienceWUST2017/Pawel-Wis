//
// Created by pawel on 19.10.18.
//

#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "DATE.h"

using namespace std;

DATE::DATE(int day, int month, int year)
        : day(day), month(month), year(year) {}

int DATE::daysBetween(DATE date) {
    long long datePOSIX = convertToPOSIX(date);
    long long thisPOSIX = convertToPOSIX(*this);
    long long dif = abs(datePOSIX - thisPOSIX);
    dif = dif / 86400; // diffrence over duration of day in seconds
    return (int) dif;
}

long long DATE::convertToPOSIX(DATE data) {
    tm t = {};
    stringstream ss;

    ss << data.year << "-" << ((data.month < 10) ? "0" : "") << data.month << "-" << ((data.day < 10) ? "0" : "")
       << data.day;

    if (ss >> get_time(&t, "%Y-%m-%dT")) {
        return (long long) mktime(&t);
    }
    return (long long) -1;
}

int DATE::age(DATE birthdate) {
    int age = this->year - birthdate.year;
    if (this->month < birthdate.month || (this->month == birthdate.month && this->day < birthdate.day)) {
        age--;
    }

    return age;
}

int DATE::daysInYear() {
    DATE *tempDate = new DATE(1, 1, this->year);
    return daysBetween(*tempDate);
}

bool DATE::areShopsOpenedNextSunday() {
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->year % 4 == 0) monthDays[1]++;

    return this->day <= 7 || this->day >= monthDays[this->month - 1] - 7;
}
