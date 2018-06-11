#include<iostream>
#include <string>
#include <sstream>

// BST

using namespace std;

template <class T>
class MyBST{
private:

    struct Element{
        T key;
        int value;
    };

    struct Node{
        Element elem;
        Node *left,*right,*parent;
    };

// Binary search tree
    struct BST{
        Node *root;
    };

    BST tree;
public:
    MyBST(){
        tree.root=NULL;
    }


bool insertElem(BST & tree, Element elem){

    Node* tempNode=tree.root;
    bool leftLeaf;

    while(tempNode!=NULL){
        if(tempNode->elem.key==elem.key){
            return false;
        }
        if(tempNode->elem.key>elem.key){
            if(tempNode->left==NULL){
                leftLeaf=1;
                break;
            }
            tempNode=tempNode->left;
        }
        else{
            if(tempNode->right==NULL){
                leftLeaf=0;
                break;
            }
            tempNode=tempNode->right;
        }
    }

    //now tempNode is parent for newNode

    Node* newNode=new Node;
    newNode->parent=tempNode;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->elem=elem;

    if(tree.root==NULL){
        tree.root=newNode;
        return true;
    }

    if(leftLeaf){
        tempNode->left=newNode;
    }
    else{
        tempNode->right=newNode;
    }
    return true;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    cout<<node->elem.key<<'('<<node->elem.value<<"),";

    printInorder(node->right);
}
void showInorder(BST & tree){
    printInorder(tree.root);
    cout<<endl;
}

void printPreorder(Node* node)
{
    if (node == NULL)
        return;

    cout<<node->elem.key<<'('<<node->elem.value<<"),";

    printPreorder(node->left);

    printPreorder(node->right);
}
void showPreorder(BST & tree){
    printPreorder(tree.root);
    cout<<endl;
}

void printPostorder(Node* node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);

    printPostorder(node->right);

    cout<<node->elem.key<<'('<<node->elem.value<<"),";
}
void showPostorder(BST & tree){
    printPostorder(tree.root);
    cout<<endl;
}

Node *findNode(Node *node,int key){

    if (node == NULL)
        return NULL;

    if(node->elem.key==key){
        return node;
    }

    Node* foundNode = findNode(node->left, key);
    if(foundNode == NULL) {
        foundNode = findNode(node->right, key);
    }
    return foundNode;
}


bool MyFindKey(Node* node,int key,Element &outputElem)
{
    if (node == NULL)
        return false;

    if(node->elem.key==key){
        outputElem=node->elem;
        return true;
    }

    if(node->elem.key>key){
        return MyFindKey(node->left,key,outputElem);
    }
    else{
        return MyFindKey(node->right,key,outputElem);
    }
}

bool findKey(BST & tree,int key, Element &elem){
    Element forOutput;
    if(MyFindKey(tree.root,key,forOutput)){
        elem=forOutput;
        return true;
    }
    return false;
}


Node * findMinNode (Node * node){
    while (node->left != NULL){
        node = node->left;
    }
    return node;
}

Node* findSuccessor(Node *node)
{
    if( node->right != NULL ){
        return findMinNode(node->right);
    }


    Node *p = node->parent;
    while(p != NULL && node == p->right)
    {
        node = p;
        p = p->parent;
    }
    if(p!=NULL)
    return p;
}

    Node* myDeleteNode(BST &tree, Node* node,Element &elem){

        if (node == NULL) return node; //empty

        static bool elemSet = false;

        if(elemSet == false){
            elem=node->elem;
            elemSet = true;
        }

        //1-element tree
        if(node==tree.root && node->left ==NULL && node->right==NULL) {
            delete node;
            tree.root=NULL;
            return NULL;
        }

        //no children
        if(node->left == NULL && node->right == NULL){
            if(node == node->parent->left) {
                node->parent->left = NULL;
            }
            else{
                node->parent->right=NULL;
             }
            delete node;
            elemSet = false;
            return NULL;
        }

        //has only left child
        if(node->left != NULL && node->right == NULL){
            if(node->parent == NULL){
                tree.root=node->left;
                tree.root->parent=NULL;
                delete node;
                return NULL;
            }

            if(node == node->parent->left) {
                node->parent->left = node->left;
            }
            else{
                node->parent->right=node->left;
            }
            node->left->parent=node->parent;
            delete node;
            elemSet = false;
            return NULL;
        }

        //has only right child
        if(node->left == NULL && node->right != NULL){
            if(node->parent == NULL){
                tree.root=node->right;
                tree.root->parent=NULL;
                delete node;
                return NULL;
            }

            if(node == node->parent->left) {
                node->parent->left = node->right;
            }
            else{
                node->parent->right=node->right;
            }
            node->right->parent=node->parent;
            delete node;
            elemSet = false;
            return NULL;
        }

        //two children or root
        Node* successor=findSuccessor(node);
        if(successor!=NULL){
            node->elem=successor->elem;
        }
        myDeleteNode(tree,successor,elem);
    }

    bool removeKey(BST &tree, int key, Element &elem){
        Node* toRemove=findNode(tree.root,key);

        if(toRemove==NULL){
            return false;
        }

        myDeleteNode(tree,toRemove,elem);

        return true;
    }


void MyClear(Node* node){
    if(node==NULL){
        return;
    }
    MyClear(node->left);
    MyClear(node->right);
    delete node;
}

void clear(BST & tree){
    MyClear(tree.root);
    tree.root=NULL;
}


void MyCountNodes(Node* node,int &num)
{
    if (node == NULL)
        return;

    MyCountNodes(node->left,num);

    MyCountNodes(node->right,num);

    ++num;
}

void getNumOfLeaves(Node* node,int &numLeaves)
{
    if (node == NULL)
        return;

    getNumOfLeaves(node->left,numLeaves);

    if(node->left == node->right) numLeaves++;

    getNumOfLeaves(node->right,numLeaves);
}

int CountLeaves(BST tree){
    int numLeaves=0;
    getNumOfLeaves(tree.root,numLeaves);
    return numLeaves;
}


int numberOfNodes(BST & tree){
    int sum=0;
    MyCountNodes(tree.root,sum);
    return sum;
}

int MyHeight(Node* node){
    if(node==NULL){
        return 0;
    }
    int leftHeight = MyHeight(node->left);

    int rightHeight = MyHeight(node->right);

    if(leftHeight < rightHeight){
        return rightHeight +1;
    }
    else{
        return leftHeight +1;
    }
}

int height(BST & tree){
    return MyHeight(tree.root);
}

}; //end of class

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

    return 0;
}