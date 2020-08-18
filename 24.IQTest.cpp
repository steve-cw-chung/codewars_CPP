/* Bob is preparing to pass IQ test. The most frequent task in this test is to find out which one of the given n numbers differs from the others. Bob observed that one number usually differs from the others in evenness. Help Bob — to check his answers, he needs a program that among the given n numbers finds one that is different in evenness.

Input
The first line contains integer n (3 ≤ n ≤ 100) — amount of numbers in the task. The second line contains n space-separated natural numbers, not exceeding 100. It is guaranteed, that exactly one of these numbers differs from the others in evenness.

Output
Output index of number that differs from the others in evenness. Numbers are numbered from 1 in the input order.

Examples
inputCopy
5
2 4 7 8 10
outputCopy
3
inputCopy
4
1 2 1 1
outputCopy
2
 */

#include <iostream>

int main(){
    int x,a;
    int evenCount = 0;
    int oddCount = 0;
    int retVal = 0;
    int lastEvenIndex=0;
    int lastOddIndex=0;
    std::cin >> x;
    for(int i =0 ; i< x; i++){
        std::cin>>a;
        
        if(a%2==0){
            evenCount++;
            lastEvenIndex=i+1;
            
        } else{
            oddCount++;
            lastOddIndex=i+1;
        }
  
        if(evenCount>1&& oddCount==1){
            retVal = lastOddIndex;
            break;
        }
        if(oddCount>1&&evenCount==1){
            retVal = lastEvenIndex;
            break;
        }
    }
    std::cout << retVal;
    return 0;
}