//
// Created by pawel on 19.11.18.
//

#include "SparseVectors.h"
#include <iostream>
#include <vector>
using namespace std;

SparseVectors::SparseVectors() {
    initializeVectors();
}

void SparseVectors::initializeVectors() {
    int number;
    while (cin >> number) {
        if (number != 0) {
            this->valueVec.push_back(number);
            this->orderVec.push_back(true);
        } else {
            this->orderVec.push_back(false);
        }

    }
    cin.clear();
    cin.ignore(255,'\n');
}

void SparseVectors::printOrderVec() const {
    cout << "~Order vector: ";
    for (auto i : this->orderVec) {
        cout << i << ',';
    }
    cout << endl;
}

void SparseVectors::printValueVec() const {
    cout << "~Value vector: ";
    for (auto i : this->valueVec) {
        cout << i << ',';
    }
    cout << endl;
}

float SparseVectors::getScalarProduct(SparseVectors *sec) {
    if(this->orderVec.size()!=sec->orderVec.size()){
        cerr<<"\n~Vectors have different sizes!\n"<<endl;
        return -1;
    }
    float sum = 0;
    int iValThis = 0, iValSec = 0;

    for(int i = 0;i<(int)this->orderVec.size();++i){
        if(this->orderVec[i] == true && sec->orderVec[i] == true){
            sum += this->valueVec[iValThis] * sec->valueVec[iValSec];
            ++iValSec;
            ++iValThis;
        }
        else if(this->orderVec[i] == true && sec->orderVec[i] == false){
            ++iValThis;
        }
        else if(this->orderVec[i] == false && sec->orderVec[i] == true){
            ++iValSec;
        }
    }
    return sum;
}
