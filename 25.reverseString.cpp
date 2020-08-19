/*
An arbitrary string like "This is fine" is given 
Constraint: This is a coding/algorithm exercise: you are only allowed to operate on scalar types
(i.e: don't use helper functions like '[].reverse()')
 (1)  Write a method that reverses the character in the string 
      In the example the string with reversed characters would be "enif si sihT" 
 (2)  Write a method that reverses the words in the string
       In the example the string with reversed words would be "fine is This"
 */
#include <iostream>
#include <string>
#include <cstring>
#include <list>



char * reverseString1(char* s){
    //1
    
    char temp;

    for(int i =0; i < strlen(s)/2 ;i++){
        
        temp = s[i];
        s[i] = s[strlen(s)-i-1];
        s[strlen(s)-i-1]=temp;
    }
    
    //2 
    
    
    return s;
}

std::string reverseString2(std::string s){
    
    std::list<std::string> words;
    std::string temp = "";
    std::string retVal ="";
  
    for(int i =0; i < s.length(); i++){
        if(s[i]!=' '){
            temp+=s[i];
            if(i==s.length()-1)
                words.push_front(temp);
        }else {
            words.push_front(temp);
            temp="";
        }
    }
    int size = words.size();
    
    for(int i = 0; i < size; i++){
        retVal += words.front() + " ";
        words.pop_front();
        
    }
    return retVal;
}



int main(){
    char a [] = "This is fine";
    std::cout << reverseString1(a)<<std::endl;
    std::string b = "This is fine";
    std::cout << reverseString2(b);

    return 0;
}