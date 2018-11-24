#include "Shape.h"
#include <iostream>

Shape::Shape(float a, float b, int x, int y):width(a),height(b),x(x),y(y){};

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

ThreeDimensionalShape::ThreeDimensionalShape(float a, float b, float c, int x, int y):Shape(a,b,x,y),depth(c){};

TwoDimensionalShape::TwoDimensionalShape(float a, float b, int x, int y):Shape(a,b,x,y){};

Square::Square(float a, int x, int y):TwoDimensionalShape(a,a,x,y){};

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

Rectangle::Rectangle(float a, float b, int x, int y):TwoDimensionalShape(a,b,x,y){};

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
IsoscelesTriangle::IsoscelesTriangle(float a, int x, int y):TwoDimensionalShape(a,a,x,y){};

float IsoscelesTriangle::area(){
  return this->width*this->height/2;
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

Parallelogram::Parallelogram(float a, float b, int x, int y):TwoDimensionalShape(a,b,x,y){};

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

ChristmasTree::ChristmasTree(float a, int x, int y):TwoDimensionalShape(a,a,x,y), totalArea(0){};

float ChristmasTree::area(){
  return this->totalArea;
}

void ChristmasTree::draw(){
  offsetY();
  for(int i=0;i<this->height;++i){
    this->drawPartialTree(i,this->height-1-i);
  }
}

void ChristmasTree::drawPartialTree(int levels,int offset){
  for(int i=0;i<levels;++i){
    offsetX();
    for(int j=levels-1+offset;j>i;--j){
      cout<<" ";
    }
    for(int k=0;k<i*2+1;++k){
      cout<<"X";
    }
    this->totalArea+=i*2+1;
    cout<<endl;
  }
}
