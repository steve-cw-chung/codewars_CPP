/* Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters. */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //make hash for ransomNote char->int (count)
        // or make vector with size 26
        //decrease the count value for each letter in magazine
        // check if every count is 0 or less
        /*unordered_map <char,int>m;
        for(int i =0; i<ransomNote.length();i++){
            m[ransomNote[i]]++;
        }
        for(int i =0; i<magazine.length();i++){
            m[magazine[i]]--;
        }
        for(auto x : m){
            if(x.second>0){
                return false;
            }
        }
        return true;
        */
        unordered_map<char,int>m;
        for(int i =0; i<magazine.length();i++){
            m[magazine[i]]++;
        }
        for(int i =0; i<ransomNote.length();i++){
            if(--m[ransomNote[i]]<0){
                return false;
            }
        }
        return true;
    }
};