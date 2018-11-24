#include "Shape.h"
#include <iostream>

Shape::Shape(int a, int b, int x, int y):x(x),y(y){
  this->width = a>=0?a:-a;
  this->height = b>=0?b:-b;
  this->x = x>=0?x:-x;
  this->y = y>=0?y:-y;
};

Shape::~Shape(){};

  void Shape::offsetX(){
    for(int i=0;i<this->x;++i){
      cout<<" ";
    }
  }

  void Shape::offsetY(){
    for(int i=0;i<this->y;++i){
      cout<<endl;
    }
  }

ThreeDimensionalShape::ThreeDimensionalShape(int a, int b, int c, int x, int y):Shape(a,b,x,y){
  depth = c>=0?c:-c;
};

ThreeDimensionalShape::~ThreeDimensionalShape(){};

TwoDimensionalShape::TwoDimensionalShape(int a, int b, int x, int y):Shape(a,b,x,y){};

TwoDimensionalShape::~TwoDimensionalShape(){};

Square::Square(int a, int x, int y):TwoDimensionalShape(a,a,x,y){};

Square::~Square(){};

float Square::area(){
  return this->width*this->height;
}

void Square::draw(){
  offsetY();
  for(int i=0;i<this->height;++i){
    offsetX();
    for(int j=0;j<this->width;++j){
      cout<<"X";
    }
    cout<<endl;
  }
}

Rectangle::Rectangle(int a, int b, int x, int y):TwoDimensionalShape(a,b,x,y){};

Rectangle::~Rectangle(){};

float Rectangle::area(){
  return this->width*this->height;
}

void Rectangle::draw(){
  offsetY();
  for(int i=0;i<this->height;++i){
    offsetX();
    for(int j=0;j<this->width;++j){
      cout<<"X";
    }
    cout<<endl;
  }
}
IsoscelesTriangle::IsoscelesTriangle(int a, int x, int y):TwoDimensionalShape(a,a,x,y){};

IsoscelesTriangle::~IsoscelesTriangle(){};

float IsoscelesTriangle::area(){
  return (float)this->width*this->height/2;
}

void IsoscelesTriangle::draw(){
  offsetY();
  for(int i=0;i<this->height;++i){
    offsetX();
    for(int j=0;j<=i;++j){
      cout<<"X";
    }
    cout<<endl;
  }
}

Parallelogram::Parallelogram(int a, int b, int x, int y):TwoDimensionalShape(a,b,x,y){};

Parallelogram::~Parallelogram(){};

float Parallelogram::area(){
  return this->width*this->height;
}

void Parallelogram::draw(){
  offsetY();
  for(int i=0;i<this->height;++i){
    offsetX();
    for(int j=this->height-1;j>i;--j){
      cout<<" ";
    }
    for(int k=0;k<this->width;++k){
      cout<<"X";
    }
    cout<<endl;
  }
}

ChristmasTree::ChristmasTree(int a, int x, int y):TwoDimensionalShape(a,a,x,y){};

ChristmasTree::~ChristmasTree(){};

float ChristmasTree::area(){
  float area = 0;
  for(int i=1;i<=this->height;++i){
    area += i*i;
  }
  return area;
}

void ChristmasTree::draw(){
  offsetY();
  for(int i=1;i<=this->height;++i){
    this->drawPartialTree(i,this->height-1-i);
  }
}

void ChristmasTree::drawPartialTree(int levels,int offset){
  for(int i=1;i<=levels;++i){
    offsetX();
    for(int j=levels+offset;j>=i;--j){
      cout<<" ";
    }
    for(int k=0;k<i*2-1;++k){
      cout<<"X";
    }
    cout<<endl;
  }
}
