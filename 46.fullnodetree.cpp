/*
Given a binary tree, print all nodes will are full nodes. Full Nodes are nodes which has both left and right children as non-empty.
Examples: 
 

Input :    10
          /  \
         8    2
        / \   /
       3   5 7
Output : 10 8

Input :   1
         / \
        2   3
           / \
          4   6     
Output : 1 3

*/

#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode (int data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void findFullNode (Node* root ){
    if(root != NULL){
        findFullNode(root->left);
        if(root->left!=NULL && root->right!=NULL){
            std::cout << root->data << " ";
        }
        findFullNode(root->right);
    }
}


int main()
{
    Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->right->left = newNode(7);
    root->left->right = newNode(5);
   
    findFullNode(root);
    
    return 0;
}