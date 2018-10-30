
///
//
// Created by pawel on 22.10.18.
//

#ifndef LIST3ZAD2_COMPLEX_H
#define LIST3ZAD2_COMPLEX_H


class Complex {
public:
    float real, imag;

    Complex operator+(Complex const &obj);

    Complex operator-(Complex const &obj);

    Complex operator*(Complex const &obj);

    Complex operator/(Complex const &obj);
};


#endif //LIST3ZAD2_COMPLEX_H