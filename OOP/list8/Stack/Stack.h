#ifndef STACK
#define STACK

template<class T>
class Stack {
    int maxSize, top;
    T *stackPtr;

    bool isEmpty() const {
        return this->top == -1;
    }

    bool isFull() const {
        return this->top >= this->maxSize - 1;
    }

public:
    Stack(int maxsize) : maxSize(maxsize), top(-1) {
        this->stackPtr = new T[maxsize];
    }

    ~Stack() {
        delete[] stackPtr;
    }

    bool push(const T &elem) {
        if (!isFull()) {
            this->stackPtr[++this->top] = elem;
            return true;
        }
        return false;
    }

    bool pop(T &elem) {
        if (!isEmpty()) {
            elem = this->stackPtr[this->top--];
            return true;
        }
        return false;
    }

    bool getTop(T &top) {
        if (!isEmpty()) {
            top = this->stackPtr[this->top];
            return true;
        }
        return false;
    }
};

#endif
