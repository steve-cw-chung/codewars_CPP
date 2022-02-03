// effienct algorithm to calculate max-min diff of continuous parcels.
// 1,2,3,4,5,6,7
// singles 1 -> imbalance : 1-1 = 0
// doubles 1,2 -> imbalance : 2-1 = 1
// triples 1,2,3 -> imbalance : 3-1 = 2
// quadriples 1,2,3,4, -> imbalance : 4-1 = 3

/*
Random parcels
5 2 4 3 4 10 88 43 75 23
singles 5 -> imbalance : 5-5 =0
doubles 5 2 -> imbalance : 5-2 = 3
triples 5 2 4 -> imbalance : 5-2 = 3
quadriples 5 2 4 3 -> imbalance : 5-2 = 3 

*/

/*

pair<int,int> (startIndex,endIndex) => pair<int,int>(min, max)
unordered_map<pair<int,int>,pair<int,int> > m;

need to pointers

*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
//#include <algorithm>

using namespace std;
// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

long imbalance(vector<int> parcels){
    unordered_map <pair<int,int>,pair<int,int>,hash_pair > m;
    // m : key : {start,end} =>  value : {min,max}
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > maxpq;
    priority_queue<pair<int,int> > minpq;
    //testing

   int min = INT_MAX;
   int max = INT_MIN;
    for(int i =0; i<parcels.size();i++){
        int current = parcels[i];
        //m[make_pair(i,i)] = make_pair(current,current);
        if(current > max){
            max= current;
        }
        if(current<min){
            min = current;
        }

        m[make_pair(0,i)]=make_pair(min,max);
        
    }
    min = 0;
    max=0;
    for(int i =0; i<parcels.size();i++){
        int current = parcels[i];
        for(int j =i+1; j<parcels.size();j++){
            
            if(m[make_pair(i,j)].first>current){
                min = current;
            }else{
                min = m[make_pair(i,j)].first;
            }
            if(m[make_pair(i,j)].second<current){
                max = current;
            }else{
                max = m[make_pair(i,j)].second;
            }
            m[make_pair(i+1,j)]=make_pair(min,max);
            cout <<"i: "<< i+1 <<" j: "<< j << " min :" << m[make_pair(i,j)].first<< " max : " << m[make_pair(i,j)].second<<endl;
        }
    }
    return 0;
}


int main(){
    vector <string> v1 = {"helllo"};
    vector<int> arr = {1,2,3,4,5,6,7,8};
    vector<int> v(10);
    
    cout << imbalance(arr);

    sort(arr.begin(),arr.end(),greater<int>());

    imbalance(arr);


    return 0;


}
