
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

struct bintree_node {
    int data;
    bintree_node* left;
    bintree_node* right;
};
//class for binary tree
class bst{
    bintree_node *root;
    int previous; // for duplicate check
    bool duplicate = false; 
    public:
    bst(){
        root=NULL;
    }
    int isempty() {
        return(root==NULL);
    }
    void insert(int item);
    void displayBinTree();
    void printBinTree(bintree_node *);
    void hasDuplicate();
     
};
void bst::hasDuplicate(){
  cout<< duplicate<<endl;

}
// insert node in an appropriate place.
void bst::insert (int value){
    bintree_node * temp = new bintree_node;
    bintree_node * parent = NULL;
    temp->data = value;
    temp->left = temp->right = NULL;
    //when root is null, insert the node to root.
    if (isempty()){
      root = temp;
    } else {
      //look for the right place to add the new node.
      bintree_node * ptr = root; 
      while (ptr!=NULL){
        parent = ptr;
        if(parent->data>value){
          if(parent->left==NULL){
            parent->left=temp;
            ptr=NULL;
          }else {
            ptr = parent->left;
          }
          
        } else {
          if(parent->right==NULL){
            parent->right = temp;
            ptr=NULL;
          } else {
            ptr= parent->right;   
          }
        }
      }
    }
}
void bst::displayBinTree(){
  printBinTree(root);
}

void bst::printBinTree(bintree_node *ptr){
  if (ptr!=NULL){

    //Inorder
    printBinTree(ptr->left);
    if(previous!=ptr->data){
      cout<< ptr->data << "  " <<endl;
      previous = ptr->data;
    }else{
      duplicate = true;
      cout<< ptr->data << "  " <<endl;
      previous=ptr->data;
    }
    
    printBinTree(ptr->right);

   /*  //Postorder
    printBinTree(ptr->left);
  
    printBinTree(ptr->right);
    cout<< ptr->data << "  " <<endl; */
    /* //Preorder
    cout<< ptr->data << "  " <<endl;
    printBinTree(ptr->left);
    printBinTree(ptr->right); */
  }
  
}

int main (){

    bst b;
    b.insert(20);
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(40);
    b.insert(45);
    b.insert(30); 
    b.insert(20);

    cout << "binary tree : " << endl;
    b.displayBinTree();

    b.hasDuplicate();
    
    
    return 0;
}