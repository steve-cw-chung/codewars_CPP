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

int main(){
    long long int m,s;
    std::cin >> m >> s;
    long long int num =0;
    long long int min=0;
    long long int max=0;
    long long int i=0;
    long long int sum = s;
    if(s==0){
        std::cout << "-1 -1";
    }else if (s==1){
        std::cout << pow(10,m-1)<< " " << pow(10,m-1);
    }else if (m*9>=s){
        s--;
        min = pow(10,m-1);
        while(s!=0){
            if(s>=9){
                min += 9*pow(10,i);
                i++;
                s-=9;
            } else {
                min += s*pow(10,i);
                i++;
                s =0;
            }
        }
        i = m-1;

        while(sum!=0){
            if(sum>=9){
                //std::cout << "max :" <<max<<std::endl;
                max += (9*pow(10,i));
                if ( max == 899){
                    max =900;
                }
                //std::cout << "9*pow(10,i) :" <<(int)9*pow(10,i)<<std::endl;
                //std::cout << "max :" <<max<<std::endl;
                i--;
                sum-=9;
            } else {
                //std::cout << "max :" <<max<<std::endl;
                max += sum*pow(10,i);
                //std::cout << "max :" <<max<<std::endl;
                sum =0;
                i--;
            }
        }

        std::cout<< min <<" " << max;
    }

    
    return 0;

}