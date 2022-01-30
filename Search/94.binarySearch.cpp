/* Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order. */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //start at mid 
        
        int mid = nums.size()/2;
        int rightBound = nums.size()-1;
        int index = mid;
        int leftBound = 0;
        cout << "1 : nums[index] = " << nums[index] << " mid = " << mid <<endl;
        int counter = 0;
        while(nums[index]!=target&&counter<nums.size()/2){
            if(nums[index]>target){
                cout << "greater than target ! " << endl;
                rightBound = mid;
                mid=(rightBound-leftBound)/2;
                 
                cout << "mid = " <<  mid  <<endl;
            }else{
                cout << "smaller than target ! " << endl;
                leftBound = mid;
                mid += (rightBound-mid) / 2;
                if(mid==leftBound){
                    mid++;
                }
                cout << "mid = " <<mid <<endl;
            }
            
            index = mid;
            counter++;
            cout << "nums[index] = " << nums[index] << " mid = " << mid <<endl;
        }
            if(nums[index]!=target) return -1;
            return index;
    }
};