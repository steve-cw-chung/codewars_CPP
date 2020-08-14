/* Create a regular expression capable of evaluating binary strings (which consist of only 1's and 0's) and determining whether the given string represents a number divisible by 7.

Note:

Empty strings should be rejected.
Your solution should reject strings with any character other than 0 and 1.
No leading 0's will be tested unless the string exactly denotes 0.
*/
#include <regex>
// Write a regular expression to detect whether a binary number is divisible by 7
std::regex solution = std::regex("^(0|(10((0|11)(1|00))*(10|(0|11)01)|11)(01*0(0|101|1(1|00)((0|11)(1|00))*(10|(0|11)01)))*1)+$");

/* Solution 1
^(((((((0+)?1)1)((10*1)1)*(((10*1)0)0)|((((0+)?1)0)0))((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*(((10*1)0)1)|((00|1)1))|((((0+)?1)1)((10*1)1)*(((10*1)0)1)|((((0+)?1)0)1)))((0((10*1)1)*(((10*1)0)0)|1)((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*(((10*1)0)1)|((00|1)1))|(0((10*1)1)*(((10*1)0)1)))*((0((10*1)1)*(((10*1)0)0)|1)((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*0)|(0((10*1)1)*0))|(((((0+)?1)1)((10*1)1)*(((10*1)0)0)|((((0+)?1)0)0))((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*0)|((((0+)?1)1)((10*1)1)*0)))(0((0((10*1)1)*(((10*1)0)0)|1)((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*(((10*1)0)1)|((00|1)1))|(0((10*1)1)*(((10*1)0)1)))*((0((10*1)1)*(((10*1)0)0)|1)((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*0)|(0((10*1)1)*0))|1)*(0((0((10*1)1)*(((10*1)0)0)|1)((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*(((10*1)0)1)|((00|1)1))|(0((10*1)1)*(((10*1)0)1)))*((0((10*1)1)*(((10*1)0)0)|1)((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*(1(0+)?))|(0((10*1)1)*(1(0+)?))))|((((((0+)?1)1)((10*1)1)*(((10*1)0)0)|((((0+)?1)0)0))((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*(((10*1)0)1)|((00|1)1))|((((0+)?1)1)((10*1)1)*(((10*1)0)1)|((((0+)?1)0)1)))((0((10*1)1)*(((10*1)0)0)|1)((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*(((10*1)0)1)|((00|1)1))|(0((10*1)1)*(((10*1)0)1)))*((0((10*1)1)*(((10*1)0)0)|1)((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*(1(0+)?))|(0((10*1)1)*(1(0+)?)))|(((((0+)?1)1)((10*1)1)*(((10*1)0)0)|((((0+)?1)0)0))((01)((10*1)1)*(((10*1)0)0)|((00|1)0))*((01)((10*1)1)*(1(0+)?))|((((0+)?1)1)((10*1)1)*(1(0+)?)|(0(0+)?)))))$
*/

/* Solution 2 
#include <regex>
#include <string>

std::string P_3_6_5 = "01*0";
std::string P_5_3_6_5 = "(0" + P_3_6_5 + ")*";
std::string P_3_6_5_3_6_5 = P_3_6_5 + P_5_3_6_5;
std::string P_5_1 = "1(1(01)*1" + P_5_3_6_5 + "1|10)*0";

std::string P_2_5_4 = "(000|01)*(11|0)(10)*";
std::string P_2_5_4_2 = "(" + P_2_5_4 + "(1|00))*";
std::string P_1_2_5_4_1 = "(0" + P_2_5_4_2 + P_2_5_4 + "0)*";
std::string P_1_3 = P_1_2_5_4_1 + "(0" + P_2_5_4_2 + "10|1)";


std::regex solution = std::regex("^(1" + P_1_3 + "(" + P_3_6_5_3_6_5 + "(0|(11(01)*1)*0|" + P_5_1 + P_1_3 + "))*1|0)+$");

*/

/* Solution 3 
#include <regex>
std::regex solution = std::regex("^(0|1((1(01*00)*01*01|(0|1(01*00)*01*011)((0|1(1|0(01*00)*01*01))1)*(0|1(1|0(01*00)*01*01)))0)*(1|(0|1(01*00)*01*011)((0|1(1|0(01*00)*01*01))1)*10)(01*00)*1|(0|1((1(01*00)*01*01|(0|1(01*00)*01*011)((0|1(1|0(01*00)*01*01))1)*(0|1(1|0(01*00)*01*01)))0)*(1|(0|1(01*00)*01*011)((0|1(1|0(01*00)*01*01))1)*10)(01*00)*1)(0|1((1(01*00)*01*01|(0|1(01*00)*01*011)((0|1(1|0(01*00)*01*01))1)*(0|1(1|0(01*00)*01*01)))0)*(1|(0|1(01*00)*01*011)((0|1(1|0(01*00)*01*01))1)*10)(01*00)*1)*(0|1((1(01*00)*01*01|(0|1(01*00)*01*011)((0|1(1|0(01*00)*01*01))1)*(0|1(1|0(01*00)*01*01)))0)*(1|(0|1(01*00)*01*011)((0|1(1|0(01*00)*01*01))1)*10)(01*00)*1))$");

/*
 *  generated DFA by hand
 *  converted DFA into regex using an online tool[1]
 *  verified regex using regex101[2]
 *  
 *  could also convert manually, using the state elimination method
 *  this regex is too big for most simplifiers, but works fine as is
 *  
 *  [1] - http://ivanzuzak.info/noam/webapps/fsm2regex/
 *  [2] - https://regex101.com/
 */

*/