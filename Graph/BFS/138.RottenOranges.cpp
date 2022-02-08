/* You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2. */
class Solution {
public:
    int BFS(vector<vector<int>>& grid, vector<vector<int>>visited,int r,int c ){
        int distRotten = 0;
        vector <int> dist = {1,0,-1,0,1};
        queue<pair<int,int>>q;
        
        visited[r][c]=1;
        queue<pair<int,int>>q2;
        q2.emplace(r,c);
        while(!q2.empty()){
            distRotten++;
            while(!q2.empty()){
                q.push(q2.front());
                q2.pop();
            }
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i =0; i<4;i++){
                    int nr = dist[i] +x;
                    int nc = dist[i+1]+y;
                    if(nr<0 || nc<0 || nr>grid.size()-1 || nc>grid[0].size()-1 || grid[nr][nc]==0 ){
                        continue;
                    }else{ 
                        if(grid[nr][nc]==1&&visited[nr][nc]==0){
                            q2.emplace(nr,nc);
                            visited[nr][nc]=1;
                        }else if(grid[nr][nc]==2){
                            return distRotten;
                        }
                    }
                }
            }
        }
        return -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>visited;
        int distRotten = 0;
        for(int i =0;i<grid.size();i++){
            vector<int>temp(grid[i].size(),0);
            visited.push_back(temp);
        }
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[i].size();j++){
                if(grid[i][j]==0){
                    visited[i][j]=1;
                }else if (grid[i][j]==1){
                    int currentDist = BFS(grid,visited,i,j);
                    if(currentDist == -1){
                        return -1;
                    }
                    distRotten = max(distRotten,currentDist);
                }
            }
        }
        return distRotten;
    }
};