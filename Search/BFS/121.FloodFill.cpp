/* An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], newColor < 216
0 <= sr < m
0 <= sc < n */
class Solution {
public:
    void colorNeighbors(vector<vector<int>>& image, int r , int c, int newColor, int target){
        //4 directions
        //mark as visisted first?or after visit other nodes? mark first is better to avoid unnecessary steps
        image[r][c]=newColor;
        //North
        if(r>0&&image[r-1][c]==target){
            colorNeighbors(image,r-1,c,newColor,target);
        }
        //South
        if(r<image.size()-1&&image[r+1][c]==target){
            colorNeighbors(image,r+1,c,newColor,target);
        }
        //West
        if(c>0&&image[r][c-1]==target){
            colorNeighbors(image,r,c-1,newColor,target);
        }
        //East
        if(c<image[r].size()-1&&image[r][c+1]==target){
            colorNeighbors(image,r,c+1,newColor,target);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //BFS vs DFS 
        int target = image[sr][sc];
        if(target ==newColor){
            return image;
        }
        colorNeighbors(image,sr,sc,newColor,target);
        return image;
    }
};