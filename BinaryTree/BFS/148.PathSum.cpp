/* Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000 */
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
/*
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        queue<pair<TreeNode*,int>>q;
        q.emplace(root,root->val);
        while(!q.empty()){
            TreeNode * curr = q.front().first;
            int sum = q.front().second;
            q.pop();
            if(curr->left) q.emplace(curr->left,sum+curr->left->val);
            if(curr->right) q.emplace(curr->right,sum+curr->right->val);
            if(!curr->left&&!curr->right) {
                if(sum==targetSum) return true;
            }
        }
        return false;
    }
};

*/
class Solution {
    bool found = false;
public:
    void DFS(TreeNode*root, int sum, int targetSum){
        if(!root){
            return;
        }
        sum +=root->val;
        if(!root->left && !root->right){
            if(sum==targetSum){
                found = true;
            }
        }
        DFS(root->left,sum,targetSum);
        DFS(root->right,sum,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        DFS(root,0,targetSum);
        return found;
    }
};