#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string compressedString(string message) {
    string retVal = "";
    int consecutive = 0; 
 // for loop through the string
// starting from 0
// if consec == 0 then consec+1 then i++
// if consec > 0 then compare with previous character
// if same then consec++ and i++ else add previous character + consec to the retVal and set consec = 0
// on last character if same then consec++ add character + consec else add previous character + consec and add character
    for(int i = 0 ; i < message.length(); i++){
        if(i<message.length()-1){
            if(consecutive==0){
                consecutive++;
            } else if (consecutive > 0 ){
                if(message[i]==message[i-1]){
                    consecutive++;
                } else {
                    retVal+=message[i-1];
                    if(consecutive>1){
                        retVal+=to_string(consecutive);
                    }
                    consecutive = 1;
                }
            }
        } else {
            if(message[i]==message[i-1]){
                retVal += message[i];
                retVal += to_string(++consecutive);
            } else {
                retVal+= message[i-1];
                if(consecutive>1){
                    retVal+=to_string(consecutive);
                }
                retVal += message[i];
            }
        }
    }
    return retVal;
}

int main(){
    
    cout<<compressedString("abbbabccvccc");
    return 0;
}