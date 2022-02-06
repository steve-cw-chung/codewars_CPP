/* Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //look for higher first integer of row than target
        //if you can't find it, check last row
        // if you find it , check a row before
        // binary search
        
        int low = 0;
        int high = matrix.size()-1;
        while(low<high){
            int mid = low +(high-low)/2;
            if(matrix[mid][0]<target){
                low = mid+1;
            }else if (matrix[mid][0]>target){
                high = mid-1;
            }else{
                return true;
            }
        }
        int targetRow=low;
        if(target<matrix[low][0]){
            if(low==0){
                return false;
            }
            targetRow = low-1;
        }
        
        
        low = 0;
        high = matrix[0].size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[targetRow][mid]>target){
                high = mid-1;
            }else if (matrix[targetRow][mid]<target){
                low = mid+1;
            }else{
                return true;
            }
        }
        
        
        return false;
    }
};
/*Use binary search.

n * m matrix convert to an array => matrix[x][y] => a[x * m + y]

an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
*/
/*class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};*/