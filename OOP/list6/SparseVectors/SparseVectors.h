//
// Created by pawel on 19.11.18.
//

#ifndef SPARSEVECTORS_SPARSEVECTORS_H
#define SPARSEVECTORS_SPARSEVECTORS_H

#include <vector>

class SparseVectors {
private:
    std::vector<bool> orderVec;
    std::vector<int> valueVec;

    void initializeVectors();

public:


    SparseVectors();

    void printOrderVec() const;

    void printValueVec() const;

    float getScalarProduct(SparseVectors *sec);

};


#endif //SPARSEVECTORS_SPARSEVECTORS_H
