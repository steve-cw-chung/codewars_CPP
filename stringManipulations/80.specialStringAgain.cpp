/* A string is said to be a special string if either of two conditions is met:

All of the characters are the same, e.g. aaa.
All characters except the middle one are the same, e.g. aadaa.
A special substring is any substring of a string which meets one of those criteria. Given a string, determine how many special substrings can be formed from it.

Example

 contains the following  special substrings: .

Function Description

Complete the substrCount function in the editor below.

substrCount has the following parameter(s):

int n: the length of string s
string s: a string
Returns
- int: the number of special substrings

Input Format

The first line contains an integer, , the length of .
The second line contains the string .

Constraints


Each character of the string is a lowercase English letter, .

Sample Input 0

5
asasd
Sample Output 0

7 
Explanation 0

The special palindromic substrings of  are 

Sample Input 1

7
abcbaba
Sample Output 1

10 
Explanation 1

The special palindromic substrings of  are 

Sample Input 2

4
aaaa
Sample Output 2

10
Explanation 2

The special palindromic substrings of  are  */
#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long count = 0;
    for(int i = 0 ; i < n ;i++){
        int length =1;
        int skip =0;
        count++;        
        for(int j = i+1; j<n ; j++){
            
            if(s[i]==s[j]&&skip==0){
                count++;
                length++;
            } else if(s[i]!=s[j]&&skip==0){
                skip++;
            }else if (s[i]==s[j]&&skip==1){
                length--;
                if(length==0){
                    count++;
                    break;
                }
            }else if (s[i]!=s[j]&&skip==1){
                break;
            }
            if(skip>2){
                break;
            }
        }
        
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
