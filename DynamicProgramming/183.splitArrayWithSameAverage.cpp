/* You are given an integer array nums.

You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).

Return true if it is possible to achieve that and false otherwise.

Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.
Example 2:

Input: nums = [3,1]
Output: false
 

Constraints:

1 <= nums.length <= 30
0 <= nums[i] <= 104 */
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        if(A.size()<=1) {
            return false;
        }
        int n = A.size();
        int Sum = 0;
        for(auto x: A) Sum += x;
        
        int dp[Sum+1];
        memset(dp, 0, sizeof dp);
        dp[A[0]] = 2;
        for(int i=1; i<n; i++) {
            for(int s=Sum-A[i]; s>=0; s--) {
                if(dp[s])
                    dp[s+A[i]] |= (dp[s]<<1);
            }
            dp[A[i]] |= 2;
        }
        for(int len=1; len<n; len++) {
            if( (Sum*len)%n == 0 && ((1<<len) & dp[Sum*len/n])) {
                return true;
            }
        }
        return false;
    }
};