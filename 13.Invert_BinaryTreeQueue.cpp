#include <iostream>
#include <queue>

struct Node{
    int data;
    Node *left, *right;

    Node(int data){
        this->data =  data;
        this->left = this->right = nullptr;
    }

};

//Function to perform preorder traversal of the binary tree
void preorder(Node* root){
    if (root == nullptr)
        return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}

// Iterative Function to invert given binary Tree using queue
void invertBinaryTree(Node* root){
    // base case: if tree is empty
    if(root == nullptr)
        return;

    //maintain a queue and push root node
    std::queue<Node*> q;
    q.push(root);

    // loop until queue is empty
    while (!q.empty()){
        // pop top node from queue
        Node* curr = q.front();
        q.pop();

        // swap left child with right child 
        std::swap(curr->left, curr->right);
        
        //push left child of popped node to the queue
        if (curr->left)
            q.push(curr->left);
        //push right child of popped node to the queue
        if (curr->right)
            q.push(curr->right);

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
    std::cout << std::endl;
    invertBinaryTree(root);
    preorder(root);
    return 0;
}