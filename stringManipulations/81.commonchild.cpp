/* A string is said to be a child of a another string if it can be formed by deleting 0 or more characters from the other string. Letters cannot be rearranged. Given two strings of equal length, what's the longest string that can be constructed such that it is a child of both?

Example



These strings have two children with maximum length 3, ABC and ABD. They can be formed by eliminating either the D or C from both strings. Return .

Function Description

Complete the commonChild function in the editor below.

commonChild has the following parameter(s):

string s1: a string
string s2: another string
Returns

int: the length of the longest string which is a common child of the input strings
Input Format

There are two lines, each with a string,  and .

Constraints

 where  means "the length of "
All characters are upper case in the range ascii[A-Z].
Sample Input

HARRY
SALLY
Sample Output

 2
Explanation

The longest string that can be formed by deleting zero or more characters from  and  is , whose length is 2.

Sample Input 1

AA
BB
Sample Output 1

0
Explanation 1

 and  have no characters in common and hence the output is 0.

Sample Input 2

SHINCHAN
NOHARAAA
Sample Output 2

3
Explanation 2

The longest string that can be formed between  and  while maintaining the order is .

Sample Input 3

ABCDEF
FBDAMN
Sample Output 3

2
Explanation 3
 is the longest child of the given strings. */

 #include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int commonChild(string s1, string s2) {
    //for loop twice
/*     int retVal =0;
    int pointer =0;
    int count =0;
    for(int i =0; i<s1.length();i++){
        for(int j = pointer; j<s2.length();j++){
            if(s1[i]==s2[j]){
                pointer=j+1;
                cout << "i : " << i << " j: " << j << " s1[i] : "<< s1[i] << " s2[j] : "<<s2[j] <<endl;
                count++;
                break;
            }
        }
    }
    pointer = 0;
    int count2 =0;
    for(int i =0; i<s2.length();i++){
        for(int j = pointer; j<s1.length();j++){
            if(s1[j]==s2[i]){
                pointer=j+1;
                count2++;
                cout << "i : " << i << " j: " << j << " s1[j] : "<< s1[j] << " s2[i] : " <<s2[i] <<endl;
                break;
            }
        }
    }
    retVal = max(count,count2);
    return retVal; */
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> C;
    //unordered_map<pair<int,int>,int> C;
    //int C = new int[m + 1, n + 1];
    vector<int>temp (m+1,0);
    for(int i=0;i<=n;i++){
        C.push_back(temp);
    }
    /* for (int i = 0; i < m; i++)
        C[i][0] = 0;
    for (int j = 0; j < n; j++)
        C[0][j] = 0; */
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                C[i][j] = C[i - 1][ j - 1] + 1;
            else
                C[i] [j] = max(C[i] [j - 1], C[i - 1] [j]);
        }
    return C[m] [n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
