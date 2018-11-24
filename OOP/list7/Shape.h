#ifndef SHAPE
#define SHAPE
using namespace std;

class Shape{
public:
  Shape(float a, float b, int x, int y);
  float width,height;
  int x,y;
  virtual float area()=0;
  virtual void draw()=0;
  void offsetX();
  void offsetY();
};

class ThreeDimensionalShape: public Shape{
public:
  ThreeDimensionalShape(float a, float b, float c, int x, int y);
  float depth;
  virtual float volume()=0;
  float area()=0;
  void draw()=0;
};

class TwoDimensionalShape: public Shape{
public:
  TwoDimensionalShape(float a, float b, int x, int y);
  float area()=0;
  void draw()=0;
};

class Square: public TwoDimensionalShape{
  public:
    Square(float a, int x, int y);
    float area() override;
    void draw() override;
};

class Rectangle: public TwoDimensionalShape{
  public:
    Rectangle(float a, float b, int x, int y);
    float area() override;
    void draw() override;
};

class IsoscelesTriangle: public TwoDimensionalShape{
  public:
    IsoscelesTriangle(float a, int x, int y);
    float area() override;
    void draw() override;
};

class Parallelogram: public TwoDimensionalShape{
  public:
    Parallelogram(float a, float b, int x, int y);
    float area() override;
    void draw() override;
};

#endif
