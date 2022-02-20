/* Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that:

0 <= i < j <= n - 1 and
nums[i] * nums[j] is divisible by k.
 

Example 1:

Input: nums = [1,2,3,4,5], k = 2
Output: 7
Explanation: 
The 7 pairs of indices whose corresponding products are divisible by 2 are
(0, 1), (0, 3), (1, 2), (1, 3), (1, 4), (2, 3), and (3, 4).
Their products are 2, 4, 6, 8, 10, 12, and 20 respectively.
Other pairs such as (0, 2) and (2, 4) have products 3 and 15 respectively, which are not divisible by 2.    
Example 2:

Input: nums = [1,2,3,4], k = 5
Output: 0
Explanation: There does not exist any pair of indices whose corresponding product is divisible by 5.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i], k <= 105 */
typedef long long LL;
int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}
class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        map<int, vector<int>> table;
        int n = nums.size();
        LL ret = 0;
        for (int i = n-1; i >= 1; i--) {
            int tmp = gcd(nums[i], k);
            tmp = k / tmp;
            if (tmp == 1) {
                ret += i;
                continue;
            }
            if (table.find(tmp) == table.end()) {
                vector<int> vs(i);
                for (int j = 0; j < i; j++) {
                    if (nums[j] % tmp == 0) vs[j] = 1;
                    if (j-1 >= 0) vs[j] += vs[j-1];
                }
                table[tmp] = move(vs);
            }
            ret += table[tmp][i-1];
        }
        return ret;
        
        
    }
};