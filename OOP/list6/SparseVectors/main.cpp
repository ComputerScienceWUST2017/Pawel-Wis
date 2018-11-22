#include <iostream>
#include <string>
#include "SparseVectors.h"
using namespace std;
int main() {
    SparseVectors *sv1 = new SparseVectors();
    sv1->printOrderVec();
    sv1->printValueVec();
    SparseVectors *sv2 = new SparseVectors();
    sv2->printOrderVec();
    sv2->printValueVec();
    cout<<"~prod = "<<sv1->getScalarProduct(sv2)<<endl;
    return 0;
}
