/* Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1 */


class Solution {
    
public:
    class TrieNode{
        public:
        TrieNode * next [2];
        TrieNode(){
            next[0]=NULL;
            next[1]=NULL;
        }
    };
    TrieNode * createTrie(vector<int>& nums){
        TrieNode* root = new TrieNode();
        // O(31)
        TrieNode* curr;
        
        for(int j=0;j<nums.size();j++){
            int num = nums[j];
            curr = root;
           for(int i=31;i>=0; i--){
            int index = ((num>>i) & 1);
                if(curr->next[index]==NULL){
                    curr->next[index] = new TrieNode();
                }
                    curr = curr->next[index];
                
            } 
        }
        
        
        return root;
    }
        TrieNode* buildTrie(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        TrieNode*cur;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            cur = root;
            for (int j = 31; j >= 0; j--) {
                int index = ((num >> j) & 1);
                if (cur->next[index] ==  NULL)
                    cur->next[index] = new TrieNode();
                cur = cur->next[index];
            }
        }
        return root;
    }
    
    
    int helper2(TrieNode* cur, int num) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1) ? 0 : 1;
            if (cur->next[index]) {
                res <<= 1;
                res |= 1;
                cur = cur->next[index];
            } else {
                res <<= 1;
                res |= 0;
                cur = cur->next[index ? 0 : 1];
            }
        }
        return res;
    }
    
    
    int helper(TrieNode * root, int num){
        TrieNode* curr = root;
        int potential =0;
        for(int i=31;i>=0;i--){
            int index = ((num>>i) & 1)?0:1;
            if(curr->next[index]==NULL){
                potential<<=1;
                potential+=0;
                curr=curr->next[!index];
            }else{
                potential<<=1;
                potential+=1;
                curr=curr->next[index];
            }
        }
        return potential;
    }
    
    
    int findMaximumXOR(vector<int>& nums) {
        //root = new TrieNode;   
        // O(n)
        TrieNode * root = createTrie(nums);
        //TrieNode * root = buildTrie(nums);
     
        int maximum =0;
        for(int i =0; i<nums.size();i++){
            maximum = max(maximum,helper(root,nums[i]));
        }
        
        
        return maximum;
    }
    
};

/*
class Solution {
public:
    class TreeNode {
    public:
        TreeNode* next[2];
        TreeNode () {next[0] = NULL; next[1] = NULL;};
    };
    TreeNode* buildTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(), *cur;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            cur = root;
            for (int j = 31; j >= 0; j--) {
                int index = ((num >> j) & 1);
                if (cur->next[index] ==  NULL)
                    cur->next[index] = new TreeNode();
                cur = cur->next[index];
            }
        }
        return root;
    }
    
    int helper(TreeNode* cur, int num) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1) ? 0 : 1;
            if (cur->next[index]) {
                res <<= 1;
                res |= 1;
                cur = cur->next[index];
            } else {
                res <<= 1;
                res |= 0;
                cur = cur->next[index ? 0 : 1];
            }
        }
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        TreeNode* root = buildTree(nums);
        
        for (auto i : nums) {
            res = max(res, helper(root, i));
        }
        
        return res;
    }
};*/