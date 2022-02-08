/* Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively? */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*class Solution {
    vector<int> postorder;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root){
            return postorder;
        }
        
        postorderTraversal(root->left);
    
        postorderTraversal(root->right);
        postorder.push_back(root->val);
        return postorder;
    }
};*/
/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* last = NULL;
        while (root || !todo.empty()) {
            if (root) {
                todo.push(root);
                root = root -> left;
            } else {
                TreeNode* node = todo.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } else {
                    nodes.push_back(node -> val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return nodes;
    }
};
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        if(root)stk.push(root);
        vector<int> ans;
        while(stk.size())
        {
            auto p = stk.top();
            //All children nodes are visited
            if(p == nullptr)
            {
                stk.pop();
                ans.push_back(stk.top()->val);
                stk.pop();
                continue;
            }
            //Use nullptr to mark parent node
            stk.push(nullptr);
            //last in first out
            if(p->right)stk.push(p->right);
            if(p->left)stk.push(p->left);
        }
        return ans;
    }
};