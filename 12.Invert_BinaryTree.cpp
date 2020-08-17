#include <iostream>

// Data structure to store a Binary Tree node
struct Node{
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        this->left = this->right = nullptr;

    }
};
//Function to perform preorder traversal of the binary 
void preorder(Node* root){
    if (root == nullptr)
        return;

    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}

/* void swap(Node* left, Node *right){
    Node* temp;
    temp = left;
    left = right;
    right = temp;
} */

//FUnction to invert given binary Tree using preorder
void invertBinaryTree(Node *root){
    // base casee: if tree is empty
    if(root == nullptr)
        return;
    
    //swap left subtree with right subtree
    std::swap(root->left, root->right);

    //invert left subtree
    invertBinaryTree(root->left);

    //invert right subtree
    invertBinaryTree(root->right);
}

int main(){
    Node* root = nullptr;

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node (6);
    root->right->right = new Node (7);

    preorder(root);
    std::cout<<std::endl;

    invertBinaryTree(root);
    preorder(root);

    return 0;
}