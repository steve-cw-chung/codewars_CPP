#include <iostream>
#include <string>
int main(){
    int n;
    std::string word;
    std::cin >> n;
    std::string newWord = "";

    for (int i=0 ; i < n ; i ++){
        std::cin >> word;
        if(word.length()>10){
            newWord += word[0];
            newWord += std::to_string(word.length()-2);
            newWord += word[word.length()-1];
            word = newWord;
            newWord = "";
        }
        std::cout << word<<std::endl;

    }
    return 0;
}