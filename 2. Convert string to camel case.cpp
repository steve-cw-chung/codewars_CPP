/* Complete the method/function so that it converts dash/underscore delimited words into camel casing. The first word within the output should be capitalized only if the original word was capitalized (known as Upper Camel Case, also often referred to as Pascal case).

Examples
to_camel_case("the-stealth-warrior") // returns "theStealthWarrior"

to_camel_case("The_Stealth_Warrior") // returns "TheStealthWarrior" */

// My Solution

#include <string>


std::string to_camel_case(std::string text) {
  // TODO: Your code goes here!
   for (int i = 0 ; i < (int)size(text);){
     if(text[i]=='-' || text[i]=='_'){
        if(islower(text[i+1])){
          // subtracting ascii value by 32 to change the lowercase to uppercase. 
          text[i+1] = (char)(((int)text[i+1]) -32);
          //text[i+1]= toupper(text[i+1]);
        }
      text.erase(i,1);
      } else {
        i++;
      }
    }
  return text;
}

// Solution 1 
#include <string>


std::string to_camel_case(std::string text)
{
  for(int i = 0; i < text.size(); ++i)
  {
    if(text[i] == '-' || text[i] == '_')
    {
      text.erase(i,1);
      text[i] = toupper(text[i]);
    }
  }
  return text;
}

// Solution 2

#include <string>

std::string to_camel_case(const std::string & text)
{
    std::string result;
    result.reserve(text.length());

    bool capital = false;

    for (auto c : text)
    {    
        // any non-alphanumeric character causes the next one to be upper-case
        if (!std::isalpha(c))
        {
            capital = true;
        }
        
        // this character should be upper case if the "capital" flag is set or if
        // it's already an upper-case character
        else if (capital || std::isupper(c))
        {
            result.push_back(std::toupper(c));
            capital = false; // unset the "capital" flag after emitting the character
        }
        
        // anything else is emitted as lower case
        else
        {
            result.push_back(std::tolower(c));
        }
    }
    
    return result;
}