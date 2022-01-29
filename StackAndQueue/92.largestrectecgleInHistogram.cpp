/* Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> index;
        int largestRectangle = 0;
        //heights.push_back(0);
        for(int i = 0; i <heights.size();i++){
            
            while(!index.empty()&&heights[index.top()]>heights[i]){
                int curIndex = index.top();
                
                index.pop();
                
                int width = index.empty()?i-1+1: i-index.top()-1;
                largestRectangle = max(largestRectangle,heights[curIndex]*width);
            }
            index.push(i);
        }
        while(!index.empty()&&heights[index.top()]>0){
            int curIndex = index.top();
            index.pop();
            int width = index.empty()?heights.size()-1+1:heights.size()-index.top()-1;
            largestRectangle = max(largestRectangle,heights[curIndex]*width);
        }
        return largestRectangle;
    }
};