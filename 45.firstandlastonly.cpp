//Check whether the number has only first and last bits set
//Given a positive integer n, check whether only the first and last bits are set in the binary representation of n. Print ‘Yes’ or ‘No’.
/* Examples: 
 

Input: 9 
Output: Yes 
(9)10 = (1001)2, only the first and 
last bits are set.
Input: 15 
Output: No 
(15)10 = (1111)2, except first and last 
there are other bits also which are set.  */

#include <iostream>

using namespace std;

int nextBit(int x){
    return x%2;
}
// iterative solution Time Complexity : O(n) Space Complexity : O(n) 
/* int main(){
    int a;
    cin >> a ;
    bool answer=true;
    int current;
    if (a==0){
        answer = false;
    } else if (a==1){
        answer = true;
    
    } else {
        if (a%2==0){
            answer = false;
        } else {
            current=(a/2);
            while(current>2){
                if(nextBit(current)==1){
                    answer=false;
                }
                current=(current/2);
            }
                   
        }
    }

    cout << answer <<endl;


    return 0;
} */

// Better Solution
int main (){
    int a;
    cin >> a;
    if (a == 1){
        cout << "true" << endl;
    } else if (a == 2) {
        cout << "false" << endl;
    } else {
        if ( ((a-1)&(a-2))==0){
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}