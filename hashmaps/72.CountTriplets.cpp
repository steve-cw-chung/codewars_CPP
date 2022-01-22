/* You are given an array and you need to find number of tripets of indices  such that the elements at those indices are in geometric progression for a given common ratio  and .

Example
 

There are  and  at indices  and . Return .

Function Description

Complete the countTriplets function in the editor below.

countTriplets has the following parameter(s):

int arr[n]: an array of integers
int r: the common ratio
Returns

int: the number of triplets
Input Format

The first line contains two space-separated integers  and , the size of  and the common ratio.
The next line contains  space-seperated integers .

Constraints

Sample Input 0

4 2
1 2 2 4
Sample Output 0

2
Explanation 0

There are  triplets in satisfying our criteria, whose indices are  and 

Sample Input 1

6 3
1 3 9 9 27 81
Sample Output 1

6
Explanation 1

The triplets satisfying are index , , , ,  and .

Sample Input 2

5 5
1 5 5 25 125
Sample Output 2

4
Explanation 2

The triplets satisfying are index , , , .

 */

/* long countTriplets(vector<long> arr, long r) {
    unordered_map <long,int> m,n;
    // Case : n =1 and 2
    if(arr.size()<3) return 0;
    
    // Case : r = 1
    if (r ==1 ){
        return factorial(arr.size())/(factorial(arr.size()-3)*factorial(3));
    }
    long c=0;
    for(int i = 0; i<arr.size();i++){
        if(m[arr[i]]==0){
            m[arr[i]] = 1;
        } else {
            m[arr[i]]++;
        }
    }
    n=m;

    long currentNumber,secondNumber, thirdNumber;
    for(auto x : m){
        //cout << "size of m " << m.size() << endl;
        //cout << "ITERATE : " << x.first << " " << x.second << endl;
        currentNumber = x.first;
        if(currentNumber%r!=0||currentNumber/r<1) continue;
        secondNumber = currentNumber/r;
        if(currentNumber/r%r!=0||currentNumber/r/r<1) continue;
        thirdNumber = currentNumber/r/r;
        
        c = c + (x.second * n[secondNumber] * n[thirdNumber]);
        //cout << "F : " << currentNumber << " S : " << secondNumber << " T : " << thirdNumber << " c : " << c << endl;
    }
    
    return c;

} */
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
long factorial (long i){
    if(i==1 || i==0) return 1;
    return i * factorial(i-1);
}
// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    unordered_map<long,int> before,after;
    for(int i = 0; i<arr.size();i++){
        if(after[arr[i]]==0){
            after[arr[i]]=1;
        }else {
            after[arr[i]]++;
        }
    }
    long current = 0;
    long c = 0;
    for(int i = 0; i<arr.size();i++){
        current =arr[i];
        after[current]--;
        // check current/r in before current%r==0 current*r in after
        if(before[current/r]>0 && current%r==0 && after[current*r]>0){
            c+= (long)before[current/r] * (long)after[current*r];
        }
        if(before[current]==0){
            before[current]=1;
        } else {
            before[current]++;
        }
        
    }
    return c;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
