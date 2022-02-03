/* The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 

Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1. */

class Solution {
public:
    int tribonacci(int n) {
        /*vector<int> v={0,1,1};
        if(n==0){
            return 0;
        }else if (n==1){
            return 1;
        } else if (n==2){
            return 1;
        } else{
            for(int i=3;i<=n;i++){
                v.push_back(v[i-3]+v[i-2]+v[i-1]);
            }
        }
        return v.back();
        */
        vector<int> v={0,1,1};
        int counter =0;
        if(n==0){
            return 0;
        }else if (n==1){
            return 1;
        } else if (n==2){
            return 1;
        } else{
           
            for(int i=3;i<=n;i++){
                v[counter++]= v[0]+v[1]+v[2];
                if(counter==3){
                    counter =0;
                }
            }
        }
        counter--;
        if (counter==-1){
            counter =2;
        }
        return v[counter];
        /*if(n==0){
            return 0;
        }else if (n==1){
            return 1;
        } else if (n==2){
            return 1;
        } else{
            return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        }*/
    }
};