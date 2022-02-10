/* Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum =0;
        m[0]++;
        int count = 0;
        for(int i =0; i<nums.size();i++){
            sum+=nums[i];
            count += m[sum-k];
            m[sum]++;
        }
        return count;
    }
};