//
// Created by pawel on 11.01.19.
//

#ifndef RPN_STACK_H
#define RPN_STACK_H
using namespace std;

template<class T>
class Stack {
    int maxSize, top;
    T *arrPtr;

    void shiftLeft() {
        for (int i = 0; i < this->top; ++i) {
            this->arrPtr[i] = this->arrPtr[i + 1];
        }
        --this->top;
    }

public:
    Stack(int maxsize) : maxSize(maxsize), top(-1) {
        this->arrPtr = new T[maxsize];
    }

    ~Stack() {
        delete[] arrPtr;
    }

    bool isEmpty() const {
        return this->top == -1;
    }

    bool isFull() const {
        return this->top >= this->maxSize - 1;
    }

    bool push(const T &elem) {
        if (!isFull()) {
            this->arrPtr[++this->top] = elem;
            return true;
        }
        return false;
    }

    bool pop(T &elem) {
        if (!isEmpty()) {
            elem = this->arrPtr[this->top--];
            return true;
        }
        return false;
    }

    bool getTop(T &top) {
        if (!isEmpty()) {
            top = this->arrPtr[this->top];
            return true;
        }
        return false;
    }

    bool deq(T &elem) {
        if (!isEmpty()) {
            elem = this->arrPtr[0];
            shiftLeft();
            return true;
        }
        return false;
    }

    void printStack(string i = "") {
        cout << i << " ";
        for (int i = 0; i <= this->top; ++i) {
            cout << arrPtr[i] << ',';
        }
        cout << endl;
    }
};

#endif //RPN_STACK_H
