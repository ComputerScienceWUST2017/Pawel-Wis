#include <iostream>
using namespace std;
class Account {
public:
    Account() {
        cout << "Constructor" << endl;
    }
    ~Account() {
        cout << "Destructor" << endl;
    }
};
int main() {
    Account *acc = new Account();
    delete(acc);
    return 0;
}