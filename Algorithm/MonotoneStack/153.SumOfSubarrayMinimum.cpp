/* Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104 */

/*class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int,int>>stk_prev,stk_next;
        vector<int>prev(arr.size());
        vector<int>next(arr.size());
         for(int i = 0; i < arr.size(); i++) prev[i] =  i + 1;
         for(int i = 0; i < arr.size(); i++) next[i] = arr.size() - i;
        
        for(int i = 0; i<arr.size();i++){
            
            //get prev stack
            while(!stk_prev.empty()&&stk_prev.top().first>arr[i]) stk_prev.pop();
            prev[i]=stk_prev.empty()?i+1:i-stk_prev.top().second;
            stk_prev.push({arr[i],i});
            //get next stack
            while(!stk_next.empty()&&stk_next.top().first>arr[i]){
                next[stk_next.top().second]=i-stk_next.top().second;
                stk_next.pop();
            }
            stk_next.push({arr[i],i});
            
        }
        int sum =0;
        int mod = 1e9 +7;
        for(int i = 0; i<arr.size();i++){
            sum=(sum+(prev[i]*next[i]*arr[i]))%mod;
        }
        return sum;
        
        //calculate
    }
};
*/
class Solution {
public:
    int sumSubarrayMins(vector<int> A) {
        long res = 0, n = A.size(), mod = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<pair<int, int>> s1,s2;
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!s1.empty() && s1.top().first > A[i]) {
                count += s1.top().second;
                s1.pop();
            }
            s1.push({A[i], count});
            left[i] = count;
        }
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!s2.empty() && s2.top().first >= A[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({A[i], count});
            right[i] = count;
        }
        for (int i = 0; i < n; ++i)
            res = (res + (long)A[i] * left[i] * right[i]) % mod;
        return res;
    }
};