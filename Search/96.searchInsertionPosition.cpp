/* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //Binary Search

        int leftBound = 0;
        int rightBound = nums.size()-1;
        while(leftBound<rightBound){
            int mid = leftBound + (rightBound-leftBound)/2;
            if(nums[mid]==target){
                return mid;
            } else if (nums[mid]>target){
                rightBound = mid-1;
            } else{
                leftBound = mid +1;
            }
        }
        int answer;
        if(target>nums[leftBound]){
            answer = leftBound+1;
        } else {
            answer = leftBound;
        }
        return answer;
    }
};