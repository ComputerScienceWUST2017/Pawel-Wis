#include <iostream>
#include "Shape.h"
using namespace std;

int main(){
auto squ = new Square(5,10,1);
squ->draw();

auto rec = new Rectangle(19,5,10,1);
rec->draw();

auto tri = new IsoscelesTriangle(15,6,1);
tri->draw();

auto par = new Parallelogram(15,5,1,1);
par->draw();
  return 0;
}
