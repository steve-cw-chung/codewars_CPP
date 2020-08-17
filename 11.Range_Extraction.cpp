#include <string>
#include <vector>
#include <iostream>
#include <limits.h>

std::string range_extraction(std::vector<int> args) {
  int prev = INT_MIN;
  int seg_start = INT_MIN;
  std::string retVal = "";
  int count = 0;
  for (int arg : args){
    if(prev==INT_MIN){
      prev = arg;
      seg_start = arg;
      count++;
    } else {
      if(arg==prev+1){
        prev=arg;
        count++;
        if(arg==args[args.size()-1]){
          if(count>=3){
          retVal += std::to_string(seg_start) + "-"+std::to_string(arg)+",";
          }else{
            if(seg_start!=INT_MIN){
              retVal+=std::to_string(seg_start)+",";
            }
            retVal+=std::to_string(arg)+",";
          }
        }
      }else{
        
        if (count>=3){
          if(arg==args[args.size()-1]){
          
            retVal += std::to_string(seg_start) + "-"+std::to_string(prev)+","+ std::to_string(arg)+",";
          }else{
            retVal += std::to_string(seg_start) + "-"+std::to_string(prev)+",";
            prev=arg;
            seg_start=arg;
            count=1;
            }
        }else{
          if(arg==args[args.size()-1]){
            if(seg_start!=prev){
              retVal+=std::to_string(seg_start)+","+std::to_string(prev)+","+std::to_string(arg)+",";
            }else{
            retVal+=std::to_string(prev)+","+std::to_string(arg)+",";
          
            }
          }else{
            if(seg_start!=INT_MIN){
              retVal+=std::to_string(seg_start)+",";
              if(seg_start!=prev){
                retVal+=std::to_string(prev)+",";
              }
            }
          }
          count=1;
          seg_start=arg;
          prev=arg;
        }
        
      }
    }
    
  }
  
  
  return retVal.substr(0,retVal.size()-1);
}

int main(){
  std::vector<int> args = {1,2,3,4,5,6,8,9,10,12,31};
  std::cout << range_extraction(args);
}

/* Solution 1 

#include <string>
#include <set>

std::string range_extraction(std::vector<int> args)
{
    using Range = std::pair<int, int>;
    std::vector<Range> ranges;
    for(auto &i : args)
        if(ranges.empty() || ranges.back().second + 1 != i)
            ranges.push_back({i, i});
        else
            ++ranges.back().second;

    std::string result;
    for(auto &r : ranges)
        if(r.first == r.second)
            result.append(std::to_string(r.first) + ",");
        else
            result.append(std::to_string(r.first) +
                          ((r.first + 1 == r.second) ? ',' : '-') +
                          std::to_string(r.second) +
                          ",");
    result.pop_back();
    return result;
}
*/

/* Solution 2 

#include <string>
#include <vector>
using namespace std;
std::string range_extraction(std::vector<int> v) {
  stringstream ss("");
  int c=0;
  for(int i=0;i<v.size();i++){
    if(v[i+2]==v[i]+2){
    ss<<v[i];
    int j=i+3;
    while(v[j]-v[j-1]==1){j++;}
    i=j-1;
    ss<<"-"<<v[i]<<",";
  }
  else ss<<v[i]<<",";
  }
  return (ss.str()).substr(0,ss.str().length()-1);
}
*/

/*Solution 3

#include <string>
#include <vector>
#include <sstream>
using namespace std;

string range_extraction(vector<int> args) {
  int a = args[0], b = args[0];
  stringstream ss;
  for(auto p = begin(args)+1; p <= end(args); ++p){
    if(p == end(args) || p[0] > p[-1]+1){
      ss << a;
      if(a != p[-1])
        ss << ((p[-1]-a<=1)? ',' : '-') << p[-1];
      ss << ',';      
      a = p[0];
    }
  }
  string s = ss.str();
  s.pop_back();
  return s;
}
*/