/* Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space. */

class Solution {
public:
    string reverseWords(string s) {
        /*string temp = s.substr(0,s.find(" "));
        string answer;
        while(s.find(" ")!=string::npos){
            string temp = s.substr(0,s.find(" "));
            reverse(temp.begin(),temp.end());
            answer+=temp+" ";
            s.erase(0,s.find(" ")+1);
            
            //answer+=" ";
            
        }
        reverse(s.begin(),s.end());
        answer+=s;
        return answer;*/
        int start = 0;
        for(int i =0; i<=s.length();i++){
            if(i==s.length()||s[i]==' '){
                reverse(&s[start],&s[i]);
                start = i+1;
            }
        }
        return s;
    }
};