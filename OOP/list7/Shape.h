#ifndef SHAPE
#define SHAPE
using namespace std;

class Shape{
 public:
  Shape(int a, int b, int x, int y);
  virtual ~Shape();
  int width,height,x,y;
  virtual float area()=0;
  virtual void draw()=0;
  void offsetX();
  void offsetY();
};

class ThreeDimensionalShape: public Shape{
 public:
  ThreeDimensionalShape(int a, int b, int c, int x, int y);
  ~ThreeDimensionalShape() override;
  int depth;
  virtual float volume()=0;
};

class TwoDimensionalShape: public Shape{
 public:
  TwoDimensionalShape(int a, int b, int x, int y);
  ~TwoDimensionalShape() override;
};

class Square: public TwoDimensionalShape{
  public:
    Square(int a, int x, int y);
    ~Square() override;
    float area() override;
    void draw() override;
};

class Rectangle: public TwoDimensionalShape{
  public:
    Rectangle(int a, int b, int x, int y);
    ~Rectangle() override;
    float area() override;
    void draw() override;
};

class IsoscelesTriangle: public TwoDimensionalShape{
  public:
    IsoscelesTriangle(int a, int x, int y);
    ~IsoscelesTriangle() override;
    float area() override;
    void draw() override;
};

class Parallelogram: public TwoDimensionalShape{
  public:
    Parallelogram(int a, int b, int x, int y);
    ~Parallelogram() override;
    float area() override;
    void draw() override;
};

class ChristmasTree: public TwoDimensionalShape{
  void drawPartialTree(int levels,int offset);
  float partialArea();
  public:
    ChristmasTree(int a, int x, int y);
    ~ChristmasTree() override;
    float area() override;
    void draw() override;
};
#endif
