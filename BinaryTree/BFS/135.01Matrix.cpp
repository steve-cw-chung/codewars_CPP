/* Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat. */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({ i, j }); //Put all 0s in the queue.
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                    if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                        dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }
        return dist;
    }
};

/*class Solution {
public:
    void DFS(vector<vector<int>>& mat, vector<vector<int>> visited,int m, int n){
        int minDist = 0;
        queue<pair<int,int>> q2;
        q2.push({m,n});
        while(!q2.empty()){
            queue<pair<int,int>>q;
            minDist++;
            while(!q2.empty()){
                
                q.push(q2.front());
                q2.pop();
            }
        
            while(!q.empty()){
                
                int x = q.front().first;
                int y = q.front().second;
                visited[x][y]=1;
                q.pop();
                //north
                if(x>0&&mat[x-1][y]==0){
                    mat[m][n]=minDist;
                    return;
                }else if(x>0&&visited[x-1][y]==0){
                    q2.push({x-1,y});
                }
                //south
                if(x<mat.size()-1&&mat[x+1][y]==0){
                    mat[m][n]=minDist;
                    return;
                }else if(x<mat.size()-1&&visited[x+1][y]==0){
                    q2.push({x+1,y});
                }
                //east
                if(y<mat[0].size()-1&&mat[x][y+1]==0){

                    mat[m][n]=minDist;
                    return;
                }else if(y<mat[0].size()-1&&visited[x][y+1]==0){
                    q2.push({x,y+1});
                }
                //west
                if(y>0&&mat[x][y-1]==0){

                    mat[m][n]=minDist;
                    return;
                }else if(y>0&&visited[x][y-1]==0){
                    q2.push({x,y-1});
                }
            }
        }
        
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> visited;
        for(int i =0; i<mat.size();i++){
            vector<int> temp (mat[i].size(),0);
            visited.push_back(temp);
        }
        for(int i =0; i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    DFS(mat,visited,i,j);
                }
            }
        }
        return mat;
    }
};*/