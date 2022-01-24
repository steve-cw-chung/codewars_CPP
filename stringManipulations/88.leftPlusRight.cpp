/* Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

 

Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3
Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
Example 3:

Input: s = "1111"
Output: 3
 

Constraints:

2 <= s.length <= 500
The string s consists of characters '0' and '1' only. */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        
        //2 ptrs
        // 1 and 2~string-1
        // 1~2 and 3~s -2
        // ...
        // 1~s-1 and last
        //int totalScore=0;
        /*for(int i=1; i< s.length();i++){
            string left = s.substr(0,i);
            string right = s.substr(i);
            int score = 0;
            while(left.find("0")!=string::npos){
                score++;
                left.erase(0,left.find("0")+1);
            }
            while(right.find("1")!=string::npos){
                score++;
                right.erase(0,right.find("1")+1);
            }
            if(totalScore<score){
                totalScore = score;
            }
        }
       */
    int count_0=0,count_1=0,maximum=0;
        for(int i=0;i<s.length();i++)
        {
        if(s[i]=='1')
        count_1++;
        }
        for(int i=0;i<s.length()-1;i++)
        {
        if(s[i]=='0')
        {
        count_0++;
        }
        else
        {
        count_1--;
        }
        maximum=max(maximum,count_0+count_1);
        }
        return maximum;

    }
    
};