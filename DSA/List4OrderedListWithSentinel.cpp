#include<iostream>
#include <string>
#include <sstream>

using namespace std;


struct Element{
    int key;
    int value;
};

struct ElementLL{
    Element elem;
    ElementLL *next, *prev;
};

// Two-way ordered cycled list with sentinel
struct List2W{
    ElementLL *sentinel;
};

void init(List2W& l){
    l.sentinel=new ElementLL();
    l.sentinel->next=l.sentinel;
    l.sentinel->prev=l.sentinel;
}

ElementLL* insertElem(List2W & l, Element elem, ElementLL* startFromThis){
    ElementLL *newELL = new ElementLL;
    newELL->elem=elem;
    ElementLL *ptr=startFromThis;
    do{
        ptr=ptr->next;
    }while(ptr->elem.key<=elem.key && ptr!=l.sentinel);
    newELL->next=ptr;
    newELL->prev=ptr->prev;
    ptr->prev->next=newELL;
    ptr->prev=newELL;
   return newELL;
}

bool findKey(List2W & l,int key, Element &elem){
    if(l.sentinel==l.sentinel->next){
        return false;
    }
    ElementLL *ptr = l.sentinel;
    do{
        ptr=ptr->next;
    }while(ptr->elem.key!=key && ptr!=l.sentinel);
    if(ptr==l.sentinel){
        return false;
    }
    elem=ptr->elem;
    return true;
}

ElementLL* removeELL(List2W l, ElementLL *toDelete){
    if(toDelete==l.sentinel){
        return l.sentinel;
    }
    toDelete->prev->next=toDelete->next;
    toDelete->next->prev=toDelete->prev;
    ElementLL *temp = toDelete->next;
    delete toDelete;
    return temp;
}

void deleteOdd(List2W &l){
    ElementLL* ptr=l.sentinel;
    for(int i=0;ptr!=l.sentinel;++i){
        if(i%2==1){
            ptr=removeELL(l,ptr);
        }
        else{
            ptr=ptr->next;
        }
    }
}

void removeAllKeys(List2W& l, int key){
    if(l.sentinel==l.sentinel->next){
        return;
    }
    ElementLL *ptr = l.sentinel;
    do{
        ptr=ptr->next;
        if(ptr->elem.key==key){
            removeELL(l,ptr);
            if(ptr->next->elem.key!=key){
                return;
            }
        }
    }while(ptr!=l.sentinel);
}

void showListFromHead(List2W& l){
    ElementLL * ptr = l.sentinel->next;
    while(ptr!=l.sentinel){
        cout<<ptr->elem.key<<'('<<ptr->elem.value<<"),";
        ptr=ptr->next;
    }
    cout<<endl;
}

void showListFromTail(List2W& l){
    ElementLL * ptr = l.sentinel->prev;
    while(ptr!=l.sentinel){
        cout<<ptr->elem.key<<'('<<ptr->elem.value<<"),";
        ptr=ptr->prev;
    }
    cout<<endl;
}

void clearList(List2W& l){
    ElementLL *ptr=l.sentinel->next;
    while(ptr!=l.sentinel){
       ptr = removeELL(l,ptr);
    }
}

void addList(List2W& l1,List2W& l2){
    if(l1.sentinel==l2.sentinel || l2.sentinel==l2.sentinel->next){
        return;
    }
    ElementLL *pL2=l2.sentinel->next;
    ElementLL *pL1=l1.sentinel;
    while(pL2!=l2.sentinel){
        pL1=insertElem(l1,pL2->elem,pL1);
        pL2=pL2->next;
    }
    clearList(l2);
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

        // zero-argument command
        if(isCommand(command,"HA")){
            cout << "END OF EXECUTION" << endl;
            break;
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

        if(isCommand(command,"FK"))
        {
            Element elem;
            bool ret=findKey(list[currentL], value, elem);
            if(ret)
                cout << elem.key << '(' << elem.value << ')' << endl;
            else
                cout << "false" << endl;
            continue;
        }

        if(isCommand(command,"RK"))
        {
            removeAllKeys(list[currentL],value);
            continue;
        }

        if(isCommand(command,"CH"))
        {
            currentL=value;
            continue;
        }

        if(isCommand(command,"IE"))
        {
            int variable2;
            stream >> variable2;
            Element elem;
            elem.key=value;
            elem.value=variable2;
            insertElem(list[currentL],elem,list[currentL].sentinel);
            continue;
        }

        if(isCommand(command,"GO"))
        {
            list=new List2W[value];
            continue;
        }

        if(isCommand(command,"AD"))
        {
            addList(list[currentL],list[value]);
            continue;
        }
        cout << "wrong argument in test: " << command << endl;
    }
    return 0;
}