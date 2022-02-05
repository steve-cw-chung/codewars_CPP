/* You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1. */
class Solution {
public:
    int getArea(vector<vector<int>>& grid,vector<vector<bool>>& visited,int r, int c){
        int area=0;
        queue<pair<int,int>> q;
        q.push({r,c});
        visited[r][c]= true;
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
       
            area++;
            
            //visit 4-directional
            //north
            if(curr.first>0 &&!visited[curr.first-1][curr.second] &&grid[curr.first-1][curr.second]){
                q.push({curr.first-1,curr.second});
                visited[curr.first-1][curr.second] = true;
            }
            //south
            if(curr.first<grid.size()-1&&grid[curr.first+1][curr.second]&&!visited[curr.first+1][curr.second]){
                q.push({curr.first+1,curr.second});
                visited[curr.first+1][curr.second] = true;
            }
            //east
            if(curr.second<grid[0].size()-1&&grid[curr.first][curr.second+1]&&!visited[curr.first][curr.second+1]){
                q.push({curr.first,curr.second+1});
                visited[curr.first][curr.second+1] = true;
            }
            //west
            if(curr.second>0 && grid[curr.first][curr.second-1]&&!visited[curr.first][curr.second-1]){
                q.push({curr.first,curr.second-1});
                visited[curr.first][curr.second-1] = true;
            }
            
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //DFS or BFS
        vector<vector<bool>> visited;
        for(int i =0 ; i <grid.size();i++){
            vector<bool> temp (grid[i].size(),false);
            visited.push_back(temp);
        }
        int maxArea =0;
        for(int i =0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(!visited[i][j]){
                    visited[i][j] = true;
                    if(grid[i][j]){
                        maxArea = max(maxArea,getArea(grid,visited,i,j));
                    }
                }
            }
        }
        
        return maxArea;
        
    }
};