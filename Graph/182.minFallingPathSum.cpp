/* Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100 */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //memoization
        //dp[row][col] = min(matrix[row][col]+dp[row-1,col+1],...)
        vector<int>dp(matrix[0].size(),0);
        vector<int>dp2(matrix[0].size(),0);
        //initialize with matrix[0][i]
        //O(col)
        for(int i = 0;i<matrix[0].size();i++){
            dp[i]=matrix[0][i];
        }
        //update dp
        //O(row*col)
        for(int i =1;i<matrix.size();i++){
            for(int j = 0;j<matrix[i].size();j++){
                //edge cases if can go diagonally
                //center
                int minSum = dp[j];
                //left
                if(j>0){
                    if(minSum>dp[j-1])
                    minSum = dp[j-1];
                }
                
                //right
                if(j<matrix[i].size()-1){
                    if(minSum>dp[j+1]){
                        minSum=dp[j+1];
                    }
                }
                dp2[j]= minSum+matrix[i][j];
            }
            dp=dp2;
        }
        int minSum = dp[0];
        //O(col)
        for(int i = 1; i<dp.size();i++){
            if(minSum>dp[i]){
                minSum = dp[i];
            }
        }
        return minSum;
    }
};