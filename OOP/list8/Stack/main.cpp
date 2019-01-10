#include <iostream>
#include "Stack.h"

using namespace std;

class Dur{
public:
  Dur(){
    hur=0;};
  Dur(int x){
    hur = x;
  }
  int hur;
};


int main() {

    Dur **arrDur = new Dur*[10];
    for (int i = 0; i < 10; i++) {
      arrDur[i] = new Dur(i+100);
    }


    Stack<Dur*> *stack = new Stack<Dur*>(10);
    cout<< stack->pop(arrDur[0]) <<endl;
    cout<< stack->push(arrDur[1]) <<endl;
    cout<< stack->push(arrDur[2]) <<endl;
    cout<< stack->pop(arrDur[0]) <<endl;
    cout<< arrDur[0]->hur <<endl;
    return 0;
}







    // cout << "\n~INT~\n" << endl;
    //
    // int x;
    // Stack<int> *stackInt = new Stack<int>(5);
    //
    // cout << "Pop: " << stackInt->pop(x) << endl << endl;
    //
    // for (int i = 0; i < 7; ++i) {
    //     cout << "Push: " << stackInt->push(i) << endl;
    // }
    //
    // cout << endl << "Get top: " << stackInt->getTop(x) << ", Top value: " << x << endl << endl;
    //
    // for (int i = 0; i < 7; ++i) {
    //     cout << "Pop: " << stackInt->pop(x) << ", value: " << x << endl;
    // }
    //
    // cout << "\n~STRING~\n" << endl;
    //
    // string str;
    // Stack<string> *stackString = new Stack<string>(5);
    //
    // cout << "Pop: " << stackInt->pop(x) << endl << endl;
    //
    // for (int i = 0; i < 7; ++i) {
    //     cout << "Push: " << stackString->push("str" + to_string(i)) << endl;
    // }
    //
    // cout << endl << "Get top: " << stackString->getTop(str) << ", Top value: " << str << endl << endl;
    //
    // for (int i = 0; i < 7; ++i) {
    //     cout << "Pop: " << stackString->pop(str) << ", value: " << str << endl;
    // }
