/* You are given pointer to the root of the binary search tree and two values  and . You need to return the lowest common ancestor (LCA) of  and  in the binary search tree.

image
In the diagram above, the lowest common ancestor of the nodes  and  is the node . Node  is the lowest node which has nodes  and  as descendants.

Function Description

Complete the function lca in the editor below. It should return a pointer to the lowest common ancestor node of the two values given.

lca has the following parameters:
- root: a pointer to the root node of a binary search tree
- v1: a node.data value
- v2: a node.data value

Input Format

The first line contains an integer, , the number of nodes in the tree.
The second line contains  space-separated integers representing  values.
The third line contains two space-separated integers,  and .

To use the test data, you will have to create the binary search tree yourself. Here on the platform, the tree will be created for you.

Constraints




The tree will contain nodes with data equal to  and .

Output Format

Return the a pointer to the node that is the lowest common ancestor of  and .

Sample Input

6
4 2 3 1 7 6
1 7
image

 and .

Sample Output

[reference to node 4]

Explanation

LCA of  and  is , the root in this case.
Return a pointer to the node. */
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    vector<int> getPath(Node * root,int value){
        vector<int> path;
        Node * ptr = root;
        if(root==NULL){
            return path;
        }
        if(root->data==value){
            path.push_back(root->data);
            return path;
        }
        while(ptr->data!=value){
            path.push_back(ptr->data);
            if(value<ptr->data){
                if(ptr->left!=NULL){
                    ptr = ptr->left;
                } else {
                    return path;
                }
                    
            }else{
                if(ptr->right!=NULL){
                    ptr = ptr->right;
                }else{
                    return path;
                }
            }
        }
        path.push_back(ptr->data);
        return path;
    }
    Node * findNode (Node*root,int value){
        Node * ptr = root;
        if(root==NULL){
            return NULL;
        }
        if(root->data==value){
            return root;
        }
        while(ptr->data!=value){
            if(value<root->data){
                ptr= ptr->left;
            }else{
                ptr = ptr->right;
            }
        }
        return ptr;
    }
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        // 1. All nodes saved in list 
        // 2. Ignore the v1 and v2
        // 3. Look for lca
        if(root==NULL){
            return NULL;
        }
        vector<int> p1 =getPath(root,v1);
        vector<int> p2 =getPath(root,v2);
 /*        for(int i =0; i<p1.size();i++){
            cout <<"i: " << i <<" p1[i] : "<< p1[i] << " " ;
        }
        cout <<endl;
        for(int i =0; i<p2.size();i++){
            cout <<"i: " << i <<" p2[i] : "<< p2[i] << " " ;
        }
        cout <<endl; */
        for(int i = p1.size()-1; i>=0; i--){
            for(int j = p2.size()-1; j>=0; j--){
                if(p1[i]==p2[j]){
                    return findNode(root,p1[i]);
                }
            }
        }
        return root;
    }

}; //End of Solution