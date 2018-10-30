//
// Created by pawel on 19.10.18.
//

#ifndef LIST3ZAD1_DATE_H
#define LIST3ZAD1_DATE_H

class DATE {
private:
    long long convertToPOSIX(DATE data);
public:
    DATE(int day, int month, int year);

    int daysBetween(DATE date);

    int age(DATE birthdate);

    int daysInYear();

    bool areShopsOpenedNextSunday();

    int day, month, year;

};


#endif //LIST3ZAD1_DATE_H
