#include <iostream>
#include "Shape.h"
using namespace std;

int getOption() {
    char c;
    cin >> c;
    c -= '0';
    cin.clear();
    cin.ignore(255, '\n');
    return c;
}

void handleInvalidInput() {
    cin.clear();
    cin.ignore(255, '\n');
    cerr << "\n~Invalid input! Provide proper values: " << endl << ' ';
}

int main(){
Shape *shape = nullptr;
int option,x,y,a,b;
while(true){

  cout<<"\n===========================\n \
    \r\r\r0: exit\n \
    \r\r\r1: Create and use new Square\n \
    \r\r\r2: Create and use new Rectangle\n \
    \r\r\r3: Create and use new IsoscelesTriangle\n \
    \r\r\r4: Create and use new Parallelogram\n \
    \r\r\r5: Create and use new ChristmasTree\n \
    \r\r\r6: Calculate area\n \
    \r\r\r7: Draw\n \
    \r\r\r===========================\n\
    \r\r\rChoose an option: "<<flush;

  option = getOption();
  if(option == 0){
    break;
  }

  switch (option) {
    case 1:{                                                    // square
      cout<<"\n~Please enter side length and offset x y: ";
      while (!(cin >> a >> x >> y)) {
          handleInvalidInput();
      }
      delete shape;
      shape = new Square(a,x,y);
      break;
    }
    case 2:{                                                    // rectangle
      cout<<"\n~Please enter width and height and offset x y: ";
      while (!(cin >> a >> b >> x >> y)) {
          handleInvalidInput();
      }
      delete shape;
      shape = new Rectangle(a,b,x,y);
      break;
    }
    case 3:{                                                    // triangle
      cout<<"\n~Please enter side length and offset x y: ";
      while (!(cin >> a >> x >> y)) {
          handleInvalidInput();
      }
      delete shape;
      shape = new IsoscelesTriangle(a,x,y);
      break;
    }
    case 4:{                                                    // parallelogram
      cout<<"\n~Please enter width and height and offset x y: ";
      while (!(cin >> a >> b >> x >> y)) {
          handleInvalidInput();
      }
      delete shape;
      shape = new Parallelogram(a,b,x,y);
      break;
    }
    case 5:{                                                    // christmasTree
      cout<<"\n~Please enter number of levels and offset x y: ";
      while (!(cin >> a >> x >> y)) {
          handleInvalidInput();
      }
      delete shape;
      shape = new ChristmasTree(a,x,y);
      break;
    }
    case 6:{                                                    // area
      if(shape == nullptr){
        cerr<<"\n~Create an object first"<<endl;
        break;
      }
      cout<<"\n~The area = " << shape->area()<<endl;
      break;
    }
    case 7:{                                                    // draw
      if(shape == nullptr){
        cerr<<"\n~Create an object first"<<endl;
        break;
      }
      shape->draw();
      break;
    }
    default:{
      cerr << "\n~invalid number of option!" << endl;
    }
  }

}


  return 0;
}
