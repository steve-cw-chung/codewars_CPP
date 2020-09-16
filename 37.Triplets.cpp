#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


// Complete the triplets function below.
long triplets(long t, vector<int> d) {

long combinations = 0; // return value
long total = 0; // to keep track of current total to skip the obvious failing combinations to improve time 
// 1. find the maximum combination which is n choose 3
// 2. subtract the combinations that does that pass the threshold
// OR-------
// brute force solution with break
// 1. for(i for (j for (k))) 
// O(n*m*l)

//sort 
sort(d.begin(),d.end()); 

for(int i = 0; i < d.size()-2; i++){
    total += d[i];
    if(total > t){
        total -= d[i];
        break;
    }
    for(int j = i+1; j < d.size()-1; j++){
        total+=d[j];
        if(total > t){
            total -= d[j];
            break;
        }
        for(int k = j+1; k < d.size(); k++){
            total += d[k];
            if(total<=t){
                combinations++;
                total -=d[k];
            } else {
                total -= d[k];
                break;
            }
        }
        total-=d[j];
    }
    total-=d[i];
}

return combinations;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    long t = stol(ltrim(rtrim(t_temp)));

    string d_count_temp;
    getline(cin, d_count_temp);

    int d_count = stoi(ltrim(rtrim(d_count_temp)));

    vector<int> d(d_count);

    for (int i = 0; i < d_count; i++) {
        string d_item_temp;
        getline(cin, d_item_temp);

        int d_item = stoi(ltrim(rtrim(d_item_temp)));

        d[i] = d_item;
    }

    long res = triplets(t, d);
    cout <<"Output: "<< res << endl; 

    fout << res << "\n";

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