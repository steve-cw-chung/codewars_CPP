//binary search tree

#include <iostream>

using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;
};

class bst{
    Node * root;
    bool found = false;
    
    public:

    bst();
    void insert(int);
    void displayTree();
    bool search(int);
    void printTree(Node*);
    void binarySearch(Node*,int);

};

void bst::displayTree(){
    printTree(root);
}

void bst::printTree(Node* node){
    if(node==NULL){

    }else {
        printTree(node->left);
        cout << node->data << "  ";
        printTree(node->right);
    }
    
}

void bst::binarySearch(Node* node,int number){
    if(node==NULL){

    }else {
        binarySearch(node->left,number);
        if(node->data==number){
            found = true;
        }
        binarySearch(node->right,number);
    }
}

void bst::insert(int number){
    Node* temp = new Node;
    temp->data = number;
    temp->left = temp->right = NULL;
    if(root==NULL){
        root=temp;
    } else {
        Node * parent;
        Node * ptr;
        ptr = root;
        while(ptr!=NULL){
            parent = ptr;
            if(parent->data > number){
                ptr = parent->left;
            } else {
                ptr = parent->right;
            }
        }
        if(parent->data > number){
            parent->left = temp;
        } else {
            parent->right = temp;
        }
    }
}

bool bst::search(int number){
    binarySearch(root,number);
    bool retVal = found;
    found = false;

    return retVal;
}

bst::bst(){
    root = NULL;
}

int main (){
    bst b;
    b.insert(5);
    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(7);
    b.insert(6);
    b.insert(8);
    if(b.search(8)==false){
        cout << "Not Found!" << endl;
    }else {
        cout << "Found!" << endl;
    }
    return 0;
}