/* Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters. */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> scc (26,0);
        vector<int> pcc (26,0);
        vector<int> answer ;
        if(p.length()>s.length()){
            return answer;
        }
        for(int i =0; i<p.length();i++){
            scc[s[i]-'a']++;
            pcc[p[i]-'a']++;
        }
        if(scc==pcc){
            answer.push_back(0);
        }
        for(int i = p.length();i<s.length() ; i++){
            scc[s[i]-'a']++;
            scc[s[i-p.length()]-'a']--;
            if(scc==pcc){
                answer.push_back(i-p.length()+1);
            }
            
        }
        return answer;
    }
};