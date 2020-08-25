/* Vasya has found a strange device. On the front panel of a device there are: a red button, a blue button and a display showing some positive integer. After clicking the red button, device multiplies the displayed number by two. After clicking the blue button, device subtracts one from the number on the display. If at some point the number stops being positive, the device breaks down. The display can show arbitrarily large numbers. Initially, the display shows number n.

Bob wants to get number m on the display. What minimum number of clicks he has to make in order to achieve this result?

Input
The first and the only line of the input contains two distinct integers n and m (1 ≤ n, m ≤ 104), separated by a space .

Output
Print a single number — the minimum number of times one needs to push the button required to get the number m out of number n.

Examples
inputCopy
4 6
outputCopy
2
inputCopy
10 1
outputCopy
9
Note
In the first example you need to push the blue button once, and then push the red button once.

In the second example, doubling the number is unnecessary, so we need to push the blue button nine times. */
/*
#include <iostream>

int twoButtons(int n, int m){
    int retVal=0; 
  
    if(n> m ){
        while(n>m){
            n--;
            retVal++;
        }
        return retVal;
    }else if ( m > n ){
        while(m!=n){
            if(n*2>m && m%2!=0 && n*2<m*2){
                if(abs((n-1)*2-m) <abs(n*2-m )){
                    n--;
                    retVal++;
                } else {
                    n*=2;
                    retVal++;
                }
            }else if (abs((n-1)*2-m) <abs(n*2-m)){
                n--;
                retVal++;
            }else if (abs((n-1)*2-m) >=abs(n*2-m)){
                n*=2;
                retVal++;
            }
             else if ( n *2 == m) {
                n*= 2;
                retVal++;
            
            }else if ((n-1)*2>=m/2 && m%2==0){
                if((n-1)*2>=m/2){
                    n--;
                    retVal++;
                } else {
                    n*=2;
                    retVal++;
                }
                
            }else if(n*2>m){
                n--;
                retVal++;
            }else {
                n*=2;
                retVal++;
            }
            std::cout << "n: " << n <<std::endl;
            //std::cout << "retVal: " << retVal << std::endl;
        }
    }
    return retVal;
}

int main (){
    int n, m;
    std::cin>> n  >> m ;
    std::cout << twoButtons(n,m);
    return 0;
}
*/

#include <iostream>
using namespace std;

int main()
{
    int n, m, w(0);
    cin >> n >> m;
    while (n != m)
    {
        if (m > n)
            if (m % 2 == 0) m /= 2, w++;
            else m++, w++;
        else if (n > m) m++, w++;
    }
    cout << w << endl;
    return 0;
}
