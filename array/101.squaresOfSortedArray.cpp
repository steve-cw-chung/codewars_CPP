/* Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach? */

/*class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int p1 = -1;
        int p2 = nums.size();
        vector<int> solution;
        for(int i =0; i<nums.size();i++){
            if(nums[i]>=0){
                p2 = i;
                //p1 = i-1;
                break;
            }
        }
        for(int i =0; i<nums.size();i++){
            if(nums[i]<0){
                p1=i;
                
            }else{
                break;
            }
        }
        while(p1>=0 && p2<=nums.size()-1){
            if(abs(nums[p1])<=nums[p2]){
                solution.push_back(nums[p1]*nums[p1--]);
            }else{
                solution.push_back(nums[p2]*nums[p2++]);
            }
        }
        while(p1>=0){
            solution.push_back(nums[p1]*nums[p1--]);
        }
        while(p2<=nums.size()-1){
            solution.push_back(nums[p2]*nums[p2++]);
        }
        return solution;
    }
};*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int l = 0, r = A.size() - 1;
        for (int k = A.size() - 1; k >= 0; k--) {
            if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--];
            else res[k] = A[l] * A[l++];
        }
        return res;
    }
};