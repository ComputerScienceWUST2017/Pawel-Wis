#include<iostream>
#include <string>
#include <sstream>

using namespace std;


// Two-way unordered cycled list without sentinel
struct Element{
    int value;
    Element *next;
    Element *prev;
};

struct List2W{
    Element* head;
    Element* tail;
};

void init(List2W& l){
    l.head = l.tail = NULL;
}

void insertHead(List2W& l, int x){
    Element *newE = new Element;
    if(l.tail==NULL){
        l.tail=newE;
    }if(l.head!=NULL){
        l.head->prev=newE;
    }
    newE->next=l.head;
    newE->prev=l.tail;
    newE->value=x;
    l.tail->next=newE;
    l.head=newE;
}


Element* removeElement(Element* e){
    Element* tempPtr=e->prev;
    if(tempPtr==e){
        tempPtr = NULL;
    }
    e->prev->next=e->next;
    e->next->prev=e->prev;
    delete e;
    return tempPtr;
}

bool deleteHead(List2W& l, int &value){
    if(l.head==NULL){
        return false;
    }
    value = l.head->value;
    Element* ptr = removeElement(l.head);
    if(ptr== NULL){
        l.head=l.tail= NULL;
        return true;
    }
    l.tail=ptr;
    l.head=ptr->next;
    return true;
}

void insertTail(List2W& l, int x){
    if(l.head==NULL){
        insertHead(l,x);
        return;
    }
    Element *newE = new Element;
    newE->value=x;
    newE->next=l.head;
    newE->prev=l.tail;
    l.tail->next=newE;
    l.tail=newE;
    l.head->prev=newE;
}

bool deleteTail(List2W& l, int &value){
    if(l.head==NULL){
        return false;
    }
    value=l.tail->value;
    Element* ptr = removeElement(l.tail);
    if(ptr== NULL){
        l.head=l.tail= NULL;
        return true;
    }
    l.tail=ptr;
    l.head=ptr->next;
    return true;
}

int findValue(List2W& l, int value){
    if(l.head== NULL){ //empty
        return -1;
    }
    int i=0;
    Element *ptr=l.tail;
    do{
        ptr=ptr->next;
        if(ptr->value==value){
            return i;
        }
        ++i;
    }while(ptr!=l.tail);
    return -1;
}

void removeAllValue(List2W& l, int value){
    if(l.head== NULL){ //empty
        return;
    }

    Element* ptr=l.tail;
    do{
        ptr=ptr->next;
        if(ptr->value==value){
            if(ptr==l.head && l.head->value==value){
                deleteHead(l,value);
            }
            else if(ptr==l.tail && l.tail->value==value){
                deleteTail(l,value);
            }
            else{
                ptr=removeElement(ptr);
            }
        }
    }while(ptr!=l.tail && l.head!= NULL);
   }

void showListFromHead(List2W& l){
    if(l.head==NULL){
        cout<<endl;
        return;
    }
    Element*ptr=l.tail;
    do{
        ptr=ptr->next;
        cout<<ptr->value<<",";
    }while(ptr!=l.tail);
    cout<<endl;
}

void showListFromTail(List2W& l){

    if(l.head==NULL){
        cout<<endl;
        return;
    }
    Element*ptr=l.head;
    do{
        ptr=ptr->prev;
        cout<<ptr->value<<",";
    }while(ptr!=l.head);
    cout<<endl;
}

void clearList(List2W& l){
    while(l.head!= NULL){
        int temp;
        deleteHead(l,temp);
    }
}

void addList(List2W& l1,List2W& l2){
    if((l1.head==l2.head && l1.tail==l2.tail) || l2.head== NULL){
        return;
    }
    if(l1.head== NULL){
        l1.head=l2.head;
        l1.tail=l2.tail;
        l2.head=l2.tail= NULL;
        return;
    }
    l1.tail->next=l2.head;
    l2.head->prev=l1.tail;
    l1.head->prev=l2.tail;
    l2.tail->next=l1.head;
    l1.tail=l2.tail;
    l2.head=l2.tail= NULL;
}

void deleteOdd(List2W& l){
    if(l.head==NULL){
        return;
    }
    Element *ptr = l.head;
    int i=1;
    do{
        ptr=ptr->next;
        if(i%2==1){
            if(ptr==l.tail){
                deleteTail(l,l.tail->value);
                return;
            }
            removeElement(ptr);
        }
        ++i;
    }while(ptr!=l.tail);
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
    List2W *list;
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
        if(isCommand(command,"DH")) //*
        {
            int retValue;
            bool retBool=deleteHead(list[currentL],retValue);
            if(retBool)
                cout << retValue << endl;
            else
                showBool(retBool);
            continue;
        }
        if(isCommand(command,"DT")) //*
        {
            int retValue;
            bool retBool=deleteTail(list[currentL],retValue);
            if(retBool)
                cout << retValue << endl;
            else
                showBool(retBool);
            continue;
        }

        if(isCommand(command,"SH")) //*
        {
            showListFromHead(list[currentL]);
            continue;
        }

        if(isCommand(command,"ST")) //*
        {
            showListFromTail(list[currentL]);
            continue;
        }

        if(isCommand(command,"CL")) //*
        {
            clearList(list[currentL]);
            continue;
        }

        if(isCommand(command,"IN")) //*
        {
            init(list[currentL]);
            continue;
        }

        // read next argument, one int value
        stream >> value;

        if(isCommand(command,"FV")) //*
        {
            int ret;
            ret=findValue(list[currentL],value);
            cout << ret << endl;
            continue;
        }

        if(isCommand(command,"RV")) //*
        {
            removeAllValue(list[currentL],value);
            continue;
        }


        if(isCommand(command,"AD")) //*
        {
            addList(list[currentL],list[value]);
            continue;
        }

        if(isCommand(command,"CH")) //*
        {
            currentL=value;
            continue;
        }

        if(isCommand(command,"IH")) //*
        {
            insertHead(list[currentL],value);
            continue;
        }

        if(isCommand(command,"IT")) //*
        {
            insertTail(list[currentL],value);
            continue;
        }

        if(isCommand(command,"GO")) //*
        {
            list=new List2W[value];
            continue;
        }

        cout << "wrong argument in test: " << command << endl;
    }
}