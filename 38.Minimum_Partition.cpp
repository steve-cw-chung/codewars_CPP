//#include <bits/stdc++.h>
 #include <vector>
 #include <iostream>
 #include <algorithm>

 
int minDiff(std::vector<int>& arr); 
 
int main(){ 
 
  std::vector<int> v{6, 1, 11, 5, 2}; 
  std::cout<<"#Case 1: "<<minDiff(v); 
  std::cout<<std::endl; 
  std::vector<int> v1{6, 1, 11, 10, 12}; 
  std::cout<<"#Case 2: "<< minDiff(v1); 
 
  return 0; 
} 
 
int minDiff(std::vector<int>& arr){ 
 
 std::vector<std::vector<int>> st;   
  st.push_back({0}); 
 
  for(int i=0; i<arr.size(); ++i){ 
    std::vector<int> step; 
    for(int j=0; j<st[i].size(); ++j){ 
      step.push_back(st[i][j] + arr[i]); 
      step.push_back(st[i][j] - arr[i]); 
    } 
    st.push_back(step); 
  } 
 
  int min = std::abs(st[st.size()-1][0]); 
  for(int i : st[st.size()-1]) 
    min = std::min(std::abs(i), min); 
 
  return min; 
} 