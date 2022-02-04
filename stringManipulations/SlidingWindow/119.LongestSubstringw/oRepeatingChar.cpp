/* Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces. */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int maxLen =0, start =-1;
        for(int i =0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                if(m[s[i]]>start){
                    start = m[s[i]];
                }
            }
            m[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
        
        /*
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    */
        /*
        unordered_map<char,int> m;
        int longestSubString = 0;
        int start = -1;
        for(int i =0; i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                start = max(m[s[i]],start);
                longestSubString = max(longestSubString,i-start);
                
            }else{
                longestSubString = max(longestSubString,i-start);
            }
            //cout << i << " " << longestSubString <<endl;
            m[s[i]]=i;
        }
        return longestSubString;*/
   /*     unordered_map<char,int> m;
        int longestSubString = 0;
        int currentSubString =0;
        int start = 0;
        for(int i = 0; i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                if(longestSubString<currentSubString){
                    longestSubString = currentSubString;
                }
                i=m[s[i]];
                m.clear();
                currentSubString=0;
                
            } else{
                m[s[i]]=i;
                currentSubString++;
                
            }
            
        }
        
        
        return max(longestSubString,currentSubString);*/
    }
};

/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max=0;
        int count=0;
        int nonRepeating=0; //= s[0] xor s[1];
        unordered_map <char,int> m;
        int ptr =0;
        for(int i = 0; i <s.length();  i++){
            if(m.find(s[i])==m.end()){
                //cout << "NOT FOUND " << endl;
                m[s[i]]++;
                count++;
                
            } else{
                
                count =0;
                
                i=ptr;
                ptr++;
                m.clear();
            }
            if(max<count){
                    max = count;
                }
        }
        
            
            
        return max;
    }
};*/