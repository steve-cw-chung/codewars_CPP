/* Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n */
/*class Solution {
vector<vector<int>> comb;
public:
    void helper(int index, vector<int>&current,int n,int k){
        if(current.size()==k){
            comb.push_back(current);
            return;
        }
        for(int i = index; i<=n; i++){
            current.push_back(i);
            helper(i+1,current,n,k);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        helper(1,current,n,k);
        return comb;
    }
};*/
/*class Solution {
public:   
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp(k, 0);
        int itr = 0;
        while(itr > -1){
            temp[itr]++;
            if(temp[itr] > n) itr--;
            else if(itr == k-1) res.push_back(temp);
            else{                
                itr++;
                temp[itr] = temp[itr-1];
            }
        }
        return res;
    }
};*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> comb;
        vector<int>temp(k,0);
        int itr = 0;
        while(itr>-1){
            temp[itr]++;
            if(temp[itr]>n)itr--;
            else if (itr==k-1) comb.push_back(temp);
            else{
                itr++;
                temp[itr]=temp[itr-1];
            }
        }
        return comb;
    }
};