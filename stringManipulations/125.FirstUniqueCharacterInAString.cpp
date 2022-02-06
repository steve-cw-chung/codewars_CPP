/* Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters. */

class Solution {
public:
    int firstUniqChar(string s) {
        //loop through s
        // char -> vector<index>
        // char -> index
        // lowest index
        unordered_map<char,vector<int>> m;
        int lowestIndex = INT_MAX;
        for(int i =0; i<s.length();i++){
            m[s[i]].push_back(i);
        }
        /*for(int i=0; i< s.length();i++){
            if(m[s[i]].size()==1){
                return i;
            }
        }
        return -1;*/
        for(auto x : m){
            if(x.second.size()==1){
                if(lowestIndex>x.second[0]){
                    lowestIndex = x.second[0];
                }
            }
        }
        
        if(lowestIndex==INT_MAX){
            return -1;
        }
        return lowestIndex;
        
    }
};