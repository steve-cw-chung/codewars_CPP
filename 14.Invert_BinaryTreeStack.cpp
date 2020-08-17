#include <iostream>
#include <stack>

struct Node{ 
    int data;
    Node* left, * right;

    Node(int data){
        this->data = data;
        this->left = this->right = nullptr;

    }
};

//Function to perform preorder traversal of the binary tree

void preorder(Node* root){

    if (root==nullptr)
        return;

    std::cout<< root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Iterative Function to invert given binary Tree using stack
void invertBinaryTree(Node* root){
    // base case: if tree is empty 
    if(root==nullptr)
        return;
    
    // create a empty stack and push root node

    std::stack<Node*> s;
    s.push(root);

    //loop until stack is empty
    while(!s.empty()){
        //pop top node from stack
        Node* curr = s.top();
        s.pop();

        //swap left child with right child
        std::swap(curr->left,curr->right);
        //push right child onto the stack
        if(curr->right)
            s.push(curr->right);

        //push left child onto the stack
        if(curr->left)
            s.push(curr->left);
    }


}

int main(){
    Node* root = nullptr;

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preorder(root);

    std::cout<<std::endl;
    invertBinaryTree(root);
    preorder(root);

    return 0;
}