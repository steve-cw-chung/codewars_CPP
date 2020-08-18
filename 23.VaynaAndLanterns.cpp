/* Vanya walks late at night along a straight street of length l, lit by n lanterns. Consider the coordinate system with the beginning of the street corresponding to the point 0, and its end corresponding to the point l. Then the i-th lantern is at the point a i. The lantern lights all points of the street that are at the distance of at most d from it, where d is some positive number, common for all lanterns.

Vanya wonders: what is the minimum light radius d should the lanterns have to light the whole street?

Input
The first line contains two integers n, l (1 ≤ n ≤ 1000, 1 ≤ l ≤ 109) — the number of lanterns and the length of the street respectively.

The next line contains n integers a i (0 ≤ a i ≤ l). Multiple lanterns can be located at the same point. The lanterns may be located at the ends of the street.

Output
Print the minimum light radius d, needed to light the whole street. The answer will be considered correct if its absolute or relative error doesn't exceed 10 - 9.

Examples
inputCopy
7 15
15 5 3 7 9 14 0
outputCopy
2.5000000000
inputCopy
2 5
2 5
outputCopy
2.0000000000
Note
Consider the second sample. At d = 2 the first lantern will light the segment [0, 4] of the street, and the second lantern will light segment [3, 5]. Thus, the whole street will be lit. */

#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    int n,l,x,prev=0;
    long double d = 0;
    std::cin >> n;
    std::cin >> l;
    std::vector<int> v;
    for(int i=0; i< n ;i++){
        std::cin >> x;
        v.push_back(x);
    }
    std::sort(v.begin(),v.end());
    for (auto i :v){
        if(v[0]==i){
            if(v.size()==1){
                if(i > l-i){
                    d=i;
                } else {
                    d=l-i;
                }
            
                break;
            }
            d = i;
            prev = i;
        } else if( v[v.size()-1]==i){
            if(d< l-i){
                d= l-i;
            }
            if(((long double)l-prev)/2>d){
                d=((long double)l-prev)/2;
            }
        } else {
            if(((long double)i-prev)/2>d){
                d = ((long double)i-prev)/2;
            }
            prev = i;
        }
    }

    std::cout<<std::fixed<< d;
        
    return 0;
}