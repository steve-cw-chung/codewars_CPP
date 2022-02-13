/* Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique. */
class Solution {
public:
    void helper(vector<vector<int>>&subs,vector<int>&nums,int size,vector<int>&curr,int start){
        if(curr.size()==size){
            subs.push_back(curr);
            return;
        }
        for(int i = start; i<nums.size();i++){
            curr.push_back(nums[i]);
            helper(subs,nums,size,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //backtracking?
        // i = number of integers
        vector<vector<int>> subs;
        vector<int> curr;
        for(int i = 0; i<=nums.size();i++){
            helper(subs,nums,i,curr,0);
        }
        return subs;
    }
};

// Recursive Solution
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
class Solution {
public:
    vector<vector<int>> ans;
    
    void sub(vector<int> &nums, int i, vector<int> temp)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        sub(nums, i+1, temp);
        temp.push_back(nums[i]);
        sub(nums, i+1, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;       
        sub(nums, 0, temp); // or sub(nums, 0, vector<int> {});
        return ans;
    }
};
// Iterative Solution
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        ans.push_back({});
        
        for(int i=0; i<n; i++)
        {
            int sz = ans.size();
            for(int j=0; j<sz; j++)
            {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
// Bit Manipulation
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int num = pow(2, n), i = 0;
        
        while(i<num)
        {
            vector<int> temp;
            for(int j=0; j<n; j++)
            {
                if(i & 1<<j)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
            i++;
        }
        
        return ans;
    }
};