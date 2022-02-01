/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done? */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //sort decreasing order, count number of zeroes, sort increasing order 0 to size - number of zeroes
        /*
        map<int,int> m; 
        int zeroes=0;
        for(int i =0; i <nums.size();i++){
            if(nums[i]!=0)
                m[i]=nums[i];
        }
        int lastIndex,nextIndex= 0;
        for(auto x: m){
            cout << x.first << " " << x.second << endl; 
            nums[nextIndex++]=x.second;
            
        }
        for(int i =nextIndex;i<nums.size();i++){
            nums[i]=0;
        }
 */
        for(int lastNonZeroIndex=0, cur=0;cur<nums.size();cur++){
            if(nums[cur]!=0){
                swap(nums[lastNonZeroIndex++],nums[cur]);
            }
        }
    }
};