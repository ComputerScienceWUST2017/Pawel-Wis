#include<iostream>
#include<string.h>
#include <string>
#include <sstream>

using namespace std;

struct Element {
    int value;
    Element *next;
};

struct List {
    Element* head;
};

void init(List& l) {
    l.head = NULL;
}

void insertHead(List& l, int x) {
    Element* newE = new Element;
    newE->value=x;
    newE->next=l.head;
    l.head=newE;
}

bool deleteHead(List& l, int &oldHead) {
    if (l.head == NULL) {
        return false;
    }
    oldHead = l.head->value;
    Element* prevHead = l.head;
    l.head = l.head->next;
    delete prevHead;
    return true;
}

void insertTail(List& l, int x) {
    if(l.head==NULL){
        insertHead(l,x);
        return;
    }
    Element* newE = new Element;
    Element* ptr  = l.head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    newE->value=x;
    newE->next=NULL;
    ptr->next=newE;
}

bool deleteTail(List& l, int &oldTail) {
    if (l.head == NULL) {
        return false;
    }
    if(l.head->next==NULL){
        return deleteHead(l,oldTail);
    }
    Element* ptr  = l.head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    oldTail = ptr->next->value;
    delete ptr->next;
    ptr->next=NULL;
    return true;
}

bool insertSecond(List& l, int x){
    if(l.head==NULL){
        return false;
    }
    Element *newE = new Element;
    newE->next=l.head->next;
    newE->value=x;
    l.head->next=newE;
    return true;
}

int findPosOfValue(List& l, int value) {
    if(l.head==NULL){
        return -1;
    }
    int counter;
    Element *ptr = l.head;
    for (counter = 0; ptr->next != NULL && ptr->value != value;++counter) {
        ptr = ptr->next;
    }
    if (ptr->value == value) {
        return counter;
    }
    return -1;
}

bool deleteValue(List& l, int value) {
    if(l.head==NULL){
        return false;
    }
    int position = findPosOfValue(l, value);
    if (position == -1) {
        return false;
    }
    if (position == 0) {
        return deleteHead(l, position);
    }
    Element* ptr = l.head,*temp;
    for (int i = 0; i < position-1; ++i) {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = ptr->next->next;
    delete temp;
    return true;
}

bool atPosition(List& l, int pos, int &value) {
    if(l.head==NULL){
        return false;
    }
    Element *ptr = l.head;
    for (int i = 0; i < pos && ptr!=NULL; ++i) {
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        value = ptr->value;
        return true;
    }
    else {
        return false;
    }
}

void showListFromHead(List& l) {
    Element *ptr = l.head;
    while (ptr != NULL) {
        cout << ptr->value << ",";
        ptr=ptr->next;
    }
    cout << endl;
}

void clearList(List& l) {
    int temp;
    while (l.head != NULL) {
        deleteHead(l, temp);
    }
}

void showBool(bool val){
    if(val)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}


bool isCommand(const string command,const char *mnemonic){
    return command==mnemonic;
}

int main(){
    string line;
    string command;
    List *list=NULL;
    int currentL=0;
    int value;
    cout << "START" << endl;
    while(true){
        getline(cin,line);
        std::stringstream stream(line);
        stream >> command;
        if(line=="" || command[0]=='#')
        {
            // ignore empty line and comment
            continue;
        }

        // copy line on output with exclamation mark
        cout << "!" << line << endl;;

        // change to uppercase
        command[0]=toupper(command[0]);
        command[1]=toupper(command[1]);

        if(isCommand(command,"HA")){
            cout << "END OF EXECUTION" << endl;
            break;
        }


        // zero-argument command
        if(isCommand(command,"DH"))
        {
            int retValue;
            bool retBool=deleteHead(list[currentL],retValue);
            if(retBool)
                cout << retValue << endl;
            else
                showBool(retBool);
            continue;
        }
        if(isCommand(command,"DT"))
        {
            int retValue;
            bool retBool=deleteTail(list[currentL],retValue);
            if(retBool)
                cout << retValue << endl;
            else
                showBool(retBool);
            continue;
        }

        if(isCommand(command,"SH"))
        {
            showListFromHead(list[currentL]);
            continue;
        }

        if(isCommand(command,"CL"))
        {
            clearList(list[currentL]);
            continue;
        }

        if(isCommand(command,"IN"))
        {
            init(list[currentL]);
            continue;
        }

        // read next argument, one int value
        stream >> value;

        if(isCommand(command,"FP"))
        {
            int ret;
            ret=findPosOfValue(list[currentL],value);
            cout << ret << endl;
            continue;
        }

        if(isCommand(command,"DV"))
        {
            showBool(deleteValue(list[currentL],value));
            continue;
        }


        if(isCommand(command,"AT"))
        {
            int retValue;
            bool retBool=atPosition(list[currentL],value,retValue);
            if(retBool)
                cout << retValue << endl;
            else
                showBool(retBool);
            continue;
        }

        if(isCommand(command,"CH"))
        {
            currentL=value;
            continue;
        }

        if(isCommand(command,"IH"))
        {
            insertHead(list[currentL],value);
            continue;
        }

        if(isCommand(command,"IT"))
        {
            insertTail(list[currentL],value);
            continue;
        }

        if(isCommand(command,"GO"))
        {
            list=new List[value];
            continue;
        }

        cout << "wrong argument in test: " << command << endl;
    }
}