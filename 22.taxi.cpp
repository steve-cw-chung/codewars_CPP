/* After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his birthday. We know that the i-th group consists of s i friends (1 ≤ s i ≤ 4), and they want to go to Polycarpus together. They decided to get there by taxi. Each car can carry at most four passengers. What minimum number of cars will the children need if all members of each group should ride in the same taxi (but one taxi can take more than one group)?

Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of groups of schoolchildren. The second line contains a sequence of integers s 1, s 2, ..., s n (1 ≤ s i ≤ 4). The integers are separated by a space, s i is the number of children in the i-th group.

Output
Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.

Examples
inputCopy
5
1 2 4 3 3
outputCopy
4
inputCopy
8
2 3 4 4 2 1 3 1
outputCopy
5
Note
In the first test we can sort the children into four cars like this:

the third group (consisting of four children),
the fourth group (consisting of three children),
the fifth group (consisting of three children),
the first and the second group (consisting of one and two children, correspondingly).
There are other ways to sort the groups into four cars. */

#include <iostream>
#include <algorithm>

int main(){
    int x,one=0,two=0,three=0,four=0,s=0;
    std::cin>>x;
    
    for(int i=0; i<x; i++){
        std::cin>> s;
        switch(s){
            case 1: one++;
                    break;
            case 2: two++;
                    break;
            case 3: three++;
                    break;
            case 4: four++;
                    break;
        }
    }

    one -= std::min(one,three);

    if( two % 2 == 0){
        two /=2;  
    }else{
        two/=2;
        two++;
   
        if(one==1){
            one--;
        }else if (one>=2){
            one -= 2;
        }

    }
    if(one%4==0){
        one/=4;
    }else{
        one/=4;
        one++;
    }
    std::cout<< one+two+three+four;

    return 0;
}