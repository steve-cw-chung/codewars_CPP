/* Consider a matrix where each cell contains either a  or a  and any cell containing a  is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. In the diagram below, the two colored regions show cells connected to the filled cells. Black on white are not connected.

Cells adjacent to filled cells: image

If one or more filled cells are also connected, they form a region. Note that each cell in a region is connected to at least one other cell in the region but is not necessarily directly connected to all the other cells in the region.

Regions: image

Given an  matrix, find and print the number of cells in the largest region in the matrix.

Function Description

Complete the function maxRegion in the editor below. It must return an integer value, the size of the largest region.

maxRegion has the following parameter(s):

grid: a two dimensional array of integers
Input Format

The first line contains an integer, , the number of rows in the matrix, .
The second line contains an integer, , the number of columns in the matrix.

Each of the following  lines contains a row of  space-separated integers, .

Constraints

Output Format

Print the number of cells in the largest region in the given matrix.

Sample Input

4
4
1 1 0 0
0 1 1 0
0 0 1 0
1 0 0 0
Sample Output

5
Explanation

The diagram below depicts two regions of the matrix:

image
The first region has five cells and the second region has one cell. We choose the larger region. */
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void DFS(vector<vector<int>>grid,vector<vector<bool>> &visited,unordered_map<int, int> &sizes, int x, int y,int color){
    visited[y][x]= true;
    //cout << "x : " << x << " y: " << y << " color : " << color << " sizes[color] : " << sizes[color] <<endl;
    sizes[color]++;
    cout << "x : " << x << " y: " << y << " color : " << color << " sizes[color] : " << sizes[color] <<endl;
    //Northwest [-1,-1]
    
    if(y-1>=0&&x-1>=0&&!visited[y-1][x-1]&&grid[y-1][x-1]==1){
        DFS(grid,visited,sizes,x-1,y-1,color);
    }    
    //North [-1, 0]
    if(y-1>=0&&!visited[y-1][x]&&grid[y-1][x]==1){
        DFS(grid,visited,sizes,x,y-1,color);
    }  
    //NorthEast[-1,1]
    if(y-1>=0&&x+1<grid[y-1].size()&&!visited[y-1][x+1]&&grid[y-1][x+1]==1){
        DFS(grid,visited,sizes,x+1,y-1,color);
    }  
    //East[0,1]
    if(x+1<grid[0].size()&&!visited[y][x+1]&&grid[y][x+1]==1){
        DFS(grid,visited,sizes,x+1,y,color);
    }  
    //Southeast [1,1]
    if(y+1<grid.size()&&x+1<grid[0].size()&&!visited[y+1][x+1]&&grid[y+1][x+1]==1){
        DFS(grid,visited,sizes,x+1,y+1,color);
    }  
    //South[1,0]
    if(y+1<grid.size()&&!visited[y+1][x]&&grid[y+1][x]==1){
        DFS(grid,visited,sizes,x,y+1,color);
    }  
    //Southwest[1,-1]
    if(x-1>=0&&y+1<grid.size()&&!visited[y+1][x-1]&&grid[y+1][x-1]==1){
        DFS(grid,visited,sizes,x-1,y+1,color);
    } 
    //West[0,-1]
    if(x-1>=0&&!visited[y][x-1]&&grid[y][x-1]==1){
        DFS(grid,visited,sizes,x-1,y,color);
    } 

    
}

int maxRegion(vector<vector<int>> grid) {
    vector<vector<bool>> visited;
    //unordered_map<vector<int>,bool>visisted2;
    unordered_map<int, int> sizes;
    int color =0;
    vector<bool>temp (grid[0].size(),false);
    for(int i =0; i<grid.size();i++){
        visited.push_back(temp);
    }
    cout << "grid.size() : " << grid.size() << endl;
    cout << "grid[0].size() : " << grid[0].size() << endl;
    for(int i =0; i<grid.size(); i++){
        for(int j = 0; j<grid[i].size(); j++){
            if(grid[i][j]==1 &&!visited[i][j]){
                DFS(grid,visited,sizes,j,i,color);
                color++;    
            }
        }
    }
    int max = 1;
    for(auto x : sizes){
        if(max<x.second){
            max = x.second;
        }
    }
    return max;
}
int main (){
    //cout <<"Hello"<<endl;
    vector<vector<int>> grid= {
    {1, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {1, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 1, 0, 0}
    };
    int answer = maxRegion(grid);
    cout << "max : " << answer;




    return 0;
}