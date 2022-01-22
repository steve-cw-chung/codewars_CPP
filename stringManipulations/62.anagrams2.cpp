/* A student is taking a cryptography class and has found anagrams to be very useful. Two strings are anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency. For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

The student decides on an encryption scheme that involves two large strings. The encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Determine this number.

Given two strings,  and , that may or may not be of the same length, determine the minimum number of character deletions required to make  and  anagrams. Any characters can be deleted from either of the strings.

Example


Delete  from  and  from  so that the remaining strings are  and  which are anagrams. This takes  character deletions.

Function Description

Complete the makeAnagram function in the editor below.

makeAnagram has the following parameter(s):

string a: a string
string b: another string
Returns

int: the minimum total characters that must be deleted
Input Format

The first line contains a single string, .
The second line contains a single string, .

Constraints

The strings  and  consist of lowercase English alphabetic letters, ascii[a-z].
Sample Input

cde
abc
Sample Output

4
Explanation

Delete the following characters from the strings make them anagrams:

Remove d and e from cde to get c.
Remove a and b from abc to get c.
It takes  deletions to make both strings anagrams. */
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */
 
int makeAnagram(string a, string b) {
    unordered_map <char,int> m1,m2;
    int counter = 0;
    for(int i =0; i <a.length(); i++){
        if(m1[a[i]]==0){
            m1[a[i]]=1;
        } else {
            m1[a[i]]++;
        }
    }
    for(int i =0; i < b.length();i++){
        if(m2[b[i]]==0){
            m2[b[i]]=1;
            
        } else {
            m2[b[i]]++;
        }
    }

    for(auto x: m1){
        
        //same
        //bigger (m1 has more characters)
        //less than 0 (m2 has more characters)
        if(x.second - m2[x.first]==0){
            m2.erase(x.first);
        } else if(x.second-m2[x.first] > 0){
            counter= counter + (x.second-m2[x.first]);
            m2.erase(x.first);
        } else {
            counter = counter + (m2[x.first]-x.second);
            m2.erase(x.first);
        }
    }
    //check leftovers in m2 
    for(auto x: m2){
        counter = counter + x.second;
    }
    return counter;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
