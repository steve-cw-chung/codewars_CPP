/* Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9] */

/* Solution 1 */

#include <cstddef>
#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>>& xs) {
  std::vector<int> res;
  if (xs[0].empty())
    return res;
  const std::size_t ny = xs.size(), nx = xs[0].size();
  res.reserve(ny * nx);
  std::ptrdiff_t x0 = 0, y0 = 0, x1 = nx - 1, y1 = ny - 1, x = 0, y = 0;
  while (y0 <= y1) {
    while (x < x1) res.push_back(xs[y][x++]); y0++;
    while (y < y1) res.push_back(xs[y++][x]); x1--;
    while (x > x0) res.push_back(xs[y][x--]); y1--;
    while (y > y0) res.push_back(xs[y--][x]); x0++;
  }
  res.push_back(xs[y][x]);
  return res;
}

/* Solution 2 */

#include <vector>
using namespace std;
inline vector<int> snail(vector<vector<int>> array) {
  int leftlimit=0, uplimit=0, rightlimit=array[0].size()-1, downlimit=rightlimit, cx=-1, cy=-1;
  vector <int> ans;
  while (leftlimit<=rightlimit){
    for (cy++, uplimit++,    cx++; cx <= rightlimit; cx++) ans.push_back(array[cy][cx]); 
    for (cx--, rightlimit--, cy++; cy <= downlimit ; cy++) ans.push_back(array[cy][cx]);
    for (cy--, downlimit--,  cx--; cx >= leftlimit ; cx--) ans.push_back(array[cy][cx]);
    for (cx++, leftlimit++,  cy--; cy >= uplimit   ; cy--) ans.push_back(array[cy][cx]);
  } 
  return ans;
}

/* Solution 3 */

#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>>& arr)
{
  std::vector<int> v;
  if(arr[0].empty()) return v;
  int i=0,k=0,x=arr.size(),y=0;
  while(x>0)
  {
    for(; k <x; ++k) v.push_back(arr[i][k]); ++i; --k;
    for(; i <x; ++i) v.push_back(arr[i][k]); --i; --k;
    for(; k>=y; --k) v.push_back(arr[i][k]); --i; ++k; ++y;
    for(; i>=y; --i) v.push_back(arr[i][k]); ++i; ++k; --x;
  }
  return v;
}