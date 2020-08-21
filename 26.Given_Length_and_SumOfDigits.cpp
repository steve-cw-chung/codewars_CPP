/* You have a positive integer m and a non-negative integer s. Your task is to find the smallest and the largest of the numbers that have length m and sum of digits s. The required numbers should be non-negative integers written in the decimal base without leading zeroes.

Input
The single line of the input contains a pair of integers m, s (1 ≤ m ≤ 100, 0 ≤ s ≤ 900) — the length and the sum of the digits of the required numbers.

Output
In the output print the pair of the required non-negative integer numbers — first the minimum possible number, then — the maximum possible number. If no numbers satisfying conditions required exist, print the pair of numbers "-1 -1" (without the quotes).

Examples
inputCopy
2 15
outputCopy
69 96
inputCopy
3 0
outputCopy
-1 -1 */

#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <sstream>

int main(){
    int m,s;
    std::cin >> m >> s;
    int m2 = m;
    int num =0;
    std::string min= "";
    std::string max= "";
    int i=0;
    int sum = s;
    std::ostringstream oss;
    if ( s > m*9){
        std::cout << "-1 -1";
    }
    else if(s==0 && m==1){
        std::cout<< "0 0";
    }
    else if(s==0 && m!=1){
        std::cout << "-1 -1";
    }else if (s==1){
        min = "1";
        m--;
        for(int i = 0 ; i < m; i++){
            min +='0';
        }
        max = min;
        std::cout << min<< " " << max;

    }else if (m*9>=s){
        s--;
        m--;
        min += '1';
        for(int i = 0; i < m; i++){
            min+='0';
        }
        
        while(s!=0){
            if(s>=9){
                std::replace(min.end()-1-i,min.end()-i,'0','9');
          
                i++;
                s-=9;
            } else {
                char c = '0' + s;
                if(min[min.length()-1-i]=='0'){
                    std::replace(min.end()-1-i,min.end()-i,'0',c);
                }else {
                    std::replace(min.end()-1-i,min.end()-i,'1',++c);
                }
                i++;
                s =0;
            }
        }
        i = m2-1;
        
        while(sum!=0){
            if(max==""){
            for(int i =0; i<m2; i++){
                max+="0";
            }
            }
            if(sum>=9){
       
                std::replace(max.end()-1-i,max.end()-i,'0','9');
                
                i--;
                sum-=9;
            } else {
                char c = '0' + sum;
                std::replace(max.begin(),max.end()-i,'0',c);
                sum =0;
                i--;
            }
        }

        std::cout<< min +" "+ max;
    }

    
    return 0;

}