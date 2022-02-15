/* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //case 1 : when there is less than 3 numbers
        set<vector<int>> zeros;
        vector<vector<int>> retVal;
        if(nums.size()<3){
            return retVal;
        }
        //case 2 : when there is exactly 3 numbers;
        if(nums.size()==3){
            if(nums[0]+nums[1]+nums[2]==0){
                retVal.push_back(nums);
                return retVal;
            } else {
                return retVal;
            }
        }
        //case 3 : when there are more than 3 numbers
        sort(nums.begin(),nums.end()); // O(nlog(n))
        
        for(int i =0; i<nums.size()-2;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            //int target = -1*nums[i];
            int lo = i+1;
            int hi = nums.size()-1;
            while(lo<hi){
                int threesum = nums[i]+nums[lo]+nums[hi];
                if(threesum==0){
                    retVal.push_back({nums[i],nums[lo],nums[hi]});
                    lo++;
                    while(lo<hi&&nums[lo]==nums[lo-1]){
                        lo++;
                    }
                }else if(threesum>0){
                    hi--;
                }else{
                    lo++;
                }
            }
        }
        
        return retVal;
    }
};