#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
};

class bitree{
    Node * root ;
    int height;
    public: 
    bitree(){
        root = NULL;
    }
    bool isEmpty();

    void insert(int);
    void printTree(Node *); 
    void displayBiTree();   
    void printLevelOrder();
    void printCurrentLevel(Node*,int);
};

void bitree::printCurrentLevel(Node * node, int level){
    if(node==NULL){

    } else if (level==1){
        cout<< node->data << "  ";
    } else {
        printCurrentLevel(node->left,level-1);
        printCurrentLevel(node->right,level-1);
    }

}

void bitree::printLevelOrder(){
    for (int i = 1; i <=height;i++){
        printCurrentLevel(root,i);
    }

}
bool bitree::isEmpty(){
    return root==NULL;
}

void bitree::insert(int value){
    Node * temp = new Node;
    temp->data = value;
    temp->left=temp->right=NULL;
    if(isEmpty()){
        root=temp;
    } else {
        Node * parent = root;
        Node * ptr = root;
        
        while(ptr!=NULL){
            parent = ptr;
            if(value < parent->data){
                ptr= parent->left;
            } else {
                ptr= parent->right;
            }
 
        }
        if(value < parent-> data){
            parent->left = temp;
        } else {
            parent -> right= temp;
        }
    }
}
void bitree::displayBiTree(){
    printTree(root);
}
void bitree::printTree(Node * node){
    //print tree
    if(node!=NULL){
        cout <<  node->data<< endl;
        printTree(node->left);
        printTree(node->right);
    }
    
}


int main(){
    bitree b;
    b.insert(5);
    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(7);
    b.insert(6);
    b.insert(8);
    //b.displayBiTree();
    b.printLevelOrder();
    return 0;
}