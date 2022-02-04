/* Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1. */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        /*int sum=0;
        unordered_map<int,int> m;
        unsigned int longestContArray = 0;
       
        for(int i=0;i<nums.size();i++){
           sum += (nums[i]==0)?-1:1;
           
           auto it = m.find(sum);
           
           if(sum == 0){
              if(longestContArray < i+1)
               longestContArray = i+1;
           }
           else if(it != m.end()){
              if(longestContArray < i-it->second)
               longestContArray = i-it->second;
           }
           else if(it == m.end())
                m.insert({sum,i});
       }
        return longestContArray;*/
        unordered_map <int, int> m;
        int longestSubArray;
        int sum = 0;
        for(int i =0; i<nums.size();i++){
            sum += (nums[i]==0)?-1:1;
            auto x = m.find(sum);
            if(sum==0){
                if(longestSubArray<i+1){
                    longestSubArray=i+1;
                }
            }else if(x==m.end()){
                m[sum]=i;
            }else if (x!=m.end()){
                if(longestSubArray<i-x->second){
                    longestSubArray=i-x->second;
                }
            }
        }
        return longestSubArray;
    }
};