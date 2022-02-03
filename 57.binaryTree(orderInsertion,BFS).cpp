//inverting binary tree

#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class BTree{
    TreeNode * root;
    int maxHeight = 0;
    public:
    BTree(){
        root = NULL;
    }
    void insert(int);
    void printTree();
    void getHeight(TreeNode*,int);
    void printCurrentLevel(TreeNode*,int);
};
void BTree::printCurrentLevel(TreeNode *node, int level){
    if(node==NULL) return;
    if(level==1){
        cout << node->val << " " ; 
    } else {
        printCurrentLevel(node->left,level-1);
        printCurrentLevel(node->right,level-1);
    }

}
void BTree::getHeight(TreeNode* Node, int height){
    if(Node==NULL) return;
    if(height>maxHeight){
        maxHeight = height;
    }
    getHeight(Node->left,height+1);
    getHeight(Node->right,height+1); 
}
void BTree::printTree(){
    getHeight(root,1);
    cout << "maxHeight : " << maxHeight << endl;
    for(int i =1; i<=maxHeight; i++){
        printCurrentLevel(root,i);
    }
}

void BTree::insert(int val){
    TreeNode * temp = new TreeNode;
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
  
    if(root==NULL){
        root=temp;
    }else {
        queue<TreeNode*> q;
        q.push(root);
        //find next available position
        while(!q.empty()){
            TreeNode * ptr = q.front();
            q.pop();
            if(ptr->left!=NULL){
                q.push(ptr->left);
            }else {
                ptr->left = temp;
                return;
            }
            if(ptr->right!=NULL){
                q.push(ptr->right);
            }else {
                ptr->right = temp;
                return;
            }
        }

    } 
}

int main () {
    BTree b;
    b.insert(5);
    b.insert(2);
    b.insert(3);
    b.insert(1);
    b.insert(4);
    b.insert(10);
    
    b.printTree();

    return 0;
}