/* Alright, detective, one of our colleagues successfully observed our target person, Robby the robber. We followed him to a secret warehouse, where we assume to find all the stolen stuff. The door to this warehouse is secured by an electronic combination lock. Unfortunately our spy isn't sure about the PIN he saw, when Robby entered it.

The keypad has the following layout:

┌───┬───┬───┐
│ 1 │ 2 │ 3 │
├───┼───┼───┤
│ 4 │ 5 │ 6 │
├───┼───┼───┤
│ 7 │ 8 │ 9 │
└───┼───┼───┘
    │ 0 │
    └───┘
He noted the PIN 1357, but he also said, it is possible that each of the digits he saw could actually be another adjacent digit (horizontally or vertically, but not diagonally). E.g. instead of the 1 it could also be the 2 or 4. And instead of the 5 it could also be the 2, 4, 6 or 8.

He also mentioned, he knows this kind of locks. You can enter an unlimited amount of wrong PINs, they never finally lock the system or sound the alarm. That's why we can try out all possible (*) variations.

* possible in sense of: the observed PIN itself and all variations considering the adjacent digits

Can you help us to find all those variations? It would be nice to have a function, that returns an array (or a list in Java and C#) of all variations for an observed PIN with a length of 1 to 8 digits. We could name the function getPINs (get_pins in python, GetPINs in C#). But please note that all PINs, the observed one and also the results, must be strings, because of potentially leading '0's. We already prepared some test cases for you.

Detective, we count on you!

For C# user: Do not use Mono. Mono is too slower when run your code. */

/* Solution 1 */
#include <string>
#include <vector>
#include <functional>

std::vector<std::string> get_pins(std::string observed) {
  std::vector<std::string> symbol{"08", 
                                  "124",  "1235",  "236", 
                                  "1457", "24568", "3569",
                                  "478",  "05789", "689"   };
  
  std::vector<std::string> result;
  
  std::function<void (int, std::string)> get_pin = [&] (auto j, auto prefix) {
    if (j == observed.size()) return result.push_back(prefix);
    for (auto c : symbol.at(observed[j] - '0')) get_pin(j + 1, prefix + c);
  };
  
  get_pin(0, "");
  
  return std::move(result);
}

/* Solution 2 */

using namespace std;

vector<string> get_pins(const string &observed, const string &prefix = "")
{
    static const map<char, string> neighbors =
    {
        {'1', "124"},  {'2', "1235"},  {'3', "236"},
        {'4', "1457"}, {'5', "24568"}, {'6', "3569"},
        {'7', "478"},  {'8', "05789"}, {'9', "689"},
                       {'0', "08"}
    };
    if ( !observed.size() ) return {prefix};
    vector<string> pins;
    for (auto c : neighbors.at(observed[0]))
        for (auto pin : get_pins(observed.substr(1), prefix + c))
            pins.push_back(pin);
    return pins;
}

/* Solution 3 */
#include <string>
#include <vector>
#include <array>
#include <numeric>

const static std::array<std::string, 10> possibilities = {
  "08", "124", "1235", "236", "1457", "24568", "3569", "478", "57890", "689"
};

std::vector<std::string> generate_next_sequence(const std::vector<std::string>& strings, char c) {
  const int value = c - '0';
  std::vector<std::string> results;
  results.reserve(std::size(strings) * std::size(possibilities[value]));
  
  for (const auto& str : strings) {
    for (char c : possibilities[value]) {
      results.push_back(str + c);
    }
  }
  
  return results;
}


std::vector<std::string> get_pins(std::string observed) {
  return std::accumulate(std::begin(observed), std::end(observed), std::vector<std::string>{{""}}, generate_next_sequence);