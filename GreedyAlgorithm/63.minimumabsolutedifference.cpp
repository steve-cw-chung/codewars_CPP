/* The absolute difference is the positive difference between two values  and , is written  or  and they are equal. If  and , . Given an array of integers, find the minimum absolute difference between any two elements in the array.

Example. 

There are  pairs of numbers:  and . The absolute differences for these pairs are ,  and . The minimum absolute difference is .

Function Description

Complete the minimumAbsoluteDifference function in the editor below. It should return an integer that represents the minimum absolute difference between any pair of elements.

minimumAbsoluteDifference has the following parameter(s):

int arr[n]: an array of integers
Returns

int: the minimum absolute difference found
Input Format

The first line contains a single integer , the size of .
The second line contains  space-separated integers, .

Constraints

Sample Input 0

3
3 -7 0
Sample Output 0

3
Explanation 0

The first line of input is the number of array elements. The array,  There are three pairs to test: , , and . The absolute differences are:

Remember that the order of values in the subtraction does not influence the result. The smallest of these absolute differences is .

Sample Input 1

10
-59 -36 -13 1 -53 -92 -2 -96 -54 75
Sample Output 1

1
Explanation 1

The smallest absolute difference is .

Sample Input 2

5
1 -3 71 68 17
Sample Output 2

3
Explanation 2

The minimum absolute difference is . */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumAbsoluteDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 void merge (vector<int>& arr, int const l, int const mid, int const r){
     int leftPointer = 0;
     int rightPointer = 0;
     //copy the elements into left and right vectors
     vector<int> left,right;
     for(int i = l; i<=mid; i++){
         left.push_back(arr[i]);
     }
     for(int i= mid+1; i<=r;i++){
         right.push_back(arr[i]);
     }
     int endOfLeft= mid-l;
     int endOfRight= r-mid-1;
     int pointer = l; 
     while(leftPointer<=endOfLeft && rightPointer <= endOfRight){
         if(left[leftPointer]<=right[rightPointer]){
             arr[pointer++]= left[leftPointer++];
         }else{
             arr[pointer++]= right[rightPointer++];
         }
     }
     while(leftPointer<=endOfLeft){
         arr[pointer++]= left[leftPointer++];
     }
     while(rightPointer<=endOfRight){
         arr[pointer++]= right[rightPointer++];
     }
/*      cout << "left : " ;
     for(auto x : left ){
         cout << x << " " ;
     }
     cout << endl << "right : ";
     for(auto x : right ){
         cout << x << " " ;
     }
     cout << endl; */
 }
 
void mergesort(vector<int>& arr, int const l, int const r ){
    if(l >= r ) return;
    int mid = l + (r-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
    
}

int minimumAbsoluteDifference(vector<int> arr) {
    int minimum = INT_MAX;
/*     for(int i=0; i <arr.size()-1;i++){
        for(int j=1+i; j < arr.size();j++){
            if(abs(arr[i]-arr[j])<minimum){
                minimum = abs(arr[i]-arr[j]);
            }
            
            //cout <<"i : " <<i<< " j: "<< j <<  "abs : " << abs(arr[i]-arr[j])<< " minimum : " << minimum << endl;
        }
        
    } */
    //mergesort
    int l= 0;
    
    int r = arr.size()-1;
    mergesort(arr,l,r);
    
    //sort(arr.begin(),arr.end());
    for(int i = 0 ; i < arr.size(); i++){
        if(abs(arr[i+1]-arr[i])<minimum){
            minimum=abs(arr[i+1]-arr[i]);
        }
    }
    
    
    return minimum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = minimumAbsoluteDifference(arr);

    fout << result << "\n";

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
