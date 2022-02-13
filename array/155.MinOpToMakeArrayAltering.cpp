/* You are given a 0-indexed array nums consisting of n positive integers.

The array nums is called alternating if:

nums[i - 2] == nums[i], where 2 <= i <= n - 1.
nums[i - 1] != nums[i], where 1 <= i <= n - 1.
In one operation, you can choose an index i and change nums[i] into any positive integer.

Return the minimum number of operations required to make the array alternating.

 

Example 1:

Input: nums = [3,1,3,2,4,3]
Output: 3
Explanation:
One way to make the array alternating is by converting it to [3,1,3,1,3,1].
The number of operations required in this case is 3.
It can be proven that it is not possible to make the array alternating in less than 3 operations. 
Example 2:

Input: nums = [1,2,2,2,2]
Output: 2
Explanation:
One way to make the array alternating is by converting it to [1,2,1,2,1].
The number of operations required in this case is 2.
Note that the array cannot be converted to [2,2,2,2,2] because in this case nums[0] == nums[1] which violates the conditions of an alternating array.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105 */
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>m1,m2;
        int totalOdd=0,totalEven=0;
        int higherFreq=0;
        int oddOrEven = 0;
        for(int i =0; i<nums.size();i++){
            if(i%2==0){
                m2[nums[i]]++;
                totalEven++;
                if(higherFreq<m2[nums[i]]){
                    higherFreq=m2[nums[i]];
                    oddOrEven =2;
                }
            }
            if(i%2!=0){
                m1[nums[i]]++;
                totalOdd++;
                if(higherFreq<m1[nums[i]]){
                    higherFreq=m1[nums[i]];
                    oddOrEven =1;
                }
            }
        }
        int maxOdd=0,maxEven=0,maxOddFreq=0,maxEvenFreq=0;
        if(oddOrEven==1){
            for(auto x : m1){
                if(maxOddFreq<x.second){
                    maxOddFreq=x.second;
                    maxOdd=x.first;
                }
            }
            for(auto x : m2){
                if(maxEvenFreq<x.second && x.first!=maxOdd){
                    maxEvenFreq=x.second;
                    maxEven=x.first;
                }
            }    
        }else if (oddOrEven==2){
            for(auto x : m2){
                if(maxEvenFreq<x.second){
                    maxEvenFreq=x.second;
                    maxEven=x.first;
                }
            }  
            for(auto x : m1){
                if(maxOddFreq<x.second&&maxEven!=x.first){
                    maxOddFreq=x.second;
                    maxOdd=x.first;
                }
            }
              
        }
        
        return (totalOdd+totalEven-maxOddFreq-maxEvenFreq);
    }
};