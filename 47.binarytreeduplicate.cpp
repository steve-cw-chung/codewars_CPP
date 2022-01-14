
/* Check if a Binary Tree (not BST) has duplicate values
Examples: 
 

Input : Root of below tree
         1
       /   \
      2     3
             \
              2
Output : Yes
Explanation : The duplicate value is 2.

Input : Root of below tree
         1
       /   \
     20     3
             \
              4
Output : No
Explanation : There are no duplicates. */

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node * insert (int value){
    Node * temp = new Node;
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

int main (){


    Node* root = insert(1);

    return 0;
}