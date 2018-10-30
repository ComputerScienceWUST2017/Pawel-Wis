//
// Created by pawel on 22.10.18.
//

#include <bits/exception.h>
#include <iostream>
#include "Complex.h"

using namespace std;

Complex Complex::operator+(Complex const &obj) {
    Complex temp{};
    temp.real = this->real + obj.real;
    temp.imag = this->imag + obj.imag;
    return temp;
}

Complex Complex::operator-(Complex const &obj) {
    Complex temp{};
    temp.real = this->real - obj.real;
    temp.imag = this->imag - obj.imag;
    return temp;
}

Complex Complex::operator*(Complex const &obj) {
    Complex temp{};
    temp.real = this->real * obj.real - this->imag * obj.imag;
    temp.imag = this->real * obj.imag + this->imag * obj.real;
    return temp;
}

Complex Complex::operator/(Complex const &obj) {
    Complex temp{};
    if(obj.real * obj.real + obj.imag * obj.imag == 0){
        cerr<<" division over zero! "<<endl;
    }
    temp.real = (this->real * obj.real + this->imag * obj.imag) / (obj.real * obj.real + obj.imag * obj.imag);
    temp.imag = (this->imag * obj.real - this->real * obj.imag) / (obj.real * obj.real + obj.imag * obj.imag);

    return temp;
}
